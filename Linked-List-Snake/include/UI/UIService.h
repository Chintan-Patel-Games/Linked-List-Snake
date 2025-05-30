#pragma once
#include "UI/MainMenu/MainMenuUIController.h"
#include "UI/LevelSelection/LevelSelectionUIController.h"
#include "LinkedListSelection/LinkedListSelectionUIController.h"
#include "UI/Gameplay/GameplayUIController.h"
#include "UI/SplashScreen/SplashScreenUIController.h"
#include "Instructions/InstructionsScreenUIController.h"
#include "UI/Credits/CreditsScreenUIController.h"
#include "UI/Interface/IUIController.h"

namespace UI
{
	class UIService
	{
	private:
		SplashScreen::SplashScreenUIController* splash_screen_controller;
		MainMenu::MainMenuUIController* main_menu_controller;
		LevelSelection::LevelSelectionUIController* level_selection_controller;
		LinkedListSelection::LinkedListSelectionUIController* linked_list_selection_ui_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		Instructions::InstructionsScreenUIController* instructions_screen_ui_controller;
		Credits::CreditsScreenUIController* credits_screen_ui_controller;

		void createControllers();
		void initializeControllers();
		Interface::IUIController* getCurrentUIController();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
	};
}