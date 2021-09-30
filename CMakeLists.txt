cmake_minimum_required(VERSION 3.10)

get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${DIR_NAME})

find_package(fpmas 1.2 REQUIRED)

add_executable(${PROJECT_NAME}
	main.cpp
	src/agents.cpp)
include_directories(include)

target_link_libraries(${PROJECT_NAME} fpmas::fpmas)

