/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:37:06 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/02 17:01:16 by mbutter          ###   ########.fr       */
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
		err_arg(2);
	return (new);
}

void	add_elem(t_stack *stack, t_elem_of_stack *elem)
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

t_stack	*init_stack(enum e_stack e_name_stack)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		err_arg(2);
	stack->head = NULL;
	stack->size = 0;
	stack->name_stack = e_name_stack;
	return (stack);
}

static void	delete_elem(t_elem_of_stack *elem)
{
	if (elem == NULL)
		return ;
	elem->next = NULL;
	elem->prev = NULL;
	free(elem);
}

void	delete_stack(t_stack *stack)
{
	t_elem_of_stack	*tmp;
	int				i;

	i = 0;
	if (stack == NULL)
		return ;
	if (stack->head != NULL)
	{
		while (i++ < stack->size)
		{
			tmp = stack->head;
			stack->head = stack->head->next;
			delete_elem(tmp);
		}
	}
	free(stack);
}
