cmake_minimum_required( VERSION 3.20 )
project( pascal VERSION 1.0 )

message( "Using sources: hw7ex8.cpp" )
add_executable( pascal )
target_sources( pascal PRIVATE hw7ex8.cpp )

target_compile_features( pascal PRIVATE cxx_std_23 )
install( TARGETS pascal DESTINATION . )
