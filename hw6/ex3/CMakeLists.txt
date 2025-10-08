cmake_minimum_required(VERSION 3.20)
project(primesbyclass VERSION 1.0 LANGUAGES CXX)

add_executable(primesbyclass)
target_sources(primesbyclass PRIVATE hw6ex3.cpp)
target_compile_features(primesbyclass PRIVATE cxx_std_23)

install(TARGETS primesbyclass DESTINATION .)
