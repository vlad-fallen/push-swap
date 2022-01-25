/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:16:18 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/25 16:51:59 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_mark(t_stack *stack, int mark)
{
	int count;
	t_elem_of_stack *current;
	t_elem_of_stack *end_stack;


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

static void swap_2_elem(t_stack *main_stack,t_stack *stack, int size_chunk)
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
	else
	{
		if (main_stack->name_stack == e_stack_b)
		{
			main_stack->head->markup = 0;
			op_px(main_stack, stack, stack->name_stack);
		}
		if (main_stack->name_stack == e_stack_a)
			main_stack->head->markup = 0;
	}
}

static void rotate_mark(t_stack *stack, int mark)
{
	t_elem_of_stack *current;
	//t_elem_of_stack *tmp;
	int flag;
	//int rx_size;
	//int rrx_size;

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
		/*tmp = current;
		rx_size = 0;
		rrx_size = 0;
		while (tmp != stack->head)
		{
			rx_size++;
			tmp = tmp->prev;
		}
		tmp = current;
		while (tmp != stack->head)
		{
			rrx_size++;
			tmp = tmp->next;
		}
		if (rx_size < rrx_size)
		{
			while (stack->head->markup == mark + 1)
				op_rx(stack, stack->name_stack);
		}
		else
		{
			while (stack->head->prev->markup != mark + 1)
				op_rrx(stack, stack->name_stack);
		}*/
		while (stack->head->prev->markup == mark + 1)
		{
			op_rrx(stack, stack->name_stack);
		}
	}
}

void quicksort(t_stack *main_stack, t_stack *stack, int mark)
{
	int size_chunk;
	t_elem_of_stack *median;

	size_chunk = count_mark(main_stack, mark);
	if (size_chunk <= 2)
	{
		swap_2_elem(main_stack, stack, size_chunk);
		return ;
	}
	median = find_median(main_stack, size_chunk);
	while (main_stack->head->markup == mark)
	{
		if (main_stack->head->num > median->num)
		{
			main_stack->head->markup = mark + 1;
			if (main_stack->name_stack == e_stack_a)
				op_rx(main_stack, main_stack->name_stack);
			else
				op_px(main_stack, stack, stack->name_stack);
		}
		else
		{
			main_stack->head->markup = mark + 1;
			if (main_stack->name_stack == e_stack_a)
				op_px(main_stack, stack, stack->name_stack);
			else
				op_rx(main_stack, main_stack->name_stack);
		}
	}
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
