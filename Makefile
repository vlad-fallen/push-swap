# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 15:40:50 by mbutter           #+#    #+#              #
#    Updated: 2022/01/30 16:42:19 by mbutter          ###   ########.fr        #
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
				sorting_utils.c

OBJS		=	$(patsubst %.c,%.o,$(SRCS)) 

BONUS		=	

BONUS_OBJS	=	$(patsubst %.c,%.o,$(BONUS))

D_FILES		=	$(patsubst %.c,%.d,$(SRCS) $(BONUS)) 

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	push_swap


%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@ -MMD

$(NAME):	$(OBJS)
			@make -C ./libft
			$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(D_FILES) $(BONUS_OBJS) $(D_FILES_B)
			@make clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C ./libft

re:			fclean $(NAME)

bonus:		$(BONUS_OBJS)
			@make -C ./libft
			$(CC) $(CFLAGS) $(BONUS_OBJS) ./libft/libft.a -o $(NAME)


.PHONY:		all clean fclean re bonus

include $(wildcard $(D_FILES))
