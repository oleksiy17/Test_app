cmake_minimum_required(VERSION 3.12)

set(LIB_NAME "LibGenerator")

project(${LIB_NAME})

add_library(${LIB_NAME} STATIC
	../../../lib/${LIB_NAME}/srcGenerator/generator.c)

target_include_directories(${LIB_NAME} PRIVATE ../../../lib/${LIB_NAME}/incGenerator)
