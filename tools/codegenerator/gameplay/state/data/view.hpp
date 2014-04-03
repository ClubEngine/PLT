#ifndef <<<HV>>>
#define <<<HV>>>

#include "Gameplay.hpp"

class <<<CM>>>;
class <<<CC>>>;

class <<<CV>>> : public AbstractStateView
{
	public:
		<<<CV>>>(ViewHelper & helper);
		void setModel(<<<CM>>> & model);
		void setController(<<<CC>>> & controller);
		
		virtual bool processInputs(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void render();
		
	private:
		<<<CM>>> * mModel;
		<<<CC>>> * mController;
};

#endif // <<<HV>>>
