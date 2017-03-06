/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:34:47 by bzmuda            #+#    #+#             */
/*   Updated: 2017/03/04 17:34:50 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# Disable implicit rules
.SUFFIXES:

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -Werror
## Flags for the C preprocessor
CPPFLAGS = -I$(SRC_PATH) -I$(LIB)
## Libraries path
LDFLAGS = -L$(LIB)
## Libraries to link into the executable
LDLIBS = -lft
NAME = fdf

# Project related variables
SRC_PATH =  src
SRC_NAME =  main.c
OBJ_PATH =  obj
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft
HEADER = $(SRC_PATH)/$(NAME).h

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(LIB)/$(LIB).a $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir $@

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# /!\ Dirty workaround /!\
# If make on the libft directory should rebuild something then PHONY the rule
# libft to build it. Otherwise it relink.
ifeq ($(shell $(MAKE) --question -C ./$(LIB) ; echo $$?), 1)
.PHONY: $(LIB)/$(LIB).a
endif

$(LIB)/$(LIB).a:
	$(MAKE) -C ./$(LIB)

.PHONY: clean
clean:
	$(MAKE) -C ./$(LIB) clean
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(MAKE) -C ./$(LIB) fclean
	$(RM) -r $(NAME) $(NAME).dSYM

re: fclean
	$(MAKE) all
