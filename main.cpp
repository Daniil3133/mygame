

#include <Core/Core.h>
#include <myGUI/RenderWidget.h>

/*
class Object: public sf::Drawable
{
    std::map<std::string, IComponent*> m_components;
public:
    Object(){}
    template<typename T>
    Component<T>* addComponent()
    {
        auto comp = new Component<T>();
        m_components[Component<T>::name()] = comp;
       // debug()<<Component<T>::name()<<"\n";
        return comp;
    }
    template<typename T>
    inline constexpr Component<T>* component(){return (Component<T>*)m_components[Component<T>::name()];}
    template<typename T>
    inline constexpr Component<T>* component()const{return (Component<T>*)m_components[Component<T>::name()];}
};

class CircShape:public Object
{
    Component<Transform>* tr;
public:
	CircShape(sf::Vector2f pos, int r): ::Object()
	{
	    tr = addComponent<Transform>();
        addComponent<PhysEngine::Object>();
	    component<Transform>()->setPos({pos.x,pos.y});
		circ.setRadius(r);
	}
	void draw(sf::RenderTarget& t, sf::RenderStates st)const
	{
	    //auto transform = component<Transform>();
	    st.transform.translate(tr->pos().vecsf());
	    
		t.draw(circ,st);
	}
	void update(float dt)
	{
	    component<PhysEngine::Object>()->update(dt);
	    //debug()<< tr->pos().vecsf()<<"\n";
	}
public:
	mutable sf::CircleShape circ;
};
*/

int main()
{
	//sf::RenderWindow rw(sf::VideoMode(1080,2160),"");
	
    auto core = Core::Core::Instance();
    core.RenderWidget()->init();
    core.RenderWidget()->setTitle("myGame");
    core.RenderWidget()->setSize(100,100);
    //core.RenderWidget()->show();

	/*font.loadFromFile("/system/fonts/DroidSansMono.ttf");
	TextDebug.setFont(font);
	TextDebug.setPosition({300,100});
	TextDebug.setCharacterSize(30);
	TextDebug.setFillColor(sf::Color::Red);
	auto dbg = new debug;
	debug().setText(&TextDebug);

	
	debug()<<"Start\n";*/
	//CircShape shp1({500,200},50);
	//bool isRunning = true;
	
	
	//PhysEngine::PhysEngine pe;
	//pe.addObj(shp1.component<PhysEngine::Object>());
	
	
	
	/*.myGUI::button btn;
	btn.setPos({400,1000});
	btn.show();
	while(isRunning)
	{
		sf::Event e;
		while(rw.pollEvent(e))
		{
		}
		//btn.update();
		//pe.update();
		//rw.clear();
		//rw.draw(shp1);
		//debug().update();
		//rw.draw(TextDebug);
		//btn.draw(rw);
		//rw.display();
	}*/
	int res = core.exec();
	return res;
}
