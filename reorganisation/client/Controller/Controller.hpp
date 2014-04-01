#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../View/View.hpp"
#include "../Model/Model.hpp"

//Résolution des dépendances circulaires
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

#endif // CONTROLLER_HPP
