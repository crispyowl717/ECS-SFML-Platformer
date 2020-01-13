#include "SourceCode/Public/Managers/MSystemManager.h"

// These are the prefabs we'll be using.
PF_MovingRectangle MovingRectangle;
PF_TopBox TopBox;
PF_BottomBox BottomBox;
HGrid Grid{15};

/*
 * Function:  Activate
 * --------------------
 * This creates a window, creates the prefabs and music, then begins the game loop. 
 *
 *
 */
void MSystemManager::Activate()
{
    sf::ContextSettings Settings;
    Settings.antialiasingLevel = 2;
    sf::RenderWindow CurrentWindow = sf::RenderWindow(sf::VideoMode(static_cast<unsigned>(_WindowSizes[_WindowSelectionID].x),
        static_cast<unsigned>(_WindowSizes[_WindowSelectionID].y)),"ECS Platformer", sf::Style::Default, Settings);
	
    CurrentWindow.setFramerateLimit(60);
    CurrentWindow.setKeyRepeatEnabled(false);
    CurrentWindow.setVerticalSyncEnabled(true);

	// Prefabs are a package of components 
    MovingRectangle.Create(Registry);
    TopBox.Create(Registry);
    BottomBox.Create(Registry);

    sf::Music Music;
    if (!Music.openFromFile("SourceCode/Assets/Music/Song.wav"))
        std::cout << "Missing Music" << std::endl;
    Music.play();
	
    Update(CurrentWindow);
}

/*
 * Function:  Update
 * --------------------
 * This is called each time-step.
 * All systems update and draw.
 *
 * Window: This is the window created in Activate.
 *
 */

void MSystemManager::Update(sf::RenderWindow& Window)
{
    sf::Clock Clock;

    while (Window.isOpen())
    {
    	// DeltaTime is referring to the spacing between two frames
        sf::Time DeltaTime;
        DeltaTime = Clock.restart();

        sf::Event Event{};
        while (Window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                Window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            Window.close();

    	// The window is cleared.
        Window.clear(sf::Color(238, 245, 178));

    	// The systems will then be updated.
    	// DeltaTime.asSeconds() multiplies whatever transformations made by an entity have a constant time-step.
        InputSystem.Update(Registry, DeltaTime.asSeconds());
        PhysicsSystem.Update(Registry, DeltaTime.asSeconds());
        RenderSystem.Update(Registry);

    	// Then they will be drawn.
        RenderSystem.Draw(Registry, Window);
        //Grid.Draw(Window);
        TopBox.Draw(Window);
        BottomBox.Draw(Window);

    	// Then they will display. 
        Window.display();
    }
}
