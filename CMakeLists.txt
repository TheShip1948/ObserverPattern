cmake_minimum_required(VERSION 2.6)
project(ObserverPattern)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(cotire)

# Build Targets 
add_executable(observer_pattern main.cpp observer.h)
add_library(observer_pattern_static STATIC main.cpp observer.h) 
add_library(observer_pattern_dynamic SHARED main.cpp observer.h)

# Speed up compilation using cotire 
cotire(observer_pattern)
cotire(observer_pattern_static)
cotire(observer_pattern_dynamic)

# Install Targets 
install(TARGETS observer_pattern DESTINATION ./Install)
install(TARGETS	 observer_pattern_static DESTINATION ./Install/lib) 
install(TARGETS observer_pattern_dynamic DESTINATION ./Install/so) 
