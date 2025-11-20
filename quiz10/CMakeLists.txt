cmake_minimum_required( VERSION 3.20 )
project( hw5 VERSION 1.0 )

message( "Using sources: hw5.cpp" )
add_executable( hw5 )
target_sources( hw5 PRIVATE hw5.cpp )

target_compile_features( hw5 PRIVATE cxx_std_23 )
install( TARGETS hw5 DESTINATION . )
