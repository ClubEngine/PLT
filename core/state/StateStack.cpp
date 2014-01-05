#include "StateStack.hpp"

#include "core/Context.hpp"

StateStack::StateStack(AbstractStateFactory & factory, Context & context)
	: mStack(), mPendingList(), mContext(context), mFactory(factory)
{
}

void StateStack::update(sf::Time dt)
{
        // Iterate from top to bottom, stop as soon as update() returns false
        for (StatePtrVector::reverse_iterator itr = mStack.rbegin(); 
			 itr != mStack.rend(); ++itr)
        {
                if (!(*itr)->update(dt))
                        break;
        }

        applyPendingChanges();
}

void StateStack::draw()
{
        // Draw all active states from bottom to top
		for (StatePtrVector::const_iterator itr = mStack.begin(); 
			 itr != mStack.end(); ++itr)
			(*itr)->draw();
}

void StateStack::handleEvent(const sf::Event& event)
{
        // Iterate from top to bottom, stop as soon as handleEvent() returns false
        for (StatePtrVector::reverse_iterator itr = mStack.rbegin();
			 itr != mStack.rend(); ++itr)
        {
                if (!(*itr)->handleEvent(event))
                        break;
        }

        applyPendingChanges();
}


void StateStack::pushState(States::ID id)
{
	mPendingList.push_back(PendingChange(Push, id));
}

void StateStack::popState()
{
	mPendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates()
{
	mPendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const
{
	return mStack.empty();
}

void StateStack::applyPendingChanges()
{
	for(PendingChangeVector::const_iterator it = mPendingList.begin();
		it != mPendingList.end(); ++it) {
		
		const PendingChange & change = *it;
		
		switch(change.action) {
			case Push:
				mStack.push_back(mFactory.get(change.stateID, *this, mContext));
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


StateStack::PendingChange::PendingChange(Action action, States::ID stateID)
: action(action)
, stateID(stateID)
{
}
