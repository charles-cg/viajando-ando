cmake_minimum_required(VERSION 3.29)
project(viajando-ando)

set(CMAKE_CXX_STANDARD 20)

add_executable(viajando-ando SP/main_func.cpp
        SP/Reserva.h
        SP/Flights.h)