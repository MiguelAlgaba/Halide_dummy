project( Halide_dummy )

cmake_minimum_required( VERSION 2.8.7 )

# Place the binaries within the bin directory
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

# Specify the location of Halide's header files and libraries
set( Halide_DIR "" CACHE PATH "Halide root directory" )
if( NOT IS_DIRECTORY "${Halide_DIR}" )
  message( FATAL_ERROR "Halide_DIR not set" )
endif()
include_directories( "${Halide_DIR}/include" )
link_directories( "${Halide_DIR}/bin" )

add_subdirectory( examples )
