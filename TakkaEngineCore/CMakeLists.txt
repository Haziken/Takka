cmake_minimum_required(VERSION 3.2)

set(PR_NAME TAKKACORE)

project(${PR_NAME})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE 
	include/Application.h
	include/Utils.h
	include/Window.h
	include/Video/Array.h
	include/Video/Buffer.h
	include/Video/VBO.h
	include/Video/EBO.h
	include/Video/VAO.h
	include/Shader.h
	include/Camera.h)

set(SOURCE 
	src/Application.cpp
	src/Window.cpp
	src/Video/Array.cpp
	src/Video/Buffer.cpp
	src/Video/VBO.cpp
	src/Video/EBO.cpp
	src/Video/VAO.cpp
	src/Shader.cpp
	src/Camera.cpp)

add_library(${PR_NAME} STATIC ${INCLUDE} ${SOURCE})
target_include_directories(${PR_NAME} PUBLIC INCLUDE)

add_subdirectory(externals/assimp)
target_link_libraries(${PR_NAME} PRIVATE assimp)
target_include_directories(${PR_NAME} PUBLIC externals/assimp/include)

add_subdirectory(externals/glad)
target_link_libraries(${PR_NAME} PRIVATE glad)
target_include_directories(${PR_NAME} PUBLIC externals/glad/include)

add_subdirectory(externals/glfw)
target_link_libraries(${PR_NAME} PRIVATE glfw)
target_include_directories(${PR_NAME} PUBLIC externals/glfw/include)

add_subdirectory(externals/glm)
target_link_libraries(${PR_NAME} PRIVATE glm::glm)
target_include_directories(${PR_NAME} PUBLIC externals/glm/glm)


target_include_directories(${PR_NAME} PUBLIC externals/stb)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})