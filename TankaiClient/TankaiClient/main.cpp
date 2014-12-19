#include <iostream>

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::View view;
	view.reset(sf::FloatRect(0, 0, 250, 250));
	window.setView(view);
	sf::CircleShape shape(125.f);
	shape.setFillColor(sf::Color::Green);

	sf::Texture tPlayerOne;
	if (!tPlayerOne.loadFromFile(".\\Resources\\Images\\Player1.png"))
	{
		std::cout << "Error loading Player 1 texture";
		return 1;
	}

	sf::Sprite sPlayerOne;
	sPlayerOne.setTexture(tPlayerOne);
	sPlayerOne.setTextureRect(sf::IntRect(0, 0, 16, 16));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.draw(sPlayerOne);
		window.display();
	}

	return 0;
}