cmake_minimum_required(VERSION 3.19)
project(encoding C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(ERLANG_ROOT_DIR /usr/local/Cellar/erlang/23.2.5/lib/erlang)
include_directories(${ERLANG_ROOT_DIR}/usr/include/)
add_library(encoding_nif SHARED encoding_nif.c)
set_target_properties(encoding_nif
	PROPERTIES
	SUFFIX .so)
target_link_options(encoding_nif PUBLIC -undefined dynamic_lookup -shared)
