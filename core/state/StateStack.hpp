#ifndef STATESTACK_HPP
#define STATESTACK_HPP

#include <vector>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "AbstractStateFactory.hpp"


class StateStack : private sf::NonCopyable
{
	public:
		enum Action {
			Push,
			Pop,
			Clear
		};
		
		explicit StateStack(AbstractStateFactory & factory, Context context);
		
		void update(sf::Time dt);
		void handleEvent(const sf::Event & event);
		void draw();
		
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
