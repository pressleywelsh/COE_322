cmake_minimum_required( VERSION 3.12 )
project( quadtests
  DESCRIPTION "C++ programs for Catch2 testing"
  VERSION 1.0 )

add_executable( quadtests )
target_sources( quadtests PRIVATE quadtest.cpp quadlib.cpp quadlib.hpp )
target_compile_features( quadtests PRIVATE cxx_std_23 )

find_package( PkgConfig REQUIRED )
pkg_check_modules( CATCH2 REQUIRED catch2-with-main )
target_include_directories(
	quadtests PUBLIC
	${CATCH2_INCLUDE_DIRS}
	)
target_link_directories(
	quadtests PUBLIC
	${CATCH2_LIBRARY_DIRS}
	)
target_link_libraries(
	quadtests PUBLIC
	${CATCH2_LIBRARIES}
	)

install( TARGETS quadtests DESTINATION . )
