cmake_minimum_required(VERSION 3.15)
project(CodeWillingQuestions)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(MatrixLib)
add_subdirectory(WordFrequencyLib)
add_executable(CodeWillingQuestions main.cpp )
target_link_libraries(CodeWillingQuestions Matrix_Core WordFreq_Core)