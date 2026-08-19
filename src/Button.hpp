#pragma once
#include "Widget.hpp"

enum class border_type
{
	hover, fixed
};

enum class origin_type
{
	center, angle
};
enum class shape_type
{
	rectangle, circle
};

enum class push_type
{
	oneclick, released, pushing
};

class Button : public Widget
{
private:
	std::variant<sf::RectangleShape, sf::CircleShape> shape;
	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	sf::Vector2f cursor_pos;
	sf::Color button_color;
	sf::Color hover_button_color = sf::Color::Yellow;
	std::function<void()> storage_callback;
	push_type button_push_type;
	border_type button_border_type;
	bool hover = false;
	float border_thick = 0;
	
	void initType(shape_type& type)
	{
		if (type == shape_type::circle) shape = circle;
		if (type == shape_type::rectangle) shape = rectangle;
	}
	void initBaseValue()
	{
		std::visit([&](auto& shape) {
			shape.setPosition(BASE_POS);
			shape.setFillColor(BASE_BUTTON_COLOR);
			}, this->shape);
	}
	void hover_state_update()
	{
		if (shape._Storage()._Get().getGlobalBounds().contains(cursor_pos))
		{
			hover = true;
		}
		else
		{
			hover = false;
		}
	}
	void hover_color_on()
	{
		hover_state_update();

		if (hover)
		{

			shape._Storage()._Get().setFillColor(hover_button_color);
		}
		else
		{
			shape._Storage()._Get().setFillColor(button_color);
		}
	}
	void hover_border_on()
	{
		hover_state_update();

		if (hover)
		{
			shape._Storage()._Get().setOutlineThickness(border_thick);


		}
		else
		{
			shape._Storage()._Get().setOutlineThickness(0);
		}
	}







public:

	void pushing_on(std::function<void()> call)
	{
		storage_callback = call;

		if (button_push_type == push_type::pushing && hover && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (storage_callback)
			{
				storage_callback();
			}
		}
	}

	void push_mod(push_type type)
	{
		if (type == push_type::oneclick) button_push_type = push_type::oneclick;
		if (type == push_type::released) button_push_type = push_type::released;
		if (type == push_type::pushing) button_push_type = push_type::pushing;
	}
	
	void callback(std::function<void()> call)
	{
		storage_callback = call;
	}

	void hover_effects()
	{
		hover_border_on();
		hover_color_on();
	}

	void cursor_position(sf::RenderWindow& window)
	{
		this->cursor_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	}

	void draw(sf::RenderWindow& window) override
	{
		std::visit([&](auto& shape)
			{
				window.draw(shape);
			}, this->shape);

	}

	void event(const std::optional<sf::Event>& event) override
	{
		hover_state_update();

			
			

				if (button_push_type == push_type::oneclick && hover)
				{
					if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
					{

						if (mouseButtonPressed->button == sf::Mouse::Button::Left)
						{
							if (storage_callback)
							{
								storage_callback();
							}
						}


					}
				}

				if (button_push_type == push_type::released && hover)
				{
					if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonReleased>())
					{

						if (mouseButtonPressed->button == sf::Mouse::Button::Left)
						{
							if (storage_callback)
							{
								storage_callback();
							}
						}


					}
				}
			

		
		
	}

	
	Button(shape_type type)
	{
		initType(type);
		initBaseValue();
		button_color = BASE_BUTTON_COLOR;
		if(type == shape_type::rectangle) shape._Storage()._Get().setSize(BASE_RECTANGLE_SIZE);
		if (type == shape_type::circle)
		{
			auto s = std::get_if<sf::CircleShape>(&shape);
			s->setRadius(BASE_CIRCLE_RADIUS);
			
		}
	}


	//setters:
	void border(border_type type, float size, sf::Color color)
	{
		if (type == border_type::fixed)
		{
			shape._Storage()._Get().setOutlineThickness(size);
			shape._Storage()._Get().setOutlineColor(color);
			button_border_type = type;
		}

		if (type == border_type::hover)
		{
			border_thick = size;
			shape._Storage()._Get().setOutlineThickness(0);
			shape._Storage()._Get().setOutlineColor(color);
			button_border_type = type;
		}
	}
	void scale(sf::Vector2f scale)
	{
		if (auto s = std::get_if<sf::RectangleShape>(&shape))
		{
			s->setScale(scale);
		}
		else if (auto s = std::get_if<sf::CircleShape>(&shape))
		{
			s->setScale(scale);
		}
	}
	void position(float x, float y)
	{
		shape._Storage()._Get().setPosition(sf::Vector2f(x, y));
	}
	void size(float x, float y)
	{
		if (auto s = std::get_if<sf::RectangleShape>(&shape))
		{
			s->setSize(sf::Vector2f(x, y));
		}
		else if (auto s = std::get_if<sf::CircleShape>(&shape))
		{
			s->setRadius(x/2);
		}
	}
	void size(float x)
	{
		if (auto s = std::get_if<sf::CircleShape>(&shape))
		{
			s->setRadius(x/2);
		}
		else if (auto s = std::get_if<sf::RectangleShape>(&shape))
		{
			s->setSize(sf::Vector2f(x,x));
		}
		
		
	}
	void origin(origin_type type)
	{
		if (type == origin_type::center)
		{
			if (auto s = std::get_if<sf::RectangleShape>(&shape))
			{
				sf::FloatRect rc = s->getLocalBounds();
				s->setOrigin(sf::Vector2f(rc.size.x / 2, rc.size.y / 2));
			}
			else if (auto s = std::get_if<sf::CircleShape>(&shape))
			{
				s->setOrigin(sf::Vector2f(s->getRadius(), s->getRadius()));
			}
		}
		else
		if (type == origin_type::angle)
		{
			if (auto s = std::get_if<sf::RectangleShape>(&shape))
			{
				s->setOrigin(sf::Vector2f(0, 0));
			}
			else if (auto s = std::get_if<sf::CircleShape>(&shape))
			{
				s->setOrigin(sf::Vector2f(0, 0));
			}
		}
	}
	void color(sf::Color color)
	{
		shape._Storage()._Get().setFillColor(color);
		button_color = color;
	}
	void hover_color(sf::Color color)
	{
		hover_button_color = color;
	}
	//getters:
	sf::Color color()
	{
		return shape._Storage()._Get().getFillColor();
	}
	sf::Vector2f size()
	{
		if (auto s = std::get_if<sf::RectangleShape>(&shape))
		{
			return s->getSize();
		}
		else if (auto s = std::get_if<sf::CircleShape>(&shape))
		{
			return sf::Vector2f(s->getRadius()*2, s->getRadius() * 2);
		}
	}
	sf::Vector2f& position()
	{
		return shape._Storage()._Get().getPosition();
	}

};