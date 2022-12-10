#all: clean
all: build

OBJS=AbstractController.o core.o debug.o
LIB_NAME=core.a
#HEADERS=
#SRC_PATH=src/
INCLUDE_PATH= \
-I../ 
             #-Iinclude/

#vpath % $(SRC_PATH)

build: $(LIB_NAME)


$(LIB_NAME): $(OBJS)
	ar rs -o $(LIB_NAME) $(OBJS)

core.o: core.cpp
	$(CXX) -c $< $(INCLUDE_PATH)

AbstractController.o: AbstractController.cpp
	$(CXX) -c $< $(INCLUDE_PATH)



debug.o: debug.cpp
	$(CXX) -c $< $(INCLUDE_PATH)


clean:
	rm -f $(OBJS)
	rm -f $(LIB_NAME)