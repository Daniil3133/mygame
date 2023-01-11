#include <Core/debug.h>


#include <sstream>

//--------------DEBUG------------
debug::debug(){}
void debug::update()
{
	if(m_text==nullptr)
	{
		throw std::runtime_error("Text not initialized");
		return;
	}

	while(m_stream.size() > 20)
        m_stream.pop();
     
	std::stringstream ss;
	for(int i = 0; i < m_stream.size(); i++)
	{
	    std::string tt = m_stream.front();
	    ss << tt;
	    m_stream.push(tt);
	    m_stream.pop();
	}
	m_text->setString(ss.str());
	
}
void debug::setText(sf::Text* text){m_text = text;}
debug& debug::operator<<(const std::string& str)
{
	if(m_text==nullptr)
	{
		throw std::runtime_error("Text not initialized");
		return *this;
	}
	m_stream.push(str);	
	return *this;
}
debug& debug::operator<<(const float& str)
{
	if(m_text==nullptr)
	{
		throw std::runtime_error("Text not initialized");
		return *this;
	}
	m_stream.push(std::to_string(str));	
	return *this;
}
debug& debug::operator<<(const int& str)
{
	if(m_text==nullptr)
	{
		throw std::runtime_error("Text not initialized");
		return *this;
	}
	m_stream.push(std::to_string(str));	
	return *this;
}
debug& debug::operator<<(const vec2& v)
{
	if(m_text==nullptr)
	{
		throw std::runtime_error("Text not initialized");
		return *this;
	}
	m_stream.push("(" + std::to_string(v.x) + "," + std::to_string(v.y) + ")");
	return *this;
}

sf::Text* debug::m_text = nullptr;
std::queue<std::string> debug::m_stream;
//--------------DEBUG-END-----------
