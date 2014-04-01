#ifndef VIEW_HPP
#define VIEW_HPP

#include "../Model/Model.hpp"
#include "../Controller/Controller.hpp"

// Résolution des dépendances circulaires
class Controller;
class Model;

class View
{
    public:
        View();
        void SetModel(Model const * model);
        void SetController(Controller const * controller);
    protected:
        Model const* mModel;
        Controller const* mController;
};

#endif // VIEW_HPP
