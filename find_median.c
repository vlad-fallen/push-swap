/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:52:33 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/02 15:49:16 by mbutter          ###   ########.fr       */
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
	while (current != stack->head && i++ < size_chunk)
	{
		if (max->num < current->num)
			max = current;
		current = current->next;
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
	while (current != stack->head && i++ < size_chunk)
	{
		if (min->num > current->num)
			min = current;
		current = current->next;
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
	average_value = (find_max_elem(stack, size_chunk)->num + \
		find_min_elem(stack, size_chunk)->num) / 2;
	median = stack->head;
	current = stack->head->next;
	while (i < size_chunk)
	{
		if (ft_abs(current->num - average_value) < \
			ft_abs(median->num - average_value))
			median = current;
		if (ft_abs(median->num - average_value) == 0)
			break ;
		current = current->next;
		i++;
	}
	return (median);
}
