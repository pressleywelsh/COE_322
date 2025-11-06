cmake_minimum_required(VERSION 3.13)
project(hw10 VERSION 1.0 LANGUAGES CXX)

add_executable(hw10)
target_sources(hw10 PRIVATE hw10.cpp)
target_compile_features(hw10 PRIVATE cxx_std_17)
find_package(PkgConfig REQUIRED)
pkg_check_modules(OPTS REQUIRED cxxopts)
message(STATUS "cxxopts include dirs: ${OPTS_INCLUDE_DIRS}")

target_include_directories(hw10 PUBLIC ${OPTS_INCLUDE_DIRS})
install(TARGETS hw10 DESTINATION .)
