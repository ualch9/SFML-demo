#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include <iostream>

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(500, 500), "Poke");		// Create a window that is 500x500 pixels big.

	// Create the textures
	sf::Texture happyTexture;
	happyTexture.loadFromFile("Images/person_happy.png");

	sf::Texture sadTexture;
	sadTexture.loadFromFile("Images/person_sad.png");

	// Create the sprite
	sf::Sprite personSprite;
	personSprite.setTexture(happyTexture);					// Attach the texture to the sprite (start with happy texture)
	personSprite.setOrigin(sf::Vector2f(150, 150));			// Set the sprite's origin to be the center of our 300x300 png image file
	personSprite.setPosition(sf::Vector2f(250, 250));		// Position the sprite (in relation to the window)

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close the window if the user clicked on the (X) close button.
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// If the user clicked in the window, determine if the mouse was clicked
			// inside the sprite. If the mouse was clicked inside the sprite, we poked
			// the person and now they are sad.
			else if (event.type == sf::Event::MouseButtonReleased) {
				auto mousePosition = sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y);

				if (personSprite.getGlobalBounds().contains(mousePosition)) {
					std::cout << ":-( Player clicked inside the sprite" << std::endl;
					personSprite.setTexture(sadTexture);
				} else {
					std::cout << ":-) Player clicked outside of sprite" << std::endl;
					personSprite.setTexture(happyTexture);
				}
			}
		}

		window.clear();
		window.draw(personSprite);
		window.display();
	}

	return 0;
}