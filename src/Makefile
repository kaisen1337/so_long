# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 16:37:39 by nkasimi           #+#    #+#              #
#    Updated: 2025/02/15 13:08:01 by nkasimi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
BONUS = so_long_bonus

SRCS = get_next_line.c \
       get_next_line_utils.c \
       itoa.c \
       extention_checker.c \
       flood_file.c \
       ft_printf.c \
       map_checker.c \
       utils.c \
       clear.c \
       movement.c \
       drawing_map.c \
       game.c \
       keys.c 

OBJS = $(SRCS:.c=.o)

SRCB = get_next_line.c \
       get_next_line_utils.c \
       itoa.c \
       extention_checker.c \
       flood_file.c \
       ft_printf.c \
       map_checker.c \
       utils.c \
       bonus/utils_bonus.c \
       bonus/clear_bonus.c \
       bonus/drawing_map_bonus.c \
       bonus/movement_bonus.c \
       bonus/keys_bonus.c \
       bonus/so_long_bonus.c \
       bonus/animation_bonus.c

OBJB = $(SRCB:.c=.o)

INCLUDES = so_long.h
LIB = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext
all: $(NAME)
bonus: $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(BONUS): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) $(LIB) -o $(BONUS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus 