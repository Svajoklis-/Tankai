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
		window.display();
	}

	return 0;
}