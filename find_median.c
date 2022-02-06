/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:52:33 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/06 17:42:24 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem_of_stack	*find_max_elem(t_stack *stack, int size_chunk)
{
	t_elem_of_stack	*max;
	t_elem_of_stack	*current;
	int				i;

	i = 0;
	current = stack->head->next;
	max = stack->head;
	while (current != stack->head && i < size_chunk)
	{
		if (max->index < current->index)
			max = current;
		current = current->next;
		i++;
	}
	return (max);
}

static t_elem_of_stack	*find_min_elem(t_stack *stack, int size_chunk)
{
	t_elem_of_stack	*min;
	t_elem_of_stack	*current;
	int				i;

	i = 0;
	current = stack->head->next;
	min = stack->head;
	while (current != stack->head && i < size_chunk - 1)
	{
		if (min->index > current->index)
			min = current;
		current = current->next;
		i++;
	}
	return (min);
}

t_elem_of_stack	*find_median(t_stack *stack, int size_chunk)
{
	t_elem_of_stack	*median;
	t_elem_of_stack	*current;
	int				average_value;
	int				i;

	i = 0;
	average_value = (find_max_elem(stack, size_chunk)->index + \
		find_min_elem(stack, size_chunk)->index) / 2;
	median = stack->head;
	current = stack->head->next;
	while (i < size_chunk)
	{
		if (current->index == average_value)
		{
			median = current;
			break ;
		}
		current = current->next;
		i++;
	}
	return (median);
}
