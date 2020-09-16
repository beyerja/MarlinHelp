cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

project(MarlinHelp) # Project name

# External libraries
find_library( SPDLOG_LIB spdlog HINTS external/spdlog/build )

# Common packages
set( CMAKE_PREFIX_PATH 
    ${ILC_HOME}/Marlin/v01-17-01;
    ${ILC_HOME}/lcio/v02-15-01;
CACHE PATH "CMAKE_PREFIX_PATH" FORCE )

# Common packages
find_package( ROOT 6.16 REQUIRED ) 
include_directories( SYSTEM ${ROOT_INCLUDE_DIRS} )
link_libraries( ${ROOT_LIBRARIES} )
add_definitions( ${ROOT_DEFINITIONS} )

# Header files that can be included using #include
include_directories(
  source/MarlinHelp/include
  external/spdlog/include
)

# Install in local folder instead of system
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

# Make sure the shared library of MarlinHelp is found
set(CMAKE_INSTALL_RPATH ${CMAKE_SOURCE_DIR}/lib/${CMAKE_PROJECT_NAME})
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Code subdirectories with own CMakelists
add_subdirectory(source/MarlinHelp)
add_subdirectory(source/UnitTests)
add_subdirectory(external/googletest)

# Package name and version
set(CPACK_PACKAGE_NAME "Helpers")
set(CPACK_PACKAGE_VERSION "1.0.0")

# we don't want to split our program up into several things
set(CPACK_MONOLITHIC_INSTALL 1)

# This must be last
include(CPack)
