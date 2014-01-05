#include "Application.hpp"

using namespace std;


const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);



Application::Application(AbstractStateFactory &factory)
	: mGLContext(), 
	  mWindow(sf::VideoMode(800, 600), 
			  "PLT", 
		      sf::Style::Default), 
	  mTextureHolder(), 
	  mSoundHolder(),
	  mStateStack(factory, Context(mWindow, 
								   mTextureHolder, 
							       mSoundHolder))
{
    mSoundHolder.load(Sounds::Test, "assets/sounds/test.ogg");

    mTextureHolder.load(Textures::Patate,	"assets/images/patate.png");
    mTextureHolder.load(Textures::Rire,		"assets/images/canard.gif");
	
	mWindow.setKeyRepeatEnabled(false);
	mWindow.setVerticalSyncEnabled(true);
}

void Application::pushState(States::ID id)
{
	mStateStack.pushState(id);
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
			
			processInputs();
			update(TimePerFrame);
			
			// Check inside this loop, because stack might be empty before update() call
			if (mStateStack.isEmpty())
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
		
		mStateStack.handleEvent(event);
	
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Application::update(sf::Time dt)
{
	mStateStack.update(dt);
}


void Application::render()
{
	mWindow.clear();
	mStateStack.draw();
	mWindow.display();
}

