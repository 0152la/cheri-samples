cmake_minimum_required(VERSION 3.13)
project(al2510CheriSamples)
set(CMAKE_C_STANDARD 11)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# CHERI paths setup
set(CHERIBASE $ENV{HOME}/cheri/)
set(cheri_target "morello" CACHE STRING "Underlying CHERI architecture")
if (${cheri_target} STREQUAL "morello")
	set(CMAKE_C_COMPILER ${CHERIBASE}/output/morello-sdk/bin/clang)
	set(compile_opts --config cheribsd-morello-purecap.cfg)
elseif(${cheri_target} STREQUAL "riscv")
	set(CMAKE_C_COMPILER ${CHERIBASE}/output/sdk/bin/clang)
	set(compile_opts --config cheribsd-riscv64-purecap.cfg)
else()
	message(FATAL_ERROR "Given architecture ${cheri_target} not found.")
endif()

set(sources 
	${SRC_DIR}/simple.c
	${SRC_DIR}/simple_wrong.c
	${SRC_DIR}/derived.c
	${SRC_DIR}/derived_wrong.c
	)

foreach(src_file ${sources})
	get_filename_component(exec_name ${src_file} NAME_WE)
	add_executable(${exec_name} ${src_file})
	target_compile_features(${exec_name} PUBLIC c_std_11)
	target_compile_options(${exec_name} PUBLIC ${compile_opts} PRIVATE -Wall)
	target_link_options(${exec_name} PUBLIC -fuse-ld=lld ${compile_opts})
endforeach(src_file ${SRC_DIR})
