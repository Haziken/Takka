cmake_minimum_required(VERSION 3.2)

set(PR_NAME TAKKACORE)

project(${PR_NAME})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE src/*.cpp)
file(GLOB_RECURSE INCLUDE include/*.h)

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