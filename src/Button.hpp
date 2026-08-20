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
	oneclick, released
};

class Button : public Widget
{
private:
	std::variant<sf::RectangleShape, sf::CircleShape> shape;
	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	std::optional<sf::Text> button_text;
	sf::Vector2f cursor_pos;
	sf::Color button_color;
	sf::Color hover_button_color = sf::Color::Yellow;
	std::function<void()> storage_callback;
	push_type button_push_type;
	border_type button_border_type;
	origin_type origin_button_type;

	bool hover = false;
	bool is_hover_color_on = false;
	float border_thick = 0;
	bool waspressed = false;

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

		if (!is_hover_color_on) return;

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
	bool exist()
	{
		if (auto s = std::get_if<sf::RectangleShape>(&shape))
		{
			return true;
		}
		else if (auto s = std::get_if<sf::CircleShape>(&shape))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void text_update()
	{
		if (button_text.has_value())
		{
			if (origin_button_type == origin_type::center)
			{
				text_origin_update();
				button_text->setPosition(position());
			}

			if (origin_button_type == origin_type::angle)
			{
				text_origin_update();
				button_text->setPosition(button_center());
			}
		}
		
	}
	void text_origin_update()
	{
		if (!button_text.has_value()) return;
		sf::FloatRect rc = button_text->getLocalBounds();
		button_text->setOrigin(sf::Vector2f(rc.position.x + (rc.size.x / 2), rc.position.y + (rc.size.y / 2)));
	
	}
	void initText(std::wstring text)
	{


		button_text.emplace(ARIAL_TTF);
		button_text->setString(text);
		button_text->setFillColor(sf::Color::Magenta);
		button_text->setLineAlignment(sf::Text::LineAlignment::Center);
		text_origin_update();
	}

public:

	void when_pushing(std::function<void()> call)
	{
		storage_callback = call;

		
        
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !hover)
		{
			waspressed = true;
		}
		else if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			waspressed = false;
		}

		if (hover && waspressed == false)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				if (storage_callback)
				{
					storage_callback();
				}
			}
		}

		
	}

	void push_mod(push_type type)
	{
		if (type == push_type::oneclick) button_push_type = push_type::oneclick;
		if (type == push_type::released) button_push_type = push_type::released;
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
			  if(exist()) window.draw(shape);
			  if (button_text.has_value())
			  {
				  window.draw(*button_text);
			  }
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

	//constructors:
	Button(shape_type type)
	{
		initType(type);
		initBaseValue();

		origin_button_type = origin_type::angle;
		button_color = BASE_BUTTON_COLOR;
		if(type == shape_type::rectangle) shape._Storage()._Get().setSize(BASE_RECTANGLE_SIZE);
		if (type == shape_type::circle)
		{
			auto s = std::get_if<sf::CircleShape>(&shape);
			s->setRadius(BASE_CIRCLE_RADIUS);
			
		}
	}
	Button(shape_type type, std::wstring text)
	{
		initType(type);
		initBaseValue();
		initText(text);

		origin_button_type = origin_type::angle;
		button_color = BASE_BUTTON_COLOR;

		if (type == shape_type::rectangle)
		{
			shape._Storage()._Get().setSize(BASE_RECTANGLE_SIZE);
		
		}
		if (type == shape_type::circle)
		{
			auto s = std::get_if<sf::CircleShape>(&shape);
			s->setRadius(BASE_CIRCLE_RADIUS);

		}

		text_update();

		
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

		text_update();
	}
	void position(float x, float y)
	{
		std::visit([&](auto& shape) {
			shape.setPosition(sf::Vector2f(x, y));
			}, this->shape);

		text_update();
		
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

		text_update();
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
		
		text_update();
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

		text_update();
	}
	void color(sf::Color color)
	{
		std::visit([&](auto& shape) {
			shape.setFillColor(color);
			}, this->shape);
		button_color = color;
	}
	void hover_color(sf::Color color)
	{
		hover_button_color = color;
		is_hover_color_on = true;

	}
	void text(std::wstring str)
	{
		button_text->setString(str);
		text_update();
	}
	void text(sf::Color clr)
	{
		button_text->setFillColor(clr);
	}
	void text(int x)
	{
		button_text->setCharacterSize(x);
		text_update();
	}
	void text(sf::Text::Style& style)
	{
		button_text->setStyle(style);
		text_update();
	}
	void text(sf::Font& f)
	{
		button_text->setFont(f);
		text_update();
	}

	//getters:
	std::optional<sf::Text>& text()
	{
		return button_text;
	}
	sf::Color& color()
	{
		return shape._Storage()._Get().getFillColor();
	}
	sf::Color& hover_color()
	{
		return hover_button_color;
	}
	sf::Color& border_color()
	{
		return shape._Storage()._Get().getOutlineColor();
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

		if (auto s = std::get_if<sf::RectangleShape>(&shape))
		{
			return s->getPosition();
		}
		else if (auto s = std::get_if<sf::CircleShape>(&shape))
		{
			return s->getPosition();
		}
	}
	sf::Vector2f& button_origin()
	{

		if (auto s = std::get_if<sf::RectangleShape>(&shape))
		{

			return s->getOrigin();
		}
		else if (auto s = std::get_if<sf::CircleShape>(&shape))
		{
			return s->getOrigin();
		}


	}
	sf::Vector2f button_center()
	{
		if (auto s = std::get_if<sf::RectangleShape>(&shape))
		{
			if (origin_button_type == origin_type::angle)
			{
				sf::FloatRect r = s->getGlobalBounds();
				return sf::Vector2f(r.position.x + r.size.x / 2, r.position.y + r.size.y / 2);
			}

		}
		else if (auto s = std::get_if<sf::CircleShape>(&shape))
		{
			sf::FloatRect r = s->getGlobalBounds();
			return sf::Vector2f(r.position.x + r.size.x / 2, r.position.y + r.size.y / 2);
		}
	}
};