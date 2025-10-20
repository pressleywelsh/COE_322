cmake_minimum_required(VERSION 3.12)
project(hw8 VERSION 1.0 DESCRIPTION "C++ Pascal triangle with cxxopts")

add_executable(hw8 hw8.cpp)
target_compile_features(hw8 PRIVATE cxx_std_17)

# If TACC provides cxxopts include path, use it
if(DEFINED ENV{TACC_CXXOPTS_INC})
  message(STATUS "Using TACC_CXXOPTS_INC = $ENV{TACC_CXXOPTS_INC}")
  target_include_directories(hw8 PUBLIC $ENV{TACC_CXXOPTS_INC})
else()
  message(WARNING "TACC_CXXOPTS_INC not set. You may need -DOPTS_INCLUDE_DIRS=/path/to/cxxopts")
endif()

install(TARGETS hw8 DESTINATION .)
