#ifndef PAUSEMODEL_HPP
#define PAUSEMODEL_HPP

#include "Gameplay.hpp"

class PauseView;
class PauseController;

class PauseModel : public AbstractStateModel
{
	public:
		PauseModel(ModelHelper & helper);
		void setView(PauseView & view);
		void setController(PauseController & controller);
		
		virtual bool update(sf::Time dt);

	private:		
		PauseView * mView;
		PauseController * mController;
};

#endif // PAUSEMODEL_HPP
