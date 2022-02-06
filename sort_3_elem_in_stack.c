/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_elem_in_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:54:03 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/06 17:43:05 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 2 1 3 */
void	list_of_operations_1(t_stack *main_stack, t_stack *stack)
{
	if (main_stack->name_stack == e_stack_a)
		op_sx(main_stack, main_stack->name_stack, 1);
	else
	{
		op_px(main_stack, stack, stack->name_stack, 1);
		op_sx(main_stack, main_stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
		op_sx(stack, stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
	}
}

/* 3 1 2 */
void	list_of_operations_2(t_stack *main_stack, t_stack *stack)
{
	if (main_stack->name_stack == e_stack_a)
	{
		op_sx(main_stack, main_stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
		op_sx(main_stack, main_stack->name_stack, 1);
		op_px(stack, main_stack, main_stack->name_stack, 1);
	}
	else
	{
		op_px(main_stack, stack, stack->name_stack, 1);
		op_sx(main_stack, main_stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
	}
}

/* 2 3 1 */
void	list_of_operations_3(t_stack *main_stack, t_stack *stack)
{
	if (main_stack->name_stack == e_stack_a)
	{
		op_px(main_stack, stack, stack->name_stack, 1);
		op_sx(main_stack, main_stack->name_stack, 1);
		op_rx(main_stack, main_stack->name_stack, 1);
		op_px(stack, main_stack, main_stack->name_stack, 1);
		op_rrx(main_stack, main_stack->name_stack, 1);
	}
	else
	{
		op_sx(main_stack, main_stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
	}
}

/* 3 2 1 */
void	list_of_operations_4(t_stack *main_stack, t_stack *stack)
{
	if (main_stack->name_stack == e_stack_a)
	{
		op_sx(main_stack, main_stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
		op_sx(main_stack, main_stack->name_stack, 1);
		op_rx(main_stack, main_stack->name_stack, 1);
		op_px(stack, main_stack, main_stack->name_stack, 1);
		op_rrx(main_stack, main_stack->name_stack, 1);
	}
	else
	{
		op_px(main_stack, stack, stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
	}
}

/* 1 3 2 */
void	list_of_operations_5(t_stack *main_stack, t_stack *stack)
{
	if (main_stack->name_stack == e_stack_a)
	{
		op_px(main_stack, stack, stack->name_stack, 1);
		op_sx(main_stack, main_stack->name_stack, 1);
		op_px(stack, main_stack, main_stack->name_stack, 1);
	}
	else
	{
		op_sx(main_stack, main_stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
		op_sx(main_stack, main_stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
		op_px(main_stack, stack, stack->name_stack, 1);
	}
}
