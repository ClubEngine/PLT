#ifndef <<<HM>>>
#define <<<HM>>>

#include "Gameplay.hpp"

class <<<CV>>>;
class <<<CC>>>;

class <<<CM>>> : public AbstractStateModel
{
	public:
		<<<CM>>>(ModelHelper & helper);
		void setView(<<<CV>>> & view);
		void setController(<<<CC>>> & controller);
		
		virtual bool update(sf::Time dt);

	private:		
		<<<CV>>> * mView;
		<<<CC>>> * mController;
};

#endif // <<<HM>>>
