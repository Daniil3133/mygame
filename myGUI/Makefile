#all: clean
all: build

OBJS=RenderWidget.o widget.o button.o
LIB_NAME=mygui.a
#HEADERS=
#SRC_PATH=src/
INCLUDE_PATH=
#-I../core/include/ \
             #-Iinclude/

#vpath % $(SRC_PATH)

build: $(LIB_NAME)


$(LIB_NAME): $(OBJS)
	ar rs -o $(LIB_NAME) $(OBJS)


RenderWidget.o: RenderWidget.cpp
	$(CXX) -c $< $(INCLUDE_PATH)

button.o: button.cpp
	$(CXX) -c $< $(INCLUDE_PATH)

widget.o: widget.cpp
	$(CXX) -c $< $(INCLUDE_PATH)


clean:
	rm -f $(OBJS)
	rm -f $(LIB_NAME)