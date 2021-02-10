cmake_minimum_required(VERSION 3.17)
project(cum3d C)


#include_directories("mlx_mms")
#target_link_libraries(libmlx "mlx_mms/libmlx.dylib")

#link_directories(F:\\C++\\ExternalLibraries\\GLFW\\lib-mingw-w64)
#include_directories(F:\\C++\\ExternalLibraries\\GLFW\\include)

#add_library(libmlx.dylib SHARED IMPORTED)
#target_link_libraries(libmlx.dylib)
#target_link_libraries(texture_module -L${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror -L. lft")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit -L. -lmlx")
#add_library(libmlx.dylib)
add_executable(cum3d main.c
        parser_params.c
        parser_map.c
        functions.c
        ray.c
        libft/ft_lstsize.c
        libft/ft_strtrim.c
        libft/ft_strdup.c
        libft/ft_calloc.c
        libft/ft_bzero.c
        libft/ft_atoi.c
        libft/get_next_line.c
        libft/ft_itoa.c
        libft/ft_lstadd_back.c
        libft/ft_lstnew.c
        libft/ft_strlen.c
        )

#add_executable(cum3d main.c parcer.c)

find_library(LIBFT mlx_mms lib)
#target_link_libraries(cum3d INK_PUBLIC ${TEST_LIBRARY})

#add_library(libmlx.dylib SHARED IMPORTED)
#target_link_libraries(libmlx.dylib)
#target_link_libraries(texture_module -L${PROJECT_SOURCE_DIR}/lib)

#
#./mlx_mms/libmlx.dylib



#target_link_libraries(Hatsudouki_core glfw3)