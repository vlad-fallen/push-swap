/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:53 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/03 17:04:39 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_selection(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_3_elements(stack_a);
	else
		quicksort(stack_a, stack_b, 0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		err_arg(0);
	stack_a = parsing_args(argc, argv);
	stack_b = init_stack(e_stack_b);
	parsing_index(stack_a);
	if (check_sort(stack_a))
		sorting_selection(stack_a, stack_b);
	delete_stack(stack_a);
	delete_stack(stack_b);
	return (0);
}
