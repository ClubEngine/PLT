#include "Controller.hpp"

namespace Gameplay
{
    Controller::Controller()
    {
    }
    void Controller::SetView(View const * view)
    {
        if(view != 0)
        {
            mView = view;
        }
        else
        {
            //throw exception : exception à définir
        }
    }

    void Controller::SetModel(Model const * model)
    {
        if(model != 0)
        {
            mModel = model;
        }
        else
        {
            //throw exception : exception à définir
        }
    }
}
