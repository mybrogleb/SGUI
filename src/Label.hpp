#pragma once
#include "Widget.hpp"

class Label : public Widget
{
private:

	//private obj:
	sf::RectangleShape label;
	std::optional<sf::Text> label_text;
	sf::Color shape_color = sf::Color::Yellow;
	sf::Vector2f cursor_pos;

	//private variable
	bool label_shape = false;
	float margin_x = 0;
	float margin_y = 0;

	//updaters:
	void auto_shape()
	{
		auto_shape_position();
		auto_shape_scale();
		auto_text_position();
	}
	void auto_text_position()
	{
		label_text->setPosition(sf::Vector2f(label_text->getPosition().x + margin_x/2, label_text->getPosition().y + margin_y/2));
	}
	void auto_shape_position()
	{
		sf::FloatRect rec = label_text->getGlobalBounds();
		label.setPosition(sf::Vector2f(rec.position.x, rec.position.y));
	}
	void auto_shape_scale()
	{
		label.setSize(sf::Vector2f(text_width() + margin_x, text_hight() + margin_y));
	}
	float text_width()
	{
		sf::FloatRect rec = label_text->getLocalBounds();
		return rec.size.x;
	}
	float text_hight()
	{
		sf::FloatRect rec = label_text->getLocalBounds();
		return rec.size.y;
	}

public:

	//constructors:
	Label(std::wstring str)
	{
		label_text.emplace(ARIAL_TTF);
		label_text->setString(str);
		label_text->setFillColor(sf::Color::Black);

		label.setFillColor(shape_color);
	}
	Label()
	{
		label_text.emplace(ARIAL_TTF);
		label_text->setString(L"SOME TEXT");
		label_text->setFillColor(sf::Color::Black);

		label.setFillColor(shape_color);
	}

	//setters:
	void text(sf::Color c)
	{
		label_text->setFillColor(c);
	}
	void text(int x)
	{
		label_text->setCharacterSize(x);
		auto_shape();
	}
	void text(sf::Text::Style& style)
	{
		label_text->setStyle(style);
		auto_shape();
	}
	void text(sf::Font& f)
	{
		label_text->setFont(f);
		auto_shape();
	}
	void text(std::wstring str)
	{
		label_text->setString(str);
		auto_shape();
	}

	void position(float x, float y)
	{
		label_text->setPosition(sf::Vector2f(x, y));
		auto_shape();
	}
	
	void background(bool b)
	{
		label_shape = b;

	}
	void background(sf::Color color)
	{
		label.setFillColor(color);
		shape_color = color;
	}
	void background(float x, float y)
	{
		margin_x = x;
		margin_y = y;

		auto_shape();
	}
	void background(float x)
	{
		margin_x = x;
		margin_y = x;

		auto_shape();
	}

	//public methods:
	void draw(sf::RenderWindow& window) override
	{

		if (label_shape) window.draw(label);
		if (label_text.has_value()) window.draw(*label_text);
	}
	void cursor_position(sf::RenderWindow& window) override
	{
		return;
	}
	void event(const std::optional<sf::Event>& event) override
	{
		return;
	}

	//getters:
	std::optional<sf::Text>& text()
	{
		return label_text;
	}
	sf::RectangleShape& shape()
	{
		return label;
	}
};
