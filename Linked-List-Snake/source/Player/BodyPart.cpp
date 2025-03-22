#include "Player/BodyPart.h"
#include "Global/Config.h"

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

	sf::Vector2f BodyPart::getBodyPartScreenPosition() const { return screen_position; }

	void BodyPart::destroy() { delete bodypart_image; }
}