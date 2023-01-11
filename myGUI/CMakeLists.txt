cmake_minimum_required(VERSION 3.16)


add_library(
	myGUI SHARED
	./widget.cpp
	./RenderWidget.cpp
	./button.cpp
	)


set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

#add_subdirectory(
#	../myGUI)

#target_link_libraries(
#	Core
#	PUBLIC myGUI)

target_link_libraries(
	myGUI PUBLIC
	sfml-graphics)

target_include_directories(
	myGUI PUBLIC
	../include/Core
	../include)

