cmake_minimum_required(VERSION 3.2)

project(glad)

add_library(glad STATIC include src)
target_include_directories(glad PUBLIC include)