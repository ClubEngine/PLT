#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "View.hpp"
#include "Model.hpp"

//Résolution des dépendances circulaires

namespace Gameplay
{
    class View;
    class Model;

    class Controller
    {
        public:
            Controller();
            void SetView(View const * view);
            void SetModel(Model const * model);
        protected:
            View const* mView;
            Model const* mModel;
    };
}
#endif // CONTROLLER_HPP
