cmake_minimum_required(VERSION 3.2)

set(${PR_NAME} TAKKA-ENGINE)

add_subdirectory(TakkaEngineCore)
add_subdirectory(TakkaEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT TAKKA-EDITOR)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

if(UNIX)
    add_compile_options(-Wall -Wextra -pedantic -Werror -fpermissive -Wint-to-pointer-cast)
endif()