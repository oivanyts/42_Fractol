cmake_minimum_required(VERSION 3.14)
project(Fractol C)

set(CMAKE_C_STANDARD 11)
#set(CMAKE_C_FLAGS "-Wextra -Werror -Wall")

link_directories(minilibx_macos)    #лінковка млх
add_subdirectory(./libft)

AUX_SOURCE_DIRECTORY(./src SOURCE_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} inc/main.h src/handle_opt.c src/graphics.c inc/graphics.h src/picture.c inc/picture.h)


target_include_directories(${PROJECT_NAME} PUBLIC
        minilibx_macos
        inc)

target_link_libraries(${PROJECT_NAME} LIBFT)
target_link_libraries(${PROJECT_NAME} -lmlx "-framework OpenGL" "-framework AppKit")
target_link_libraries(${PROJECT_NAME} pthread)
