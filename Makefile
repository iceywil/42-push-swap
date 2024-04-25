# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 18:40:46 by wscherre          #+#    #+#              #
#    Updated: 2024/03/12 18:17:43 by wscherre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=	srcs/main.c \
				srcs/print_error.c \
				srcs/check_inputs.c \
				srcs/list_a.c \
				srcs/free_all.c \
				srcs/free_all_two.c \
				srcs/sort_it_one.c \
				srcs/sort_cheaps.c \
				srcs/sort_costs_a_b.c \
				srcs/sort_costs_b_a.c \
				srcs/sort_run_cheaps.c \
				srcs/sort_values.c \
				srcs/algo_two.c \
				srcs/algo_three.c \
				srcs/algo_four.c \
				srcs/moves_one.c \
				srcs/moves_two.c \
				srcs/moves_three.c \
				srcs/stack_utils.c \
				srcs/brute.c

FILES_BONUS =	bonus/main_bonus.c \
				bonus/moves_one_bonus.c \
				bonus/moves_two_bonus.c \
				bonus/moves_three_bonus.c \
				bonus/free_all_bonus.c \
				bonus/check_inputs_bonus.c \
				bonus/print_error_bonus.c \
				bonus/list_a_bonus.c \

OBJS    	=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(FILES_BONUS:.c=.o)

DEPS 		=	$(SRCS:.c=.d)
DEPS_BONUS 	=	$(FILES_BONUS:.c=.d)

CC  		=	cc

RM  		=	rm -f

CFLAGS  	=	-Wall -Wextra -Werror -I. -MMD

NAME    	=	push_swap

BONUS_NAME 	=	checker

all: $(NAME)

-include $(DEPS) $(DEPS_BONUS)

LIBFT = ./libft/libft.a

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

$(BONUS_NAME): $(LIBFT_PATH) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) -L./libft -lft

all: ${NAME}

bonus: $(BONUS_NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) $(DEPS) $(DEPS_BONUS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus