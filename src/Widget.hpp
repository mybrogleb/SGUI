#pragma once
#include "Config.hpp"

class Widget
{
private:

public:
	virtual ~Widget() {};
	virtual void cursor_position(sf::RenderWindow& window) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void event(const std::optional<sf::Event>& event) = 0;
	
};

