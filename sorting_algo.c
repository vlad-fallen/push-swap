/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:16:18 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/02 16:55:01 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_mark(t_stack *stack, int mark)
{
	int				count;
	t_elem_of_stack	*current;
	t_elem_of_stack	*end_stack;

	count = 0;
	current = stack->head;
	end_stack = stack->head->prev;
	while (mark == current->markup && current != end_stack)
	{
		count++;
		current = current->next;
	}
	if (current == end_stack)
		count++;
	return (count);
}

static void	swap_2_elem_util(t_stack *main_stack, t_stack *stack)
{
	if (main_stack->name_stack == e_stack_b)
	{
		main_stack->head->markup = 0;
		op_px(main_stack, stack, stack->name_stack);
	}
	if (main_stack->name_stack == e_stack_a)
		main_stack->head->markup = 0;
}

static void	swap_2_elem(t_stack *main_stack, t_stack *stack, int size_chunk)
{
	if (size_chunk == 2)
	{
		if (main_stack->name_stack == e_stack_a)
		{
			if (main_stack->head->num > main_stack->head->next->num)
				op_sx(main_stack, main_stack->name_stack);
			main_stack->head->markup = 0;
			main_stack->head->next->markup = 0;
		}
		else
		{
			op_px(main_stack, stack, stack->name_stack);
			op_px(main_stack, stack, stack->name_stack);
			if (stack->head->num > stack->head->next->num)
				op_sx(stack, stack->name_stack);
			stack->head->markup = 0;
			stack->head->next->markup = 0;
		}
	}
	else if (size_chunk == 1)
		swap_2_elem_util(main_stack, stack);
}

static void	rotate_mark(t_stack *stack, int mark)
{
	t_elem_of_stack	*current;
	int				flag;

	current = stack->head->prev;
	flag = 0;
	while (current != stack->head)
	{
		if (current->markup == mark + 1)
			current = current->prev;
		else if (current->markup <= mark)
		{
			flag = 1;
			break ;
		}
	}
	if (flag)
	{
		while (stack->head->prev->markup == mark + 1)
		{
			op_rrx(stack, stack->name_stack);
		}
	}
}

void	quicksort(t_stack *main_stack, t_stack *stack, int mark)
{
	int	size_chunk;

	size_chunk = count_mark(main_stack, mark);
	if (size_chunk <= 2)
	{
		swap_2_elem(main_stack, stack, size_chunk);
		return ;
	}
	push_or_rotate(main_stack, stack, mark, size_chunk);
	rotate_mark(main_stack, mark);
	if (main_stack->name_stack == e_stack_a)
	{
		quicksort(main_stack, stack, mark + 1);
		quicksort(stack, main_stack, mark + 1);
	}
	else
	{
		quicksort(stack, main_stack, mark + 1);
		quicksort(main_stack, stack, mark + 1);
	}
}
