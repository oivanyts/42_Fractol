NAME 		    = Fractol

SRC_DIR         := ./src/
OBJ_DIR 	    := ./obj/
INC_DIR 	    := ./inc/
LIB_DIR         := ./libft/
LIBMLX_DIR      := ./minilibx_macos/

LIBFT           := $(LIB_DIR)libft.a
LIBFT_INC       := $(LIB_DIR)includes/
LIBFT_FLAGS     := -lft -L $(LIB_DIR)

LIBMLX           := -lmlx
LIBMLX_INC       := $(LIBMLX_DIR)minilibx_macos/
LIBMLX_FLAGS     := $(LIBMLX) -L $(LIBMLX_DIR) -framework OpenGL -framework AppKit

SRC             += complex.c
SRC             += control.c
SRC             += control1.c
SRC             += fractol.c
SRC             += graphics.c
SRC             += main.c
SRC             += option_handler.c
SRC             += picture.c
SRC             += tread_handle.c

CC              := gcc

LINK_FLAGS      := $(LIB_FLAGS)

INCLUDES 	    := $(addprefix $(INC_DIR), libftprintf.h)

HEADER_FLAGS    := -I $(INC_DIR) -I $(LIBFT_INC) -I $(LIBMLX_INC)

FLAGS		    := -Wall -Wextra -Werror

OBJ 		    := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@gcc $(OBJ) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -o $(NAME) $(FLAGS)
	@echo "\033[m [$(NAME)] compiled successfully";

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(INC_DIR)
	@printf "compiling $@\n";
	@$(CC) -c $< -o $@ $(FLAGS) $(HEADER_FLAGS);

$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIB_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
