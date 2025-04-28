# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 15:01:26 by jyniemit          #+#    #+#              #
#    Updated: 2025/04/28 15:06:31 by jyniemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a

SRCDIR = ./src/
SRCS = $(SRCDIR)main.c

OBJDIR = ./build/
OBJS = $(addprefix $(OBJDIR), $(SRCS:$(SRCDIR)%.c=%.o))

INCLUDEDIR = ./include/
HEADER = $(addprefix $(INCLUDEDIR), push_swap.h)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(LIBFTDIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
