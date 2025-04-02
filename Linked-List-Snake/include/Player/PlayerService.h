#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "SnakeController.h"

namespace Player
{
	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void createController();
		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer();
		std::vector<sf::Vector2i> getCurrentSnakePositionList() const;
		int getPlayerScore() const;
		TimeComplexity getTimeComplexity() const;
		LinkedListOperations getLastOperation() const;
	};
}