#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>
#include "LinkedListLib/Node.h"

namespace Food
{
	enum class FoodType;
	class FoodItem;

	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};

	class FoodService
	{
	private:
		FoodItem* current_food_item;
		FoodSpawningStatus current_spawning_status;

		float cell_width;
		float cell_height;

		std::default_random_engine random_engine; // To generate random values.
		std::random_device random_device; // To give random seed to generator.

		const float spawn_duration = 4.f;
		float elapsed_duration;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		sf::Vector2i getValidSpawnPosition();
		sf::Vector2i getRandomPosition();
		FoodType getRandomFoodType();
		bool isValidPosition(std::vector<sf::Vector2i> position_data, std::vector<sf::Vector2i> elements_position_data, sf::Vector2i food_position);
		void updateElapsedDuration();
		void handleFoodSpawning();
		void reset();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		bool processFoodCollision(LinkedListLib::Node* head_node, FoodType& out_food_type);
		void startFoodSpawning();
		void spawnFood();
		void stopFoodSpawning();
		void destroyFood();
	};
}