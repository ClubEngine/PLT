#ifndef MODEL_HPP
#define MODEL_HPP

#include "../View/View.hpp"
#include "../Controller/Controller.hpp"

//Résolution des dépendances circulaires
class View;
class Controller;

class Model
{
    public:
        Model();
        void SetView(View const * view);
        void SetController(Controller const * model);
    protected:
        View const* mView;
        Controller const* mController;
};

#endif // MODEL_HPP
