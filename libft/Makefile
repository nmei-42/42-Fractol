# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 08:57:48 by nmei              #+#    #+#              #
#    Updated: 2018/01/17 19:06:26 by nmei             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS_DIR = ./
RM = /bin/rm -f

FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp \
ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat \
ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi \
ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower \
ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri \
ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim \
ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd \
ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel \
ft_lstadd ft_lstiter ft_lstmap ft_memdup ft_lstlen ft_lstrev ft_abs ft_lstlast \
ft_get_next_line ft_num_words ft_splitdel

HEAD = -I ./includes
CFLAGS = -Wall -Wextra -Werror

CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

$(OFILES) :
	gcc $(CFLAGS) -c $(CFILES) $(HEAD)

clean :
	$(RM) $(OFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all
