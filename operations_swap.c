/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:15:33 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/20 18:23:03 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem_of_stack *swap_elem(t_elem_of_stack *start_of_stack)
{
	t_elem_of_stack *elem1;
	t_elem_of_stack *elem2;
	t_elem_of_stack *tmp;

	elem1 = start_of_stack;
	elem2 = start_of_stack->next;
	tmp = elem1->prev;
	elem2->next->prev = elem1;
	elem1->next = elem2->next;
	elem1->prev = elem2;
	tmp->next = elem2;
	elem2->next = elem1;
	elem2->prev = tmp;
	return (elem2);
}

void op_sx(t_stack *stack, enum e_operation id)
{
	if (stack->head != NULL || stack->size >= 2)
		stack->head = swap_elem(stack->head);
	print_operation(id);
}

void op_ss(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->head != NULL || a_stack->size >= 2)
		a_stack->head = swap_elem(a_stack->head);
	if (b_stack->head != NULL || b_stack->size >= 2)
		b_stack->head = swap_elem(b_stack->head);
	print_operation(e_op_ss);
}