/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:34:48 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/20 18:05:01 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdio.h>

typedef struct s_elem_of_stack
{
	int				num;
	struct s_elem_of_stack	*prev;
	struct s_elem_of_stack	*next;
}	t_elem_of_stack;

typedef struct s_stack
{
	int size;
	t_elem_of_stack *head;
}	t_stack;

enum e_operation
{
	e_op_sa,
	e_op_sb,
	e_op_ss,
	e_op_ra,
	e_op_rb,
	e_op_rr,
	e_op_pa,
	e_op_pb,
	e_op_rra,
	e_op_rrb,
	e_op_rrr
};

/*utils.c*/
void	err_arg(void);
void print_operation(enum e_operation id);
void print_stack(t_elem_of_stack *start_stack, int size_stack);

/*parse.c*/
t_stack *parsing_args(int argc, char ** argv);

/*stack.c*/
t_stack *create_stack(int *array, int size_arr);
void add_elem(t_stack *stack, t_elem_of_stack *elem);
t_elem_of_stack	*create_elem(int num);
t_stack *init_stack(void);

/*operations*/
void op_sx(t_stack *stack, enum e_operation id);
void op_ss(t_stack *a_stack, t_stack *b_stack);
void op_rx(t_stack *stack, enum e_operation id);
void op_rr(t_stack *a_stack, t_stack *b_stack);
void op_rrx(t_stack *stack, enum e_operation id);
void op_rrr(t_stack *a_stack, t_stack *b_stack);
void op_px(t_stack *from, t_stack *to, enum e_operation id);

#endif