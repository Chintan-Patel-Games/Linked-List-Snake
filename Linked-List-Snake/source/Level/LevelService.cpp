#include "Level/LevelService.h"
#include "Level/LevelController.h"
#include "Global/ServiceLocator.h"

namespace Level
{
	LevelService::LevelService()
	{
		level_controller = nullptr;
		createLevelController();
	}

	LevelService::~LevelService() { destroy(); }

	void LevelService::createLevelController() { level_controller = new LevelController(); }

	void LevelService::spawnPlayer() { Global::ServiceLocator::getInstance()->getPlayerService()->spawnPlayer(current_linked_list_type); }

	void LevelService::spawnFood() { Global::ServiceLocator::getInstance()->getFoodService()->startFoodSpawning(); }

	void LevelService::spawnLevelElements(LevelNumber level_to_load)
	{
		current_level = level_to_load;

		float cell_width = level_controller->getCellWidth();
		float cell_height = level_controller->getCellHeight();

		std::vector<Element::ElementData> element_data_list = level_controller->getElementDataList((int)level_to_load);
		Global::ServiceLocator::getInstance()->getElementService()->spawnElements(element_data_list, cell_width, cell_height);
	}

	void LevelService::initialize() { level_controller->initialize(); }

	void LevelService::update() { level_controller->update(); }

	void LevelService::render() { level_controller->render(); }

	void LevelService::createLevel(LinkedListType linked_list_type)
	{
		current_linked_list_type = linked_list_type;
		spawnLevelElements(current_level);
		spawnPlayer();
		spawnFood();
	}

	float LevelService::getCellWidth() const { return level_controller->getCellWidth(); }

	float LevelService::getCellHeight() const { return level_controller->getCellHeight(); }

	LevelNumber LevelService::getCurrentLevel() const { return current_level; }

	void LevelService::setCurrentLevel(LevelNumber level_to_load) { current_level = level_to_load; }

	LinkedListType LevelService::getCurrentLinkedListType() const { return current_linked_list_type; }

	void LevelService::destroy() { delete level_controller; }
}