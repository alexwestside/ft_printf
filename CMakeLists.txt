cmake_minimum_required(VERSION 3.6)
project(ft_printf_c)

set(CMAKE_C_FLAGS "-std=c99")

set(SOURCE_FILES main.c ft_printf.c ft_printf.h libft.h flags.c arr_point.c func.c sub_func.c)

add_executable(ft_printf_c ${SOURCE_FILES} ft_printf.h)

target_link_libraries(ft_printf_c ${CMAKE_SOURCE_DIR}/libft/libft.a)