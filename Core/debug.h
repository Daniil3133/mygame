#ifndef DEBUG_H
#define DEBUG_H

#include <SFML/Graphics.hpp>
#include <string>
#include <queue>
#include "vec2.h"

class debug
{
	static sf::Text* m_text;
	static std::queue<std::string> m_stream;
public:
	debug();
	void update();
	void setText(sf::Text* text);
	debug& operator<<(const std::string& str);
	debug& operator<<(const float& str);
	debug& operator<<(const int& str);
	debug& operator<<(const vec2& v);
};

#endif // DEBUG_H