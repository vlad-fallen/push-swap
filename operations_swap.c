/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:15:33 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/03 15:41:58 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem_of_stack	*swap_elem(t_elem_of_stack *start_of_stack)
{
	t_elem_of_stack	*elem1;
	t_elem_of_stack	*elem2;
	t_elem_of_stack	*prev;
	t_elem_of_stack	*next;

	elem1 = start_of_stack;
	elem2 = elem1->next;
	prev = elem1->prev;
	next = elem2->next;
	if (prev != elem2 && next != elem1)
	{
		prev->next = elem2;
		elem2->prev = prev;
		elem2->next = elem1;
		elem1->prev = elem2;
		elem1->next = next;
		next->prev = elem1;
	}
	return (elem2);
}

void	op_sx(t_stack *stack, enum e_stack name_stack, int flag)
{
	if (stack->head != NULL || stack->size >= 2)
		stack->head = swap_elem(stack->head);
	if (flag == 1)
	{
		if (name_stack == e_stack_a)
			print_operation(e_op_sa);
		else
			print_operation(e_op_sb);
	}
}

void	op_ss(t_stack *a_stack, t_stack *b_stack, int flag)
{
	if (a_stack->head != NULL || a_stack->size >= 2)
		a_stack->head = swap_elem(a_stack->head);
	if (b_stack->head != NULL || b_stack->size >= 2)
		b_stack->head = swap_elem(b_stack->head);
	if (flag == 1)
		print_operation(e_op_ss);
}
