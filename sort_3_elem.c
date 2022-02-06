/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:20:12 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/06 12:45:44 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_elem_util(t_elem_of_stack *elem_1, t_elem_of_stack *elem_2,
	t_elem_of_stack *elem_3, t_stack *stack)
{
	if (elem_1->index > elem_2->index && elem_2->index > elem_3->index
		&& elem_3->index < elem_1->index)
	{
		op_sx(stack, stack->name_stack, 1);
		op_rrx(stack, stack->name_stack, 1);
	}
	else if (elem_1->index < elem_2->index && elem_2->index > elem_3->index
		&& elem_3->index > elem_1->index)
	{
		op_sx(stack, stack->name_stack, 1);
		op_rx(stack, stack->name_stack, 1);
	}
}

void	sort_3_elements(t_stack *stack)
{
	t_elem_of_stack	*elem_1;
	t_elem_of_stack	*elem_2;
	t_elem_of_stack	*elem_3;

	if (stack->size != 3)
		return ;
	elem_1 = stack->head;
	elem_2 = elem_1->next;
	elem_3 = elem_2->next;
	elem_1->markup = 0;
	elem_2->markup = 0;
	elem_3->markup = 0;
	if (elem_1->index > elem_2->index && elem_2->index < elem_3->index
		&& elem_3->index > elem_1->index)
		op_sx(stack, stack->name_stack, 1);
	else if (elem_1->index > elem_2->index && elem_2->index < elem_3->index
		&& elem_3->index < elem_1->index)
		op_rx(stack, stack->name_stack, 1);
	else if (elem_1->index < elem_2->index && elem_2->index > elem_3->index
		&& elem_3->index < elem_1->index)
		op_rrx(stack, stack->name_stack, 1);
	else
		sort_3_elem_util(elem_1, elem_2, elem_3, stack);
}

static void	operations_of_sort_for_3_elem_util(t_stack *main_stack,
				t_stack *stack)
{
	t_elem_of_stack	*elem_1;
	t_elem_of_stack	*elem_2;
	t_elem_of_stack	*elem_3;

	elem_1 = main_stack->head;
	elem_2 = elem_1->next;
	elem_3 = elem_2->next;
	if (elem_1->index < elem_2->index && elem_2->index > elem_3->index
		&& elem_3->index > elem_1->index)
		list_of_operations_5(main_stack, stack);
	else if (elem_1->index < elem_2->index && elem_2->index < elem_3->index
		&& elem_3->index > elem_1->index)
	{
		if (main_stack->name_stack == e_stack_b)
		{
			op_rx(main_stack, main_stack->name_stack, 1);
			op_rx(main_stack, main_stack->name_stack, 1);
			op_px(main_stack, stack, stack->name_stack, 1);
			op_rrx(main_stack, main_stack->name_stack, 1);
			op_px(main_stack, stack, stack->name_stack, 1);
			op_rrx(main_stack, main_stack->name_stack, 1);
			op_px(main_stack, stack, stack->name_stack, 1);
		}
	}
}

static void	operations_of_sort_for_3_elem(t_stack *main_stack, t_stack *stack)
{
	t_elem_of_stack	*elem_1;
	t_elem_of_stack	*elem_2;
	t_elem_of_stack	*elem_3;

	elem_1 = main_stack->head;
	elem_2 = elem_1->next;
	elem_3 = elem_2->next;
	elem_1->markup = 0;
	elem_2->markup = 0;
	elem_3->markup = 0;
	if (elem_1->index > elem_2->index && elem_2->index < elem_3->index
		&& elem_3->index > elem_1->index)
		list_of_operations_1(main_stack, stack);
	else if (elem_1->index > elem_2->index && elem_2->index < elem_3->index
		&& elem_3->index < elem_1->index)
		list_of_operations_2(main_stack, stack);
	else if (elem_1->index < elem_2->index && elem_2->index > elem_3->index
		&& elem_3->index < elem_1->index)
		list_of_operations_3(main_stack, stack);
	else if (elem_1->index > elem_2->index && elem_2->index > elem_3->index
		&& elem_3->index < elem_1->index)
		list_of_operations_4(main_stack, stack);
	else
		operations_of_sort_for_3_elem_util(main_stack, stack);
}

void	sort_3_elem_in_stack(t_stack *main_stack, t_stack *stack)
{
	if (main_stack->size == 3 && main_stack->name_stack == e_stack_a)
		sort_3_elements(main_stack);
	else
		operations_of_sort_for_3_elem(main_stack, stack);
}
