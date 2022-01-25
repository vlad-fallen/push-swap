/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:53 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/25 18:14:38 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		err_arg(0);
	stack_a = parsing_args(argc, argv);
	stack_b = init_stack(e_stack_b);
	//print_stack(stack_a->head, stack_a->size, stack_a->name_stack);
	//print_stack(stack_b->head, stack_b->size, stack_b->name_stack);
	// op_px(stack_a, stack_b, e_stack_b);
	// op_sx(stack_a, e_stack_a);
	// op_px(stack_b, stack_a, e_stack_a);
	quicksort(stack_a, stack_b, 0);
	//print_stack(stack_a->head, stack_a->size, stack_a->name_stack);
	//print_stack(stack_b->head, stack_b->size, stack_b->name_stack);
	return (0);
}
