cmake_minimum_required(VERSION 2.6)
project(ObserverPattern)
add_executable(observer_pattern main.cpp observer.h)
install(TARGETS observer_pattern DESTINATION /Install) 
