###############################################################################
## file globbing ##############################################################
###############################################################################

# these instructions search the directory tree when cmake is
# invoked and put all files that match the pattern in the variables 
# `sources`
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true src/MarlinHelp/*/*.cpp)
set(SOURCES ${SOURCES})

###############################################################################
## target definitions #########################################################
###############################################################################

add_library(${CMAKE_PROJECT_NAME} SHARED ${SOURCES})

# just for example add some compiler flags
target_compile_options(
  ${CMAKE_PROJECT_NAME} PUBLIC -std=c++1y 
  # Compiler warning/error flags
  -Wall -Wfloat-conversion -Wextra -Wunreachable-code -Wuninitialized 
  -pedantic-errors -Wold-style-cast -Wno-error=unused-variable
  -Wfloat-equal
  # Compiler optimisation
  -O3
)

###############################################################################
## dependencies ###############################################################
###############################################################################

# Link the needed libraries so that its compiled code can be used
target_link_libraries(
  ${CMAKE_PROJECT_NAME} PUBLIC 
  ${SPDLOG_LIB} # Logging
)

###############################################################################
## packaging ##################################################################
###############################################################################

# Install library
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION lib/${CMAKE_PROJECT_NAME})

# Install library headers
install(DIRECTORY include/MarlinHelp DESTINATION include)