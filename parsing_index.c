/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:59:24 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/02 16:20:49 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	parsing_index(t_stack *stack)
{
	int				*array;
	int				i;
	t_elem_of_stack	*tmp;

	tmp = stack->head;
	array = (int *)malloc(sizeof(int) * stack->size);
	if (!array)
		err_arg(2);
	i = 0;
	while (i < stack->size)
	{
		array[i++] = tmp->num;
		tmp = tmp->next;
	}
	sort_array(array, stack->size);
	i = 0;
	while (i < stack->size)
	{
		tmp = stack->head;
		while (tmp->num != array[i])
			tmp = tmp->next;
		tmp->index = i++;
	}
	free(array);
}
