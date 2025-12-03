cmake_minimum_required( VERSION 3.20 )
project( hw13 VERSION 1.0 )

message( "Using sources: hw13.cpp" )
add_executable( hw13 )
target_sources( hw13 PRIVATE hw13.cpp )

target_compile_features( hw13 PRIVATE cxx_std_23 )

install( TARGETS hw13 DESTINATION . )
