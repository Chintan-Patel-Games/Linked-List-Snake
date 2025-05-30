#include "Level/LevelModel.h"
#include "Level/LevelService.h"
#include "Element/ElementService.h"

namespace Level
{
	LevelModel::LevelModel() = default;

	LevelModel::~LevelModel() = default;

	void LevelModel::initialize(int width, int height)
	{
		cell_width = static_cast<float>(width) / static_cast<float>(number_of_columns);
		cell_height = static_cast<float>(height) / static_cast<float>(number_of_rows);

		initializeLevelData();
	}

	void LevelModel::initializeLevelData()
	{
		level_configurations.push_back(LevelData(Level::LevelNumber::ONE, &level_one_element_list));
		level_configurations.push_back(LevelData(Level::LevelNumber::TWO, &level_two_element_list));
	}

	const std::vector<Element::ElementData>& LevelModel::getElementDataList(int level_to_load) const { return *level_configurations[level_to_load].element_data_list; }

	float LevelModel::getCellWidth() const { return cell_width; }

	float LevelModel::getCellHeight() const { return cell_height; }
}