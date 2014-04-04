#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "engine/Application.hpp"
#include "gameplay/MyStateFactory.hpp"

using namespace std;

int main(int argc, char ** argv) {

    cout << "\nLong Term Project " << __DATE__ << " at " << __TIME__ << endl;
	
	MyStateFactory factory;
	//Gameplay gameplay;	
	engine::Application application(factory);

	//application.pushState(States::Title);
	//application.pushState(States::Test);
	application.pushState(States::Debug);
	application.pushState(States::Game);
    //application.pushState(States::Pause);
	
	
	
	application.run();

    return 0;
}

