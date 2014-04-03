#ifndef STATE_HPP
#define STATE_HPP


#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "States.hpp"

#include "engine/Context.hpp"
#include "engine/TextureHolder.hpp"
#include <SFML/Graphics.hpp>

#include "Engine.hpp"

class StateStackManager;

/** Represent a state of the application life.
  */
class State
{
	public:
				
		State(StateStackManager & stack, Context context);
		
		/**
		  Return false to stop states updating
		*/
		
		bool processController();
		bool updateModel(sf::Time dt);
		bool processView(const sf::Event & event);
		bool updateView(sf::Time dt);
		void render();
		
		virtual ~State();
		
	protected:
		void requestStackPush(States::ID stateID);
		void requestStackPop();
		void requestStateClear();

		Context getContext() const;
		
		void registerController(AbstractStateController & controller);
		void registerView(AbstractStateView & view);
		void registerModel(AbstractStateModel & model);
		
		
	private:
		
		StateStackManager & mStack;
		Context mContext;
		
		AbstractStateController * mController;
		AbstractStateModel * mModel;
		AbstractStateView * mView;
};

#endif // STATE_HPP
