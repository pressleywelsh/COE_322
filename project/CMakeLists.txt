cmake_minimum_required( VERSION 3.20 )
project( climate VERSION 1.0 )

message( "Using sources: climate.cpp" )

add_executable( climate )
target_sources( climate PRIVATE climate.cpp )

target_compile_features( climate PRIVATE cxx_std_23 )

configure_file( GLB.Ts_clean.txt       GLB.Ts_clean.txt       COPYONLY )
configure_file( GLB.Ts+dSST_clean.txt  GLB.Ts+dSST_clean.txt  COPYONLY )

install( TARGETS climate DESTINATION . )
install(
  FILES
    GLB.Ts_clean.txt
    GLB.Ts+dSST_clean.txt
  DESTINATION .
)
