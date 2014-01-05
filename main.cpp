#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#include "gameplay/MyStateFactory.hpp"

#include "core/Application.hpp"


using namespace std;

int main(int argc, char ** argv) {

    cout << "Long Term Project " << __DATE__ << " at " << __TIME__ << endl;
	
	MyStateFactory factory;
	Application application(factory);

	//application.pushState(States::Title);
	//application.pushState(States::Test);
	application.pushState(States::Game);
	//application.pushState(States::Debug);
	
	application.run();

    return 0;
}

