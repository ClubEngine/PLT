#include "Application.hpp"

using namespace std;
namespace Engine {


const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);



	Application::Application(AbstractStateFactory &factory)
		: mGLContext(), 
		  mWindow(sf::VideoMode(400, 300), 
				  "PLT", 
				  sf::Style::Default), 
		  mTextureHolder(), 
		  mSoundHolder(),
		  
		  mStateStackManager(factory),
		  mModelHelper(),
		  mViewHelper(),
		  mControllerHelper()
	{
		mSoundHolder.load(Sounds::Test, "assets/sounds/test.ogg");
	
		mTextureHolder.load(Textures::Patate,	"assets/images/patate.png");
		mTextureHolder.load(Textures::Rire,		"assets/images/canard.gif");
		mTextureHolder.load(Textures::Mapping, "assets/images/maptileset.bmp");
		
		mWindow.setKeyRepeatEnabled(false);
		mWindow.setVerticalSyncEnabled(true);
		
		mControllerHelper.setStateStackManager(mStateStackManager);
		
		mStateStackManager.setHelpers(mModelHelper,
									  mViewHelper,
									  mControllerHelper);
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
				
				processNetworkMessages();
				updateModels(TimePerFrame);
				processInputs();
				updateViews(TimePerFrame);
				
				// Check inside this loop, because stack might be empty before update() call
				if (mStateStackManager.isEmpty())
					mWindow.close();
			}
			
			//updateStatistics(dt);
			render();
		}
	}
	
	
	void Application::processNetworkMessages()
	{
	//	NetMsg msg;
	//	while (mNetwork.pollMsg(event)) {
	//		mStateStackManager.processNetMsg(msg);
	//	}
	}
	
	void Application::updateModels(sf::Time dt)
	{
		mStateStackManager.updateModels(dt);
	}
	
	void Application::processInputs()
	{
		sf::Event event;
		while (mWindow.pollEvent(event)) {
			
			
			mStateStackManager.processInputs(event);
		
			if (event.type == sf::Event::Closed)
				mStateStackManager.clearStates();
		}
	}
	
	void Application::updateViews(sf::Time dt)
	{
		mStateStackManager.updateViews(dt);
	}
	
	void Application::render()
	{
		mWindow.clear();
		mStateStackManager.render();
		mWindow.display();
	}

}
