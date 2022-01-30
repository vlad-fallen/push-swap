/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:37:06 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/29 14:10:49 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem_of_stack	*create_elem(int num)
{
	t_elem_of_stack	*new;

	new = (t_elem_of_stack *)malloc(sizeof(t_elem_of_stack));
	if (new != NULL)
	{
		new->num = num;
		new->next = NULL;
		new->prev = NULL;
		new->markup = 0;
	}
	else
		exit(EXIT_FAILURE);
	return (new);
}

void add_elem(t_stack *stack, t_elem_of_stack *elem)
{
	t_elem_of_stack	*tmp;

	if (stack && elem)
	{
		if (stack->head != NULL)
		{
			tmp = stack->head->prev;
			elem->prev = tmp;
			tmp->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
		}
		else
		{
			stack->head = elem;
			stack->head->next = elem;
			stack->head->prev = elem;
		}
	}
}

t_stack *init_stack(enum e_stack e_name_stack)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		err_arg(5);		// убрать цифры!!
	stack->head = NULL;
	stack->size = 0;
	stack->name_stack = e_name_stack;
	return (stack);
}

/*t_stack *create_stack(int *array, int size_arr)
{
	int i;
	t_stack *stack;

	i = 0;
	stack = NULL;
	init_stack();
	while (i < size_arr - 1)
		add_elem(stack, create_elem(array[i++]));
	stack->size_a = size_arr;
	return(stack);
}*/
