#ifndef <<<HS>>>
#define <<<HS>>>

#include "Gameplay.hpp"

#include "views/<<<CV>>>.hpp"
#include "models/<<<CM>>>.hpp"
#include "controllers/<<<CC>>>.hpp"


class <<<CS>>> : public AbstractState
{
	public:
		<<<CS>>>(ModelHelper &modelHelper, 
				  ViewHelper &viewHelper,
			      ControllerHelper &controllerHelper);
		
	private:
		<<<CM>>> mModel;
		<<<CV>>> mView;
		<<<CC>>> mController;
};


#endif // <<<HS>>>
