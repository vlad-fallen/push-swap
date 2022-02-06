# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 15:40:50 by mbutter           #+#    #+#              #
#    Updated: 2022/02/05 19:24:26 by mbutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c \
				parse.c \
				parsing_index.c \
				operations_swap.c \
				operations_rotate.c \
				operations_reverse_rotate.c \
				operations_push.c \
				stack.c \
				utils.c \
				find_median.c \
				sorting_algo.c \
				sort_3_elem.c \
				sort_3_elem_in_stack.c \
				sorting_utils.c

OBJS		=	$(patsubst %.c,%.o,$(SRCS)) 

BONUS		=	checker.c \
				parse.c \
				stack.c \
				operations_swap.c \
				operations_rotate.c \
				operations_reverse_rotate.c \
				operations_push.c \
				utils.c 

BONUS_OBJS	=	$(patsubst %.c,%.o,$(BONUS))

D_FILES		=	$(patsubst %.c,%.d,$(SRCS) $(BONUS)) 

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	push_swap

BONUS_NAME	=	checker

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@ -MMD

$(NAME):	$(OBJS) Makefile 
			@make -C ./libft
			$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME) -MMD

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(D_FILES) $(BONUS_OBJS) $(D_FILES_B)
			@make clean -C ./libft

fclean:		clean
			$(RM) $(NAME) $(BONUS_NAME)
			@make fclean -C ./libft

re:			fclean $(NAME)

bonus:		$(BONUS_OBJS)
			@make -C ./libft
			$(CC) $(CFLAGS) $(BONUS_OBJS) ./libft/libft.a -o $(BONUS_NAME) -MMD


.PHONY:		all clean fclean re bonus

include $(wildcard $(D_FILES))
