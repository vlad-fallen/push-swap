/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:20:12 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/29 18:21:19 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3_elements(t_stack *stack, int mark)
{
	t_elem_of_stack *elem_1;
	t_elem_of_stack *elem_2;
	t_elem_of_stack *elem_3;

	if (stack->size != 3)
		return ;
	elem_1 = stack->head;
	elem_2 = elem_1->next;
	elem_3 = elem_2->next;
	if (elem_1->index > elem_2->index && elem_2->index < elem_3->index 
			&& elem_3->index > elem_1->index)
		op_sx(stack, stack->name_stack);
	else if (elem_1->index > elem_2->index && elem_2->index < elem_3->index 
			&& elem_3->index < elem_1->index)
		op_rx(stack, stack->name_stack);
	else if (elem_1->index < elem_2->index && elem_2->index > elem_3->index 
			&& elem_3->index < elem_1->index)
		op_rrx(stack, stack->name_stack);
	else if (elem_1->index > elem_2->index && elem_2->index > elem_3->index 
			&& elem_3->index < elem_1->index)
	{
		op_sx(stack, stack->name_stack);
		op_rrx(stack, stack->name_stack);
	}
	else if (elem_1->index < elem_2->index && elem_2->index > elem_3->index 
			&& elem_3->index > elem_1->index)
	{
		op_sx(stack, stack->name_stack);
		op_rx(stack, stack->name_stack);
	}
}
