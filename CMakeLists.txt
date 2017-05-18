#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

# Enable C++ 11
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project("LoveBrains")

# Set version information in a config.h file
set(LoveBrains_VERSION_MAJOR 1)
set(LoveBrains_VERSION_MINOR 0)
include_directories("${PROJECT_BINARY_DIR}")

# Addings sources to project
set(SOURCES_DIR src/)
set(HEADERS_DIR include/)
set(LIB_SOURCES_DIR lib/GANNEngine/src/)
set(LIB_HEADERS_DIR lib/GANNEngine/include/)

include_directories(${HEADERS_DIR} ${LIB_HEADERS_DIR})
set(SOURCES	${SOURCES_DIR}/main.cc
		${SOURCES_DIR}/App/app.cc
		${SOURCES_DIR}/App/app_exception.cc
		${SOURCES_DIR}/App/config_getter.cc
		${SOURCES_DIR}/App/config_manager.cc
		${SOURCES_DIR}/Graphics/environment.cc
		${SOURCES_DIR}/Graphics/factory_object.cc
		${SOURCES_DIR}/Graphics/physics.cc
		${SOURCES_DIR}/Plugin/plugin_exception.cc
		${SOURCES_DIR}/Plugin/plugin_manager.cc
		${SOURCES_DIR}/Simulator/simulator.cc
		${SOURCES_DIR}/Simulator/simulator_config.cc
		${SOURCES_DIR}/Simulator/simulator_exception.cc)

IF (WIN32)
  set(SOURCES ${SOURCES} ${SOURCES_DIR}/compatibility/dlfcn.cc)
ENDIF()

# Define sources and executable
set(EXECUTABLE_NAME "lovebrains")
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/GANNEngine/build/libGANNEngine.a)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
