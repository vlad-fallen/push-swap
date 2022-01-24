/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:40:04 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/22 17:10:14 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_rrx(t_stack *stack, enum e_stack name_stack)
{
	if (stack->head == NULL)
		return ;
	stack->head = stack->head->prev;
	if (name_stack == e_stack_a)
		print_operation(e_op_rra);
	else
		print_operation(e_op_rrb);
}

void op_rrr(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->head == NULL && b_stack->head == NULL)
		return ;
	a_stack->head= a_stack->head->prev;
	b_stack->head = b_stack->head->prev;
	print_operation(e_op_rrr);
}
