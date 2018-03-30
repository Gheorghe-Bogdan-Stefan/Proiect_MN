cmake_minimum_required(VERSION 3.9)
project(NumericalMethods)

set(CMAKE_CXX_STANDARD 11)

add_executable(NumericalMethods main.cpp Cholesky.cpp Cholesky.h SolveCholesky.cpp SolveCholesky.h)