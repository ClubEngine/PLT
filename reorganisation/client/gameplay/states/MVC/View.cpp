#include "View.hpp"

namespace Gameplay
{
    View::View()
    {
    }
    void View::SetModel(Model const * model)
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
    void View::SetController(Controller const * controller)
    {
        if(controller != 0)
        {
            mController = controller;
        }
        else
        {
            //throw exception : exception à définir
        }
    }
}
