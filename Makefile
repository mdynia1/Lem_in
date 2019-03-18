#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdynia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 19:11:51 by mdynia            #+#    #+#              #
#    Updated: 2018/09/27 19:11:53 by mdynia           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			lem-in
FLAGS =			-Wall -Wextra -Werror

SRC_FILES =		validator_main.c \
				validator_links.c \
				validator_rooms.c \
				path_search.c \
				roads_activation.c \
				road_printer.c \
				data_removal.c \
				ft_lstcpy.c \
				main.c

OBJ_FILES =		$(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Library compilation..."
	@make -C libft
	@gcc -o $(NAME) $(OBJ_FILES) -L libft -lft
	@echo "Lem-in library is ready to be used!"
	
%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@ -I ~/.brew/include/SDL2/ -D_THREAD_SAFE

clean:
	@echo "All object files are removed!"
	@make clean -C libft
	@rm -f $(OBJ_FILES)

fclean:
	@echo "All object files and Lem-in are removed!"
	@make fclean -C libft
	@rm -f $(OBJ_FILES)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re