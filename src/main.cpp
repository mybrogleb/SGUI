#include "SGUI.hpp"



bool test_foo2()
{
	return true;
}

void test_foo()
{
	
	if (test_foo2())
	{
		std::cout << "foo is work corretly";
	}
	
}

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 900, 800 } ), "SFML works!" );
	
	std::vector<std::unique_ptr<Button>> button_list;

	button_list.push_back(std::make_unique<Button>(shape_type::circle));
	button_list.push_back(std::make_unique<Button>(shape_type::circle));
	button_list.push_back(std::make_unique<Button>(shape_type::circle));

	for (int i = 0, j = 1; i < 3; i++, j++)
	{
		button_list[i]->origin(origin_type::center);
		button_list[i]->color(sf::Color::Blue);
		button_list[i]->size(100);
		button_list[i]->border(border_type::hover, 8, sf::Color::White);
		button_list[i]->position(225 * j, 600);
		button_list[i]->push_mod(push_type::oneclick);
		button_list[i]->callback(test_foo);
		
	}
	

	button_list.push_back(std::make_unique<Button>(shape_type::rectangle, L"КНОПКА_3"));

	button_list[3]->hover_color(sf::Color::Yellow);
    button_list[3]->origin(origin_type::center);
	button_list[3]->position(450, 100);
	button_list[3]->size(200, 80);
	
	
	button_list[3]->text(12);
	button_list[3]->text(sf::Color::Red);
	

	while ( window.isOpen() )
	{	
		// give mouse_pos for buttons
		for (auto& b : button_list)
		{
			b->cursor_position(window);
		}

		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )window.close();
			
			// give event to buttons
			for (auto& b : button_list)
			{
				b->event(event);
			} 

		}






		// pushing mode
		button_list[3]->when_pushing(test_foo);

		//all hover effects on
		for (auto& b : button_list)
		{

			b->hover_effects();
		}

		window.clear();
	
		// draw all
		for (auto& b : button_list)
		{
			
			b->draw(window);
		}

		window.display();
	}
}
