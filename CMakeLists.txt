cmake_minimum_required(VERSION 3.21)
project(HideComments VERSION 1.0.0 LANGUAGES CXX)

add_library(HideComments SHARED src/HideComments.cpp)
set_target_properties(HideComments PROPERTIES PREFIX "")
set_target_properties(HideComments PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON)
set(GEODE_LINK_SOURCE ON)

setup_geode_mod(HideComments DONT_INSTALL)
