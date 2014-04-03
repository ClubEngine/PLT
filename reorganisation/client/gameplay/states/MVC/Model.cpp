#include "Model.hpp"

namespace Gameplay
{
    Model::Model()
    {
    }
    void Model::SetView(View const * view)
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

    void Model::SetController(Controller const * controller)
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

