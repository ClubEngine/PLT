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
		
        const int speed = 1000;
		const int margin = 20;

		
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

    else if(event.type == sf::Event::KeyPressed){

        const int speed = 1000;

        switch (event.key.code) {
            case sf::Keyboard::Up :
                mMoveDirection.y = -speed;
                break;
            case sf::Keyboard::Down :
                mMoveDirection.y = speed;
                break;
            case sf::Keyboard::Right :
                mMoveDirection.x = speed;
                break;
            case sf::Keyboard::Left :
                mMoveDirection.x = -speed;
                break;
            case sf::Keyboard::Home :
                mView.setCenter(mView.getSize().x/2, mView.getSize().y/2);
                break;
            default:
                break;
        }
    }

    else if(event.type == sf::Event::KeyReleased){
       mMoveDirection.x = 0;
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
