#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdynia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 20:43:09 by mdynia            #+#    #+#              #
#    Updated: 2017/11/20 20:43:25 by mdynia           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC =	ft_bzero.c      \
		ft_memchr.c		\
		ft_memcpy.c		\
		ft_memset.c		\
		ft_memccpy.c    \
		ft_memmove.c    \
		ft_memcmp.c     \
		ft_strlen.c     \
		ft_strdup.c     \
		ft_strcpy.c     \
		ft_strncpy.c    \
		ft_strcat.c     \
		ft_strncat.c    \
		ft_strlcat.c    \
		ft_strchr.c     \
		ft_strrchr.c    \
		ft_strstr.c     \
		ft_strnstr.c    \
		ft_strcmp.c     \
		ft_isalpha.c    \
		ft_isdigit.c    \
		ft_isalnum.c    \
		ft_isascii.c    \
		ft_isprint.c    \
		ft_toupper.c    \
		ft_tolower.c    \
		ft_atoi.c       \
		ft_memalloc.c   \
		ft_memdel.c     \
		ft_strnew.c     \
		ft_strdel.c     \
		ft_strclr.c 	\
		ft_striter.c    \
		ft_striteri.c   \
		ft_strmap.c     \
		ft_strmapi.c    \
		ft_strequ.c     \
		ft_strnequ.c    \
		ft_strsub.c     \
		ft_strjoin.c    \
		ft_strtrim.c    \
		ft_putchar.c    \
		ft_putstr.c     \
		ft_putendl.c    \
		ft_putnbr.c     \
		ft_putchar_fd.c \
		ft_putstr_fd.c  \
		ft_putendl_fd.c \
		ft_putnbr_fd.c  \
		ft_strncmp.c    \
		ft_strsplit.c   \
		ft_itoa.c       \
		ft_lstnew.c     \
		ft_lstdelone.c  \
		ft_lstdel.c     \
		ft_lstadd.c     \
		ft_lstiter.c    \
		ft_lstmap.c     \
		ft_sqrt.c       \
		ft_lstcount.c   \
		ft_swap.c       \
		ft_sortint.c    \
		ft_arrprint.c   \
		ft_part_itoa.c  \
		ft_mem_removal.c \
		get_next_line.c \
		ft_itoa_long.c \
		printf/ft_strjoin_f.c               \
        printf/ft_putstr_f.c                \
		printf/to_gather_data.c             \
		printf/to_check_speceficators.c     \
		printf/ft_converters.c              \
		printf/ft_unicode.c                 \
		printf/unicode_printer.c            \
		printf/to_put_string_and_char.c     \
		printf/to_sort_types_helper.c       \
		printf/all_main_func.c              \
		printf/all_into_string.c            \
		printf/ft_printf.c                  \
		printf/ft_itoa_double.c             \
        printf/ft_itoa_unsigned.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
