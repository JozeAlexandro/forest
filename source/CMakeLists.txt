cmake_minimum_required(VERSION 3.5)

project(forest LANGUAGES C)

set_property( TARGET PROPERTY C_STANDARD 17)

add_executable( forest
                main.c
                forest.c
                BST/src/BST.c)

include_directories( forest BST/h/ )

