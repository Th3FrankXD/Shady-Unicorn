#include <string>
#include "game_state.h"
#include "main_game.h"
#include "main_menu.h"

GameState coreState;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My window");

	coreState.SetWindow(&window);
	coreState.setState(new MainMenu());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		coreState.Update();
		coreState.Render();

		window.display();
	}

	return 0;
}