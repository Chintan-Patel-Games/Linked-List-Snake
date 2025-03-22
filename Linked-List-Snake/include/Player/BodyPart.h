#pragma once
#include <SFML/System/Vector2.hpp>
#include "UI/UIElement/ImageView.h"
#include "Player/Direction.h"

namespace Player
{
	class BodyPart
	{
	protected:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		sf::Vector2f screen_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;

		void createBodyPartImage();
		void initializeBodyPartImage();
		void destroy();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void render();

		void updatePosition();

		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();
		Direction getDirection();
		void setDirection(Direction direction);

		sf::Vector2i getPosition();
		sf::Vector2i getNextPosition();
		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionLeft();
		sf::Vector2i getNextPositionRight();
		void setPosition(sf::Vector2i position);
	};
}