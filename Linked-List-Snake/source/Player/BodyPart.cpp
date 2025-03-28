#include "Player/BodyPart.h"
#include "Global/Config.h"
#include "Level/LevelView.h"
#include "Level/LevelModel.h"

namespace Player
{
	BodyPart::BodyPart()
	{
		createBodyPartImage();
		grid_position = sf::Vector2i(0, 0);
	}

	BodyPart::~BodyPart() { destroy(); }

	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		direction = dir;
		grid_position = pos;

		initializeBodyPartImage();
	}

	void BodyPart::render() { bodypart_image->render(); }

	void BodyPart::createBodyPartImage() { bodypart_image = new UI::UIElement::ImageView(); }
	
	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Global::Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}

	void BodyPart::move()
	{
		grid_position = getNextPosition();
		updatePosition();
	}

	void BodyPart::updatePosition()
	{
		bodypart_image->setPosition(getBodyPartScreenPosition());
		bodypart_image->setRotation(getRotationAngle());
		bodypart_image->update();
	}

	sf::Vector2f BodyPart::getBodyPartScreenPosition()
	{
		float x_screen_position = Level::LevelView::border_offset_left + (grid_position.x * bodypart_width) + (bodypart_width / 2);
		float y_screen_position = Level::LevelView::border_offset_top + (grid_position.y * bodypart_height) + (bodypart_height / 2);

		return sf::Vector2f(x_screen_position, y_screen_position);
	}

	float BodyPart::getRotationAngle()
	{
		switch (direction)
		{
		case Direction::UP:
			return 270.f;
		case Direction::DOWN:
			return 90.f;
		case Direction::RIGHT:
			return 0;
		case Direction::LEFT:
			return 180.f;
		}
	}

	Direction BodyPart::getDirection() { return direction; }

	void BodyPart::setDirection(Direction direction) { this->direction = direction; }

	sf::Vector2i BodyPart::getPrevPosition()
	{
		switch (direction)
		{
		case Direction::UP:
			return getNextPositionDown();
		case Direction::DOWN:
			return getNextPositionUp();
		case Direction::RIGHT:
			return getNextPositionLeft();
		case Direction::LEFT:
			return getNextPositionRight();
		default:
			return grid_position;
		}
	}

	sf::Vector2i BodyPart::getPosition() { return grid_position; }

	sf::Vector2i BodyPart::getNextPosition()
	{
		switch (direction)
		{
		case Direction::UP:
			return getNextPositionUp();
		case Direction::DOWN:
			return getNextPositionDown();
		case Direction::RIGHT:
			return getNextPositionRight();
		case Direction::LEFT:
			return getNextPositionLeft();
		default:
			return grid_position;
		}
	}

	sf::Vector2i BodyPart::getNextPositionUp() { return sf::Vector2i(grid_position.x, (grid_position.y - 1 + (Level::LevelModel::number_of_rows)) % (Level::LevelModel::number_of_rows)); }

	sf::Vector2i BodyPart::getNextPositionDown() { return sf::Vector2i(grid_position.x, (grid_position.y + 1) % (Level::LevelModel::number_of_rows)); }

	sf::Vector2i BodyPart::getNextPositionRight() { return sf::Vector2i((grid_position.x + 1) % (Level::LevelModel::number_of_columns), grid_position.y); }

	sf::Vector2i BodyPart::getNextPositionLeft() { return sf::Vector2i((grid_position.x - 1 + Level::LevelModel::number_of_columns) % (Level::LevelModel::number_of_columns), grid_position.y); }

	void BodyPart::setPosition(sf::Vector2i position) { grid_position = position; }

	void BodyPart::destroy() { delete bodypart_image; }
}