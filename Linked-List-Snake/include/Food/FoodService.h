#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <random>

namespace Food
{
	enum class FoodType;
	class FoodItem;

	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		std::default_random_engine random_engine;
		std::random_device random_device;

		FoodType getRandomFoodType();
		FoodItem* createFood(sf::Vector2i position, FoodType type);
		sf::Vector2i getValidSpawnPosition();
		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		void spawnFood();
		sf::Vector2i getRandomPosition();
		void destroyFood();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
	};
}