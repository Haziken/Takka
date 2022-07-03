cmake_minimum_required(VERSION 3.2)

set(PR_NAME TAKKACORE)

project(${PR_NAME})

set(INCLUDE include/Application.h)
set(SOURCE src/Application.cpp)

add_library(${PR_NAME} STATIC ${INCLUDE} ${SOURCE})
target_include_directories(${PR_NAME} PUBLIC include)

add_subdirectory(externals/assimp)
target_link_libraries(${PR_NAME} PRIVATE assimp)
target_include_directories(${PR_NAME} PRIVATE externals/assimp/include)

add_subdirectory(externals/glad)
target_link_libraries(${PR_NAME} PRIVATE glad)
target_include_directories(${PR_NAME} PRIVATE externals/glad/include)

add_subdirectory(externals/glfw)
target_link_libraries(${PR_NAME} PRIVATE glfw)
target_include_directories(${PR_NAME} PRIVATE externals/glfw/include)

add_subdirectory(externals/glm)
target_link_libraries(${PR_NAME} PRIVATE glm::glm)
target_include_directories(${PR_NAME} PRIVATE externals/glm/glm)

add_subdirectory(externals/soil)
target_link_libraries(${PR_NAME} PRIVATE soil)
target_include_directories(${PR_NAME} PRIVATE externals/soil/include)