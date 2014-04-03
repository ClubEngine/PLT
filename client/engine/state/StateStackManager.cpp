#include "StateStackManager.hpp"

#include "engine/Context.hpp"



StateStackManager::StateStackManager(AbstractStateFactory & factory)
	: mStack(), mPendingList(), mFactory(factory)
{
	
}

void StateStackManager::setHelpers(ModelHelper &modelHelper, ViewHelper &viewHelper, ControllerHelper &controllerHelper)
{
	mModelHelper = & modelHelper;
	mViewHelper = & viewHelper;
	mControllerHelper = & controllerHelper;
}



void StateStackManager::processNetMsg()
{
	// Iterate from top to bottom, stop as soon as handleEvent() returns false
	for (StatePtrVector::reverse_iterator itr = mStack.rbegin();
		 itr != mStack.rend(); ++itr)
	{
			if (!(*itr)->processController())
					break;
	}

	applyPendingChanges();
}



void StateStackManager::updateModels(sf::Time dt)
{
	// Iterate from top to bottom, stop as soon as update() returns false
	for (StatePtrVector::reverse_iterator itr = mStack.rbegin(); 
		 itr != mStack.rend(); ++itr)
	{
			if (!(*itr)->updateModel(dt))
					break;
	}

	applyPendingChanges();
}



void StateStackManager::processInputs(const sf::Event& event)
{
	// Iterate from top to bottom, stop as soon as handleEvent() returns false
	for (StatePtrVector::reverse_iterator itr = mStack.rbegin();
		 itr != mStack.rend(); ++itr)
	{
			if (!(*itr)->processView(event))
					break;
	}

	applyPendingChanges();
}

void StateStackManager::updateViews(sf::Time dt)
{
	// Iterate from top to bottom, stop as soon as handleEvent() returns false
    for (StatePtrVector::reverse_iterator itr = mStack.rbegin();
		 itr != mStack.rend(); ++itr)
    {
            if (!(*itr)->updateView(dt))
                    break;
    }

	applyPendingChanges();
}

void StateStackManager::render()
{
        // Draw all active states from bottom to top
		for (StatePtrVector::const_iterator itr = mStack.begin(); 
			 itr != mStack.end(); ++itr)
			(*itr)->render();
}

void StateStackManager::pushState(States::ID id)
{
	mPendingList.push_back(PendingChange(Push, id));
}

void StateStackManager::popState()
{
	mPendingList.push_back(PendingChange(Pop));
}

void StateStackManager::clearStates()
{
	mPendingList.push_back(PendingChange(Clear));
}

bool StateStackManager::isEmpty() const
{
	return mStack.empty();
}

void StateStackManager::applyPendingChanges()
{
	for(PendingChangeVector::const_iterator it = mPendingList.begin();
		it != mPendingList.end(); ++it) {
		
		const PendingChange & change = *it;
		
		switch(change.action) {
			case Push:
				mStack.push_back(
							mFactory.get(change.stateID,
										 *mModelHelper,
										 *mViewHelper,
										 *mControllerHelper));
				break;
				
			case Pop:
				mStack.pop_back();
				break;
				
			case Clear:
				mStack.clear();
				break;
		}
	}
	
	mPendingList.clear();
}


StateStackManager::PendingChange::PendingChange(Action action, States::ID stateID)
: action(action)
, stateID(stateID)
{
}
