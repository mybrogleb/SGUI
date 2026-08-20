cmake_minimum_required(VERSION 3.28)
project(SGUI LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(SGUI 
	src/main.cpp
	src/Config.hpp
	src/Widget.hpp
	src/TextBuffer.hpp
	src/TextDisplay.hpp
	src/Button.hpp
	src/SGUI.hpp
	
)

target_compile_definitions(SGUI PRIVATE SFML_STATIC)
target_compile_features(SGUI PRIVATE cxx_std_17)
target_link_libraries(SGUI PRIVATE SFML::Graphics SFML::Audio SFML::Window SFML::System)

add_custom_command(TARGET SGUI POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:SGUI>/assets)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SGUI)
