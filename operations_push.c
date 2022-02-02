/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:04:41 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/02 15:50:16 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem_of_stack	*exclude_elem(t_stack *stack)
{
	t_elem_of_stack	*elem;
	t_elem_of_stack	*prev;
	t_elem_of_stack	*next;

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

static void	push_elem(t_stack *stack, t_elem_of_stack *elem)
{
	t_elem_of_stack	*tmp;

	if (stack && elem)
	{
		if (stack->head != NULL)
		{
			tmp = stack->head->prev;
			elem->next = stack->head;
			elem->prev = stack->head->prev;
			stack->head->prev = elem;
			tmp->next = elem;
			stack->head = elem;
		}
		else
		{
			stack->head = elem;
			stack->head->next = elem;
			stack->head->prev = elem;
		}
	}
}

void	op_px(t_stack *from, t_stack *to, enum e_stack name_stack)
{
	t_elem_of_stack	*elem;

	if (from == NULL || from->head == NULL)
		return ;
	elem = exclude_elem(from);
	push_elem(to, elem);
	to->size++;
	if (name_stack == e_stack_a)
		print_operation(e_op_pa);
	else
		print_operation(e_op_pb);
}
