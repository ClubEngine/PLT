#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <Controller/Controller.hpp>
#include <View/View.hpp>
#include <Model/Model.hpp>

class Application
{
    public:
        Application();
        void run();
    protected:
        Controller mController;
        View mView;
        Model mModel;
};

#endif // APPLICATION_HPP
