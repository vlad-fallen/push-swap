/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:35:06 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/02 16:57:15 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_push(t_stack *main_stack, t_elem_of_stack *median,
				int size_chunk)
{
	int				push_size;
	int				i;
	t_elem_of_stack	*tmp;

	tmp = main_stack->head;
	push_size = 0;
	i = 0;
	while (i < size_chunk)
	{
		if (tmp->num <= median->num && main_stack->name_stack == e_stack_a)
			push_size++;
		else if (tmp->num > median->num && main_stack->name_stack == e_stack_b)
			push_size++;
		i++;
		tmp = tmp->next;
	}
	return (push_size);
}

static int	count_rotate(t_stack *main_stack, t_elem_of_stack *median,
				int size_chunk)
{
	int				rotate_size;
	int				i;
	t_elem_of_stack	*tmp;

	tmp = main_stack->head;
	rotate_size = 0;
	i = 0;
	while (i < size_chunk)
	{
		if (tmp->num <= median->num && main_stack->name_stack == e_stack_b)
			rotate_size++;
		else if (tmp->num > median->num && main_stack->name_stack == e_stack_a)
			rotate_size++;
		i++;
		tmp = tmp->next;
	}
	return (rotate_size);
}

static void	choice_1(t_stack *main_stack, t_stack *stack,
				int *push_size, int *rotate_size)
{
	main_stack->head->markup++;
	if (main_stack->name_stack == e_stack_a && *push_size > 0)
	{
		op_rx(main_stack, main_stack->name_stack);
		(*rotate_size)--;
	}
	else if (main_stack->name_stack == e_stack_b && *push_size > 0)
	{
		op_px(main_stack, stack, stack->name_stack);
		(*push_size)--;
	}
}

static void	choice_2(t_stack *main_stack, t_stack *stack,
				int *push_size, int *rotate_size)
{
	main_stack->head->markup++;
	if (main_stack->name_stack == e_stack_a && *push_size > 0)
	{
		op_px(main_stack, stack, stack->name_stack);
		(*push_size)--;
	}
	else if (main_stack->name_stack == e_stack_b && *push_size > 0)
	{
		op_rx(main_stack, main_stack->name_stack);
		(*rotate_size)--;
	}
}

void	push_or_rotate(t_stack *main_stack, t_stack *stack,
			int mark, int size_chunk)
{
	t_elem_of_stack	*median;
	t_elem_of_stack	*tmp;
	int				push_size;
	int				rotate_size;

	median = find_median(main_stack, size_chunk);
	push_size = count_push(main_stack, median, size_chunk);
	rotate_size = count_rotate(main_stack, median, size_chunk);
	while (main_stack->head->markup == mark)
	{
		if (main_stack->head->num > median->num)
			choice_1(main_stack, stack, &push_size, &rotate_size);
		else
			choice_2(main_stack, stack, &push_size, &rotate_size);
	}
	tmp = main_stack->head->next;
	while (rotate_size > 1)
	{
		tmp->markup++;
		tmp = tmp->next;
		rotate_size--;
	}
}
