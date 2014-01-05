#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "core/state/StateStack.hpp"
#include "gameplay/CStateFactory.hpp"
#include "core/Context.hpp"
#include "core/Application.hpp"
#include "core/TextureHolder.hpp"

using namespace std;

int main(int argc, char ** argv) {

    cout << "Long Term Project " << __DATE__ << " at " << __TIME__ << endl;
	
	CStateFactory factory;
	Application application(factory);
	
	application.pushState(States::Title);
	application.pushState(States::Game);
	application.pushState(States::Debug);
	
	application.run();	
   
    return 0;
}

