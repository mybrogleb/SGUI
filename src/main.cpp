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
	sf::RenderWindow window(sf::VideoMode({ 900, 800 }), "SFML works!");

	std::vector<std::unique_ptr<Button>> button_list;

	button_list.push_back(std::make_unique<Button>(shape_type::rectangle, L"КНОПКА_3"));

	button_list[0]->hover_color(sf::Color::Yellow);
	button_list[0]->origin(origin_type::center);
	button_list[0]->position(450, 100);
	button_list[0]->size(200, 80);
	
	
	button_list[0]->text(12);
	button_list[0]->text(sf::Color::Red);

	Label header(L"ЗАГОЛОВОК");
	
	header.text(32);
	header.background(SG_ON);
	header.background(300, 0);

	header.position(400, 300);




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
		button_list[0]->when_pushing(test_foo);

		//all hover effects on
		for (auto& b : button_list)
		{

			b->hover_effects(SG_ON);
		}

		window.clear();
	
		// draw all
		for (auto& b : button_list)
		{
			
			b->draw(window);
		}

		header.draw(window);

		window.display();
	}
}
