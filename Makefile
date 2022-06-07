# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 22:54:38 by hmokhtar          #+#    #+#              #
#    Updated: 2022/06/06 22:12:23 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

INC = libft/libft.h libft/printf/ft_printf.h

SRC_PATH = src

SRC_NAME =	create_lst.c find_med.c lst.c vis.c cancer.c\
			push_swap.c push.c resolve.c reverse_rotate.c \
				rotate.c short_resolve.c swap.c utils.c \

BONUS_NAME = checker.c create_lst.c find_med.c lst.c vis.c \
				cancer.c push.c resolve.c reverse_rotate.c \
				rotate.c short_resolve.c swap.c utils.c \

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

B_SRC = $(addprefix $(SRC_PATH)/, $(BONUS_NAME))

LIBFT = libft/libft.a

PRINTF = libft/printf/libftprintf.a

OBJS = $(SRC:.c=.o)

B_OBJS = $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) src/push_swap.h
	@cc $(FLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $@

bonus: $(BONUS)

$(BONUS): $(B_OBJS) src/push_swap.h
	@cc $(FLAGS) $(B_SRC) $(LIBFT) $(PRINTF) -o $@

clean:
	@$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	@$(RM) $(NAME) $(BONUS)

re: fclean all
