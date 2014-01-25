#include "Camera.hpp"

Camera::Camera(const sf::RenderTarget & render) : 
	mDefaultView(render.getDefaultView()), 
	mView(mDefaultView),
	mWindowSize(render.getSize()),
	mMoveDirection()
{
}

void Camera::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::MouseMoved) {
		const int & x = event.mouseMove.x;
		const int & y = event.mouseMove.y;
		
		const int margin = 20;
		const int speed = 1000;
		
		if (x < margin) {
			mMoveDirection.x = -speed;
		} else if (x > mWindowSize.x - margin) {
			mMoveDirection.x = speed;
		} else
			mMoveDirection.x = 0;
		
		if (y < margin) {
			mMoveDirection.y = -speed;
		} else if (y > mWindowSize.y - margin) {
			mMoveDirection.y = speed;
		} else
			mMoveDirection.y = 0;
	}
}

void Camera::update(const sf::Time &dt)
{
	mView.move(mMoveDirection.x * dt.asSeconds(),
			   mMoveDirection.y * dt.asSeconds());
}



const sf::View &Camera::getView() const
{
	return mView;
}
