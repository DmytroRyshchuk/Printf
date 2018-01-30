# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/25 18:35:26 by dryshchu          #+#    #+#              #
#    Updated: 2017/12/25 18:35:28 by dryshchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILES 		=	t_percent.c t_char.c t_unicode_char.c wchar.c \
				t_hex.c t_hex_upper.c hex_f1.c hex_f2.c hex_f3.c \
				checks.c checks1.c checks2.c checks3.c checks4.c \
				check_format.c check_exactly_format.c \
				t_string.c string_f1.c string_f2.c \
				t_unicode_string.c unicode_string_f1.c unicode_string_f2.c \
				t_octed.c t_octed_long.c octat_f1.c octat_f2.c \
				t_double.c t_upper_double.c \
				double_f1.c double_f2.c double_f3.c double_f4.c \
				t_unsigned_decimal.c t_unsigned_long.c \
				unsigned_decimal_f1.c unsigned_decimal_f2.c\
				t_pointer.c pointer_f1.c pointer_f2.c pointer_f3.c\
				ft_printf.c fill_by.c work_with.c \
				ft_atoi.c ft_itoa.c hex_itoa_base.c t_non_valid_spec.c \
				funcs1.c \
	 			ft_putchar.c ft_strcmp.c ft_strlen.c ft_strnew.c \

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

SRC_DIR		=	./src/
OBJ_DIR		= 	./object_files/
INC_DIR		=	./includes/

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

NO_COLOUR	=	\033[0m
BLUE		=	\033[3;36m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${BLUE}Compiling $(NAME) with $(FLAGS) flags ${NO_COLOUR}\n..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "${BLUE}Done!${NO_COLOUR}"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "${BLUE}Folder with object files has been removed.${NO_COLOUR}"

fclean: clean
	@/bin/rm -f .DS*
	@/bin/rm -f $(NAME)
	@echo "${BLUE}${NAME} has been removed.${NO_COLOUR}"

re: fclean all

.PHONY: all clean fclean re
	