#include "UI/LevelSelection/LevelSelectionUIController.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace UI
{
    namespace LevelSelection
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Sound;

        LevelSelectionUIController::LevelSelectionUIController()
        {
            createImage();
            createButtons();
        }

        LevelSelectionUIController::~LevelSelectionUIController()
        {
            destroy();
        }

        void LevelSelectionUIController::initialize()
        {
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void LevelSelectionUIController::createImage() { background_image = new ImageView(); }

        void LevelSelectionUIController::createButtons()
        {
            level1_button = new ButtonView();
            level2_button = new ButtonView();
            menu_button = new ButtonView();
        }

        void LevelSelectionUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void LevelSelectionUIController::initializeButtons()
        {
            level1_button->initialize("Level1 Button", Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(0, level1_button_y_position));
            level2_button->initialize("level2 Button", Config::level_two_button_texture_path, button_width, button_height, sf::Vector2f(0, level2_button_y_position));
            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));

            level1_button->setCentreAlinged();
            level2_button->setCentreAlinged();
            menu_button->setCentreAlinged();
        }

        void LevelSelectionUIController::registerButtonCallback()
        {
            level1_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::level1ButtonCallback, this));
            level2_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::level2ButtonCallback, this));
            menu_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::menuButtonCallback, this));
        }

        void LevelSelectionUIController::level1ButtonCallback()
        {
            GameService::setGameState(GameState::GAMEPLAY);
            ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::ONE);
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
        }

        void LevelSelectionUIController::level2ButtonCallback()
        {
            GameService::setGameState(GameState::GAMEPLAY);
            ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::TWO);
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
        }

        void LevelSelectionUIController::menuButtonCallback()
        {
            GameService::setGameState(GameState::MAIN_MENU);
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
        }

        void LevelSelectionUIController::update()
        {
            background_image->update();
            level1_button->update();
            level2_button->update();
            menu_button->update();
        }

        void LevelSelectionUIController::render()
        {
            background_image->render();
            level1_button->render();
            level2_button->render();
            menu_button->render();
        }

        void LevelSelectionUIController::show()
        {
            background_image->show();
            level1_button->show();
            level1_button->show();
            menu_button->show();
        }

        void LevelSelectionUIController::destroy()
        {
            delete (level1_button);
            delete (level2_button);
            delete (menu_button);
            delete (background_image);
        }
    }
}