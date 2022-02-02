/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:15:18 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/02 19:03:14 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rx(t_stack *stack, enum e_stack name_stack, int flag)
{
	if (stack->head == NULL)
		return ;
	stack->head = stack->head->next;
	if (flag == 0)
		return ;
	if (name_stack == e_stack_a)
		print_operation(e_op_ra);
	else
		print_operation(e_op_rb);
}

void	op_rr(t_stack *a_stack, t_stack *b_stack, int flag)
{
	if (a_stack->head == NULL && b_stack->head == NULL)
		return ;
	a_stack->head = a_stack->head->next;
	b_stack->head = b_stack->head->next;
	if (flag == 0)
		return ;
	print_operation(e_op_rr);
}
