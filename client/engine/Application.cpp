#include "Application.hpp"

using namespace std;
using namespace Engine;


const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);



Application::Application(AbstractStateFactory &factory)
	: mGLContext(), 
	  mWindow(sf::VideoMode(400, 300), 
			  "PLT", 
		      sf::Style::Default), 
	  mTextureHolder(), 
	  mSoundHolder(),
	  mStateStackManager(factory, Context(mWindow, 
								   mTextureHolder, 
							       mSoundHolder))
{
    mSoundHolder.load(Sounds::Test, "assets/sounds/test.ogg");

    mTextureHolder.load(Textures::Patate,	"assets/images/patate.png");
    mTextureHolder.load(Textures::Rire,		"assets/images/canard.gif");
    mTextureHolder.load(Textures::Mapping, "assets/images/maptileset.bmp");
	
	mWindow.setKeyRepeatEnabled(false);
	mWindow.setVerticalSyncEnabled(true);
}

void Application::pushState(States::ID id)
{
	mStateStackManager.pushState(id);
}

void Application::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	while (mWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			
			//processNetworkMessages();
			//updateModel(TimePerFrame);
			processInputs();
			//updateView(TimePerFrame);
			
			
			
			update(TimePerFrame);
			
			// Check inside this loop, because stack might be empty before update() call
			if (mStateStackManager.isEmpty())
				mWindow.close();
		}
		
		//updateStatistics(dt);
		render();
	}
}


void Application::processInputs()
{
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		
		
		mStateStackManager.handleEvent(event);
	
		if (event.type == sf::Event::Closed)
			mStateStackManager.clearStates();
	}
}

void Application::update(sf::Time dt)
{
	mStateStackManager.update(dt);
}


void Application::render()
{
	mWindow.clear();
	mStateStackManager.draw();
	mWindow.display();
}

