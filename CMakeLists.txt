cmake_minimum_required(VERSION 2.8)

project(CQUADPACK C)

# add_directory(src)
include_directories(include)

FILE(GLOB source_files src/*.c)

add_library(cquadpack STATIC ${source_files})
# add_subdirectory(src)