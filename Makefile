.PHONY: clean

all: build
#all: clean
TARGET=proga
OBJS= main.o \
	debug.o \
	transform.o \
	core.a \
	PhysEngine.a \
    RenderEngine.a \
    mygui.a

MYLIBS=corea PhysEnginea RenderEnginea myguia

INCLUDE_PATH= \
    
    

LIBS=-lsfml-graphics -lsfml-window -lsfml-system \


build: $(MYLIBS) $(TARGET)


$(TARGET):$(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)


main.o: main.cpp
	$(CXX) -c $< $(INCLUDE_PATH)


ObjectManager.o: ObjectManager.cpp
	$(CXX) -c $< $(INCLUDE_PATH)


transform.o: transform.cpp
	$(CXX) -c $< $(INCLUDE_PATH)

corea:
	cd Core; make
	cp Core/core.a .

PhysEnginea:
	cd PhysEngine; make
	cp PhysEngine/PhysEngine.a .


RenderEnginea:
	cd RenderEngine; make
	cp RenderEngine/RenderEngine.a .


myguia:
	cd myGUI; make
	cp myGUI/mygui.a .
	
clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

cleanall: clean
	cd Core; make clean
	cd RenderEngine; make clean
	cd PhysEngine; make clean
	cd myGUI; make clean



