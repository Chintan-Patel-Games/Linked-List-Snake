#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Level/LevelService.h"
#include "Player/SnakeController.h"

namespace Player
{
	using namespace Level;
	class SnakeController;

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

		void spawnPlayer(LinkedListType level_type);

		bool isSnakeSizeMinimum();
		bool isPlayerDead();
		int getPlayerScore() const;
		std::vector<sf::Vector2i> getCurrentSnakePositionList() const;
		TimeComplexity getTimeComplexity() const;
		LinkedListOperations getLastOperation() const;
		int getSnakeSize();
		SnakeState getSnakeState();
	};
}