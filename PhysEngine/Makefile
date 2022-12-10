#all: clean
all: build

OBJS=PhysEngine.o
LIB_NAME=PhysEngine.a
#HEADERS=
#SRC_PATH=src/
INCLUDE_PATH=
#-I../core/include/ \
             #-Iinclude/

#vpath % $(SRC_PATH)

build: $(LIB_NAME)


$(LIB_NAME): $(OBJS)
	ar rs -o $(LIB_NAME) $(OBJS)

PhysEngine.o: PhysEngine.cpp
	$(CXX) -c $< $(INCLUDE_PATH)




clean:
	rm -f $(OBJS)
	rm -f $(LIB_NAME)