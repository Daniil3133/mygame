cmake_minimum_required(VERSION 3.16)


add_library(
	Core SHARED
	core.cpp
	./AbstractController.cpp
	./debug.cpp)


set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

#add_subdirectory(
#	../myGUI)

#target_link_libraries(
#	Core
#	PUBLIC myGUI)

target_link_libraries(
	Core PUBLIC
	sfml-graphics)

target_include_directories(
	Core PUBLIC
	../include/Core
	../include)

