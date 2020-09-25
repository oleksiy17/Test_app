cmake_minimum_required(VERSION 3.12)

set(PR_NAME "FileCopy")

project(${PR_NAME})

add_executable(${PR_NAME}
	../../src/main.c
	../../src/task1.c
	../../src/getopt.c)

target_link_libraries(${PR_NAME} PRIVATE LibGain)

target_include_directories(${PR_NAME} PRIVATE ../../include
			../../lib/LibGain/incGain
			../../lib/LibGenerator/incGenerator)
			
	
if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()