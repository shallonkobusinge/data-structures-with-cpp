cmake_minimum_required(VERSION 3.21)
project(VIRTUAL_FUNCTIONS)

set(CMAKE_CXX_STANDARD 14)

add_executable(VIRTUAL_FUNCTIONS main.cpp Sale.h MailedSale.h DiscountSale.h Animal.cpp)
