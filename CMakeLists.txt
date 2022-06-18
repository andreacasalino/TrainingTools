cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

option(LIB_OPT "Compile shared libraries (ON) or static (OFF)" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/MakeLibrary.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/FetchEigen.cmake)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

project(TrainingTools)
add_subdirectory(src)

option(BUILD_TrainingTools_TESTS "" OFF)
if(BUILD_TrainingTools_TESTS)
	project(TrainingTools-Tests)
    add_subdirectory(tests)
endif()
