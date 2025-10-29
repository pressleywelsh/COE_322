cmake_minimum_required( VERSION 3.20 )
project( hw9 VERSION 1.0 )

message( "Using sources: hw9.cpp" )
add_executable( hw9 )
target_sources( hw9 PRIVATE hw9.cpp )

# Use C++23 if available; if your compiler is older, change to cxx_std_17
target_compile_features( hw9 PRIVATE cxx_std_23 )

install( TARGETS hw9 DESTINATION . )
