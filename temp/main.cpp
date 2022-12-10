#include <SFML/Graphics.hpp>
#include <cmath>

#include "debug.h"
#include "vec2.h"
#include "transform.h"
#include "Object.h"
#include "PhysEngine/PhysEngine.h"
#include "ObjectManager.h"
#include "shape2d.cpp"

namespace bb{
class bounding_box
{
public:

};

class AABB:public bounding_box
{
public:

};

bool test(bounding_box* a, bounding_box* b)
{
	
}
}

class wall:public Object, public physObject
{
	mutable sf::RectangleShape m_shape;
	mutable Transform m_transform;
public:
	wall(const vec2& pos, const vec2& sz)
	{
		m_transform.setpos(pos);
		m_transform.setsize(sz);
		m_shape.setPosition(m_transform.getpos().vecsf());
		m_shape.setSize(m_transform.getsize().vecsf());
		m_shape.setFillColor(sf::Color::Blue);
	}
	void draw(sf::RenderTarget& t,sf::RenderStates)const
	{
		m_shape.setPosition(m_transform.getpos().vecsf());
		m_shape.setSize(m_transform.getsize().vecsf());
		t.draw(m_shape);
	}
	Transform* transform(){return &m_transform;}
	AABB getaabb()
	{
		vec2 ps = m_transform.getpos();
		vec2 sz_2 = m_transform.getsize()/2;
		return {ps - sz_2, ps + sz_2};
	}
};

class obj:public Object, public physObject
{
public:
	Transform m_transform;
	sf::CircleShape m_shape;
	vec2 m_centerOfMass;
	float m_radius;
	float m_elasticy;
	bool isforced=false;
public:
	void setpos(vec2 v)
	{
		m_transform.setpos(v);
		m_shape.setPosition(v.vecsf());
	}
	void setradius(float r)
	{
		m_radius = r;
		m_shape.setRadius(r);
	}
	void physupdate(int dt)
	{
		m_accel = m_sumforces / m_mass;
		m_vel += m_accel * dt;
		m_transform.translate(m_vel * dt);
		m_shape.setPosition(m_transform.getpos().vecsf());
		
		if(!isforced){isforced = true; m_sumforces ={0,0};}
	}
	void update(int dt)
	{
	}
	void draw(sf::RenderTarget& t,sf::RenderStates)const
	{
		t.draw(m_shape);
	}
	BS getbs()
	{
		return BS(m_transform.getpos(),m_radius);
	}
	Transform* transform(){return &m_transform;}
};


//--------------MAIN------------
sf::Text TextDebug;
sf::Font font;
int main()
{
	sf::RenderWindow rw(sf::VideoMode(1080,2160),"");
	
	bool isRunning=true;
	
	font.loadFromFile("/system/fonts/DroidSansMono.ttf");
	TextDebug.setFont(font);
	TextDebug.setPosition({300,100});
	TextDebug.setCharacterSize(30);
	TextDebug.setFillColor(sf::Color::Red);
	debug().setText(TextDebug);
	debug()<<"Start";
	
	PhysEngine phEngine;
	phEngine.setgravit(false);
	ObjectManager objmanager;
	
	wall walls[4]={{{100,100},{20,1820}}
				,{{960,100},{20,1820}}
				,{{120,100},{840,20}}
				,{{120,1900},{840,20}}};
	for(auto& j:walls)
	{
		phEngine.addObject(&j);
		objmanager.addObject(&j);
	}
	
	obj obj1;
	obj1.m_vel = {0,0};
	obj1.m_elasticy = 0.8f;
	obj1.m_mass = 10;
	obj1.m_sumforces = {2,0};
	obj1.setpos({100,1000});
	obj1.setradius(30);
	phEngine.addObject(&obj1);
	objmanager.addObject(&obj1);
	
	obj obj2;
	obj2.m_vel = {0,0};
	obj2.m_elasticy = 0.8f;
	obj2.m_mass = 10;
	obj2.m_sumforces = {-2,0};
	obj2.setpos({800,1000});
	obj2.setradius(30);
	phEngine.addObject(&obj2);
	objmanager.addObject(&obj2);
	
	sf::Clock clock;
	int max_fps = 30;
	const float DELTA_TIME = 1000.0 / max_fps;
	
	//bool isfirst=false;
	int dt = 30;
	while(isRunning)
	{
		//if(isfirst) {isfirst = false; continue;}
		debug()<<"vel=" << obj1.m_vel << "\n";
		static int sec = 0;sec += dt;
		static int FPS=0;
		if(sec > 500)
		{
			sec = 0;
			FPS = 1000.f/dt;
		}
		debug() << FPS << "  " << dt << "\n";
		if(dt < DELTA_TIME)
		{
			sf::sleep(sf::milliseconds(DELTA_TIME-dt));
		}
		sf::Event e;
		while(rw.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
			{
				isRunning = false;
			}else
			if(e.type == sf::Event::TouchBegan)
			{
				static bool b = true;
				phEngine.setgravit(b);
				b=!b;
			}
		}
		debug().update();
		phEngine.update(3);
		objmanager.update(3);
		rw.clear();
		objmanager.draw(rw);
		rw.draw(TextDebug);
		rw.display();
		dt = clock.restart().asMilliseconds();
	}
	return 0;
}

//--------------MAIN-END-----------

/*point p({300,300});
	p.transform()->setsize({100,100});
	p.setgravit(true);
	objmanager.addObject(&p);
	phEngine.addObject(&p);
	
	point p1,p2;
	p1.transform()->setpos({100,700});
	p2.transform()->setpos({500,1400});
	line line1(p1,p2);
	line1.setgravit(false);
	objmanager.addObject(&line1);
	phEngine.addObject(&line1);
	
	
	rectangle rect({100,1400},{1000,1450});
	rect.setgravit(false);
	objmanager.addObject(&rect);
	phEngine.addObject(&rect);*/