#include "SGUI.hpp"

void click_on()
{
	std::cout << "mouse was clicked" << std::endl;
}

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 1080, 720 } ), "SFML works!" );
	
	std::vector<std::unique_ptr<Button>> button_list;


	button_list.push_back(std::make_unique<Button>(shape_type::circle));
	button_list.push_back(std::make_unique<Button>(shape_type::rectangle));
	
	button_list[0]->size(100);
	button_list[1]->size(200);

	button_list[0]->position(100, 100);
	button_list[1]->position(400, 400);

	button_list[0]->push_mod(push_type::oneclick);
	button_list[1]->push_mod(push_type::pushing);

	button_list[0]->callback(click_on);

	
	button_list[1]->origin(origin_type::center);
	button_list[0]->origin(origin_type::center);

	button_list[0]->color(sf::Color::Magenta);

	button_list[1]->hover_color(sf::Color::Blue);

	button_list[1]->border(border_type::hover, 6, sf::Color::Red);

	sf::Color what_color = button_list[0]->color();

	while ( window.isOpen() )
	{
		for (auto& b : button_list)
		{
			b->cursor_position(window);
		}

		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )window.close();
			
			for (auto& b : button_list)
			{
				b->event(event);
			}

		}

		button_list[1]->pushing_on(click_on);
		

	
		button_list[1]->hover_effects();


		window.clear();
		button_list[0]->draw(window);
		button_list[1]->draw(window);
		window.display();
	}
}
