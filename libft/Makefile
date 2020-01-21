# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oivanyts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 13:27:43 by oivanyts          #+#    #+#              #
#    Updated: 2019/01/14 16:36:42 by oivanyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SRC_DIR		:= ./src/
OBJ_DIR 	:= ./obj/
INC_DIR 	:= ./includes/
LIB_DIR		:= ./lib/

CC		    := gcc

INCLUDES 	= $(addprefix $(INC_DIR), libft.h)

FLAGS		:= -Wall -Wextra -Werror

HEADER_FLAGS 	:= -I $(INC_DIR)

FUNCTIONS 	+= ft_atoi.c
FUNCTIONS 	+= ft_bzero.c
FUNCTIONS 	+= ft_countletter.c
FUNCTIONS 	+= ft_countwords.c
FUNCTIONS 	+= ft_isalnum.c
FUNCTIONS 	+= ft_isalpha.c
FUNCTIONS 	+= ft_isascii.c
FUNCTIONS 	+= ft_isdigit.c
FUNCTIONS 	+= ft_isprint.c
FUNCTIONS 	+= ft_isspace.c
FUNCTIONS 	+= ft_itoa_base.c
FUNCTIONS 	+= ft_itoa.c
FUNCTIONS 	+= ft_lstadd.c
FUNCTIONS 	+= ft_lstdel.c
FUNCTIONS 	+= ft_lstdelone.c
FUNCTIONS 	+= ft_lstiter.c
FUNCTIONS 	+= ft_lstmap.c
FUNCTIONS 	+= ft_lstnew.c
FUNCTIONS 	+= ft_lstaddback.c
FUNCTIONS 	+= ft_matrixalloc.c
FUNCTIONS 	+= ft_memalloc.c
FUNCTIONS 	+= ft_memccpy.c
FUNCTIONS 	+= ft_memchr.c
FUNCTIONS 	+= ft_memcmp.c
FUNCTIONS 	+= ft_memcpy.c
FUNCTIONS 	+= ft_memdel.c
FUNCTIONS 	+= ft_memmove.c
FUNCTIONS 	+= ft_memset.c
FUNCTIONS 	+= ft_putchar_fd.c
FUNCTIONS 	+= ft_putchar.c
FUNCTIONS 	+= ft_putendl_fd.c
FUNCTIONS 	+= ft_putendl.c
FUNCTIONS 	+= ft_putnbr_fd.c
FUNCTIONS 	+= ft_putnbr.c
FUNCTIONS 	+= ft_putstr_fd.c
FUNCTIONS 	+= ft_putstr.c
FUNCTIONS 	+= ft_strcat.c
FUNCTIONS 	+= ft_strchr.c
FUNCTIONS 	+= ft_strclr.c
FUNCTIONS 	+= ft_strcmp.c
FUNCTIONS 	+= ft_strcpy.c
FUNCTIONS 	+= ft_strdel.c
FUNCTIONS 	+= ft_strdup.c
FUNCTIONS 	+= ft_strequ.c
FUNCTIONS 	+= ft_striter.c
FUNCTIONS 	+= ft_striteri.c
FUNCTIONS 	+= ft_strjoin.c
FUNCTIONS 	+= ft_strlcat.c
FUNCTIONS 	+= ft_strlen.c
FUNCTIONS 	+= ft_strmap.c
FUNCTIONS 	+= ft_strmapi.c
FUNCTIONS 	+= ft_strncat.c
FUNCTIONS 	+= ft_strncmp.c
FUNCTIONS 	+= ft_strncpy.c
FUNCTIONS 	+= ft_strnequ.c
FUNCTIONS 	+= ft_strnew.c
FUNCTIONS 	+= ft_strnstr.c
FUNCTIONS 	+= ft_strrchr.c
FUNCTIONS 	+= ft_strsplit.c
FUNCTIONS 	+= ft_strstr.c
FUNCTIONS 	+= ft_strsub.c
FUNCTIONS 	+= ft_strtrim.c
FUNCTIONS 	+= ft_swap.c
FUNCTIONS 	+= ft_tolower.c
FUNCTIONS 	+= ft_toupper.c
FUNCTIONS 	+= get_next_line.c
FUNCTIONS 	+= ft_num_size.c
FUNCTIONS 	+= ft_lstaddhere.c
FUNCTIONS 	+= ft_atoi_hex.c
FUNCTIONS 	+= ft_swap_d.c
FUNCTIONS 	+= ft_array_print.c
FUNCTIONS 	+= printf.c
FUNCTIONS 	+= ft_itoa_prntf.c
FUNCTIONS 	+= ft_strnum_base.c
FUNCTIONS 	+= ft_itoa_double.c
FUNCTIONS 	+= ft_exp.c
FUNCTIONS 	+= ft_round_double.c
FUNCTIONS 	+= ft_charlen.c
FUNCTIONS 	+= ft_parcer_printf.c
FUNCTIONS 	+= form_num_char.c
FUNCTIONS 	+= ft_printbits_printf.c
FUNCTIONS 	+= ft_putchar_u.c
FUNCTIONS 	+= ft_putstr_u.c
FUNCTIONS 	+= ft_strlen_u.c
FUNCTIONS 	+= ft_strdup_u.c
FUNCTIONS 	+= ft_strndup_u.c
FUNCTIONS 	+= ft_color_input.c
FUNCTIONS 	+= ft_max_number.c
FUNCTIONS 	+= ft_printf_fd.c
FUNCTIONS 	+= ft_print_list.c

OBJ 		= $(addprefix $(OBJ_DIR), $(FUNCTIONS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@ar rc $(NAME) $(OBJ);
	@echo "\033[m [$(NAME)] compiled successfully";

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@printf "\033[01;48;05;22m ";
	@$(CC) -c $< -o $@ $(FLAGS) $(HEADER_FLAGS);

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "\033[01;48;05;160m destroyed [$(NAME)] \033[m"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
