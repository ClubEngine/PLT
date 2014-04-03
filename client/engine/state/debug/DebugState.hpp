#ifndef DEBUGSTATE_HPP
#define DEBUGSTATE_HPP

#include "../State.hpp"
#include "DebugController.hpp"

class DebugState : public AbstractState
{
	public:
		DebugState(ModelHelper &modelHelper, 
				   ViewHelper &viewHelper,
				   ControllerHelper &controllerHelper);
	
	private:
		class DebugView : public AbstractStateView {
			public:
				DebugView(ViewHelper & h);
				virtual bool processInputs(const sf::Event &event);
				virtual bool update(sf::Time dt);
				virtual void render();
				void setController(DebugController & controller);
			private:
				DebugController * mController;
				
		} mView;
		
		DebugController mController;		
};

#endif // DEBUGSTATE_HPP
