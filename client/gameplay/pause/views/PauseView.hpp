#ifndef PAUSEVIEW_HPP
#define PAUSEVIEW_HPP

#include "Gameplay.hpp"

class PauseModel;
class PauseController;

class PauseView : public AbstractStateView
{
	public:
		PauseView(ViewHelper & helper);
		void setModel(PauseModel & model);
		void setController(PauseController & controller);
		
		virtual bool processInputs(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void render();
		
	private:
		PauseModel * mModel;
		PauseController * mController;
};

#endif // PAUSEVIEW_HPP
