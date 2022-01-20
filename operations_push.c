/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:04:41 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/20 18:23:41 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem_of_stack *exclude_elem(t_stack *stack)
{
	t_elem_of_stack *elem;
	t_elem_of_stack *prev;
	t_elem_of_stack *next;

	elem = stack->head;
	prev = elem->prev;
	next = elem->next;
	if (stack->size == 1)
	{
		stack->head = NULL;
		elem->next = NULL;
		elem->prev = NULL;
	}
	else
	{
		stack->head = next;
		next->prev = prev;
		prev->next = next;
		elem->prev = NULL;
		elem->next = NULL;
	}
	stack->size--;
	return (elem);
}

void op_px(t_stack *from, t_stack *to, enum e_operation id)
{
	t_elem_of_stack *elem;

	if (from == NULL || from->head == NULL)
		return ;
	elem = exclude_elem(from);
	add_elem(to, elem);
	to->size++;
	print_operation(id);
}