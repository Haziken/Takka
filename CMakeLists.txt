cmake_minimum_required(VERSION 3.2)

set(${PR_NAME} TAKKA-ENGINE)

add_subdirectory(TakkaEngineCore)
add_subdirectory(TakkaEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT TAKKA-EDITOR)