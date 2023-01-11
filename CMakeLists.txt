cmake_minimum_required(VERSION 3.16)


project(mygame)


add_executable(
	${PROJECT_NAME}
	main.cpp)


set( CMAKE_EXPORT_COMPILE_COMMANDS ON )



target_link_directories(
	${PROJECT_NAME} PUBLIC
	./Core
	./myGUI
)

target_link_libraries(
	${PROJECT_NAME} PUBLIC
	Core
	myGUI
)

target_include_directories(
	${PROJECT_NAME} PUBLIC
	./include)



