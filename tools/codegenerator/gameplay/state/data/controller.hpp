#ifndef <<<HC>>>
#define <<<HC>>>

#include "Gameplay.hpp"

class <<<CM>>>;
class <<<CV>>>;

class <<<CC>>> : public AbstractStateController
{
	public:
		<<<CC>>>(ControllerHelper & helper);
		void setModel(<<<CM>>> & model);
		void setView(<<<CV>>> & view);
		
		virtual bool processAuthoritativeMessage();
				
	private:
		<<<CV>>> * mView;
		<<<CM>>> * mModel;
};

#endif // <<<HC>>>
