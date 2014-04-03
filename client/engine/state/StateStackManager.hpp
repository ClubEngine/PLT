#ifndef STATESTACKMANAGER_HPP
#define STATESTACKMANAGER_HPP

#include <vector>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "AbstractStateFactory.hpp"




/**
  Manage states of the application.
*/
class StateStackManager : private sf::NonCopyable
{
	public:
		enum Action {
			Push,
			Pop,
			Clear
		};
		
		explicit StateStackManager(AbstractStateFactory & factory);
		
		void setHelpers(ModelHelper &modelHelper,
						ViewHelper &viewHelper,
				        ControllerHelper &controllerHelper);
		
		void processNetMsg();
		
		/** Update all the states
		  @param dt Time elapsed since the latest call
		*/
		void updateModels(sf::Time dt);
		/** Notify states from the top
		  @param event Event to treat
		*/
		void processInputs(const sf::Event & event);
		
		void updateViews(sf::Time dt);
		
		/** Draw all the states from the bottom
		  */
		void render();
		
		/** Set the top active state
		  @param id Id of the state, accordly to the id into the StateFactory
		*/
		void pushState(States::ID id);
		void popState();
		void clearStates();
		
		bool isEmpty() const;
		
	private:
		
		struct PendingChange {
				explicit PendingChange(Action action, States::ID stateID = States::None);
				Action action;
				States::ID stateID;
		};
		
		void applyPendingChanges();
		
		typedef std::vector<State*> StatePtrVector;
		typedef std::vector<PendingChange> PendingChangeVector;
		
		StatePtrVector mStack;
		PendingChangeVector mPendingList;
	
		
		AbstractStateFactory & mFactory;
		
		ModelHelper *mModelHelper;
	    ViewHelper *mViewHelper;
	    ControllerHelper *mControllerHelper;
};






#endif // STATESTACKMANAGER_HPP
