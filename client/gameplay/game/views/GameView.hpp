#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include "Engine.hpp"

class GameModel;
class GameController;

class GameView : public AbstractStateView
{
	public:
		GameView(ViewHelper & helper);
		void setModel(GameModel &model);
		void setController(GameController &controller);
		
		virtual bool processInputs(const sf::Event & event);
		virtual bool update(sf::Time dt);
		virtual void render();
		
	private:
		GameModel * mModel;
		GameController * mController;
//		bool mouseispressed;

//        struct selected {
//            MapCordinates p1;
//            MapCordinates p2;
//            sf::Vector2i i1;
//            sf::Vector2i i2;
//        };
//        float aux;

//        selected selected;

//        int width, height;
//        Map *map;

//        sf::Texture grid;
//        sf::Sprite gridsprite;
//        sf::RectangleShape selection;
//        sf::RectangleShape upleft;
//        sf::RectangleShape upright;
//        sf::RectangleShape downright;
//        sf::RectangleShape downleft;
//        sf::RectangleShape upseg;
//        sf::RectangleShape rightseg;
//        sf::RectangleShape leftseg;
//        sf::RectangleShape downseg;
		
		
		//Camera camera;
};

#endif // GAMEVIEW_HPP
