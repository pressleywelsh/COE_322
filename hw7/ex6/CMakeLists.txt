cmake_minimum_required( VERSION 3.20 )
project( hw7ex6 VERSION 1.0 )

message( "Using sources: hw7ex6.cpp" )
add_executable( hw7ex6 )
target_sources( hw7ex6 PRIVATE hw7ex6.cpp )

target_compile_features( hw7ex6 PRIVATE cxx_std_23 )
install( TARGETS hw7ex6 DESTINATION . )
