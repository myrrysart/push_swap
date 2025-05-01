# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 15:01:26 by jyniemit          #+#    #+#              #
#    Updated: 2025/05/01 19:56:51 by jyniemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a
SRCDIR = ./src/
SRCS = $(SRCDIR)main.c $(SRCDIR)turk_algorithm.c
OBJDIR = ./build/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))
INCLUDEDIR = ./include/
HEADER = $(addprefix $(INCLUDEDIR), push_swap.h)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(LIBFTDIR) -c $< -o $@

$(GAME_OBJ): $(GAME_SRC) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(LIBFTDIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(GAME_NAME)
	@make -C $(LIBFTDIR) fclean

debug: CFLAGS += -g
debug: re
	@echo "Recompiling with debugflags: $(CFLAGS)"

re: fclean all

.PHONY: all clean fclean re debug game
