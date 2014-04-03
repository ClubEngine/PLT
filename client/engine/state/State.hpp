#ifndef STATE_HPP
#define STATE_HPP


#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "States.hpp"

#include "engine/Context.hpp"
#include "engine/TextureHolder.hpp"
#include <SFML/Graphics.hpp>

#include "AbstractStateModel.hpp"
#include "AbstractStateView.hpp"
#include "AbstractStateController.hpp"



class StateStackManager;

/** Represent a state of the application life.
  */
class State : sf::NonCopyable
{
	public:
				
		State();
		
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
		void registerController(AbstractStateController & controller);
		void registerView(AbstractStateView & view);
		void registerModel(AbstractStateModel & model);
		
	private:
		AbstractStateController * mController;
		AbstractStateModel * mModel;
		AbstractStateView * mView;
};

#endif // STATE_HPP
