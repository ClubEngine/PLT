#include "PauseView.hpp"

#include "../controllers/PauseController.hpp"
#include "../models/PauseModel.hpp"


PauseView::PauseView(ViewHelper &helper)
	: AbstractStateView(helper)
{
}

void PauseView::setModel(PauseModel &model)
{
	mModel = &model;
}

void PauseView::setController(PauseController &controller)
{
	mController = &controller;
}

bool PauseView::processInputs(const sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed &&
		event.key.code == sf::Keyboard::P)
	{
		mController->resume();
	}
	return false;
}

bool PauseView::update(sf::Time dt)
{
	return false;
}

void PauseView::render()
{
	sf::RenderTarget & target = mHelper.getRenderTarget();
		
	target.setView(target.getDefaultView());
		
	sf::RectangleShape rect(sf::Vector2f(800,600));
	rect.setFillColor(sf::Color(0,0,64,128));
	target.draw(rect);
}
