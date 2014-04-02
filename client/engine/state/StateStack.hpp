#ifndef STATESTACK_HPP
#define STATESTACK_HPP

#include <vector>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "AbstractStateFactory.hpp"




/**
  Manage states of the application.
*/
class StateStack : private sf::NonCopyable
{
	public:
		enum Action {
			Push,
			Pop,
			Clear
		};
		
		explicit StateStack(AbstractStateFactory & factory, Context context);
		
		/** Update all the states
		  @param dt Time elapsed since the latest call
		*/
		void update(sf::Time dt);
		/** Notify states from the top
		  @param event Event to treat
		*/
		void handleEvent(const sf::Event & event);
		/** Draw all the states from the bottom
		  */
		void draw();
		
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
		Context mContext;
		
		AbstractStateFactory & mFactory;
};






#endif // STATESTACK_HPP
