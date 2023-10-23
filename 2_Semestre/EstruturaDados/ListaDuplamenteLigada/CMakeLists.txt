cmake_minimum_required(VERSION 3.26)
project(ListaLigada C)

set(CMAKE_C_STANDARD 11)

add_executable(ListaLigada main.c
        ListaLigada.h
        ListaLigada.c)
