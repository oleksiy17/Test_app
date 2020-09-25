cmake_minimum_required(VERSION 3.10)

set(LIB_NAME "LibGain")

project(${LIB_NAME})

add_library(${LIB_NAME} STATIC
	../../../lib/${LIB_NAME}/srcGain/gain.c)

target_include_directories(${LIB_NAME} PRIVATE ../../../lib/${LIB_NAME}/incGain)
