#ifndef ABSTRACTSTATE_HPP
#define ABSTRACTSTATE_HPP


#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <SFML/Graphics.hpp>

#include "AbstractStateModel.hpp"
#include "AbstractStateView.hpp"
#include "AbstractStateController.hpp"


class StateStackManager;

/** Represent a state of the application life.
  */
class AbstractState : sf::NonCopyable
{
	public:
				
		AbstractState();
		
		/**
		  Return false to stop states updating
		*/
		
		bool processController();
		bool updateModel(sf::Time dt);
		bool processView(const sf::Event & event);
		bool updateView(sf::Time dt);
		void render();
		
		virtual ~AbstractState();
		
	protected:		
		void registerController(AbstractStateController & controller);
		void registerView(AbstractStateView & view);
		void registerModel(AbstractStateModel & model);
		
	private:
		AbstractStateController * mController;
		AbstractStateModel * mModel;
		AbstractStateView * mView;
};

#endif // ABSTRACTSTATE_HPP
