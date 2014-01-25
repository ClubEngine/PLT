#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

/** Manage the map scrolling
  */
class Camera
{
	public:
		Camera(const sf::RenderTarget & render);
		
		void handleEvent(const sf::Event & event);
		
		void update(const sf::Time & dt);
		
		const sf::View & getView() const;
		
	private:
		sf::View mDefaultView;
		sf::View mView;
		sf::Vector2u mWindowSize;
		sf::Vector2f mMoveDirection;
};

#endif // CAMERA_HPP
