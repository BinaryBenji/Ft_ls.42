#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaegene <brice.wge@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 09:48:23 by bwaegene          #+#    #+#              #
#    Updated: 2017/01/08 14:52:45 by bwaegene         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.SUFFIXES:

CC = gcc
CFLAGS = -Wall -Wextra -Werror
COPT = -I ./
CDEBUG = -g
NAME = libft.a

SOURCES = ft_atoi.c		\
					ft_bzero.c	\
					ft_isalnum.c	\
					ft_isalpha.c	\
					ft_isascii.c	\
					ft_isdigit.c	\
					ft_isprint.c	\
					ft_isspace.c	\
					ft_isupper.c	\
					ft_itoa.c	\
					ft_lstadd.c	\
					ft_lstdel.c	\
					ft_lstdelone.c	\
					ft_lstiter.c	\
					ft_lstmap.c	\
					ft_lstnew.c	\
					ft_memalloc.c	\
					ft_memccpy.c	\
					ft_memchr.c	\
					ft_memcmp.c	\
					ft_memcpy.c	\
					ft_memdel.c	\
					ft_memmove.c	\
					ft_memset.c	\
					ft_putchar.c	\
					ft_putchar_fd.c	\
					ft_putendl.c	\
					ft_putendl_fd.c	\
					ft_putnbr.c	\
					ft_putnbr_fd.c	\
					ft_putstr.c	\
					ft_putstr_fd.c	\
					ft_range.c	\
					ft_sqrt.c	\
					ft_strcat.c	\
					ft_strchr.c	\
					ft_strclr.c	\
					ft_strcmp.c	\
					ft_strcpy.c	\
					ft_strdel.c	\
					ft_strdup.c	\
					ft_strequ.c	\
					ft_striter.c	\
					ft_striteri.c	\
					ft_strjoin.c	\
					ft_strlcat.c	\
					ft_strlen.c	\
					ft_strmap.c	\
					ft_strmapi.c	\
					ft_strncat.c	\
					ft_strncmp.c	\
					ft_strncpy.c	\
					ft_strnequ.c	\
					ft_strnew.c	\
					ft_strnstr.c	\
					ft_strrchr.c	\
					ft_strsplit.c	\
					ft_strstr.c	\
					ft_strsub.c	\
					ft_strtrim.c	\
					ft_tolower.c	\
					ft_foreach.c		 \
					ft_pisnegative.c \
					ft_toupper.c \
					get_next_line.c

OBJECTS = $(SOURCES:.c=.o)
HEADERS = $(NAME:.a=.h)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(COPT) -c $(SOURCES)

.PHONY: clean
clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME) $(NAME)-debug

re: fclean all
