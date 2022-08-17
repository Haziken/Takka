cmake_minimum_required(VERSION 3.2)

set(PR_NAME TAKKA-EDITOR)

project(${PR_NAME})

set(SOURCE main.cpp)

add_executable(${PR_NAME} main.cpp)

target_link_libraries(${PR_NAME} PUBLIC TAKKACORE)
target_include_directories(${PR_NAME} PUBLIC ../TakkaEngineCore/include)

target_include_directories(${PR_NAME} PUBLIC externals/ImGUI)