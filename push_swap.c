/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:53 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/24 18:23:40 by mbutter          ###   ########.fr       */
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
	print_stack(stack_a->head, stack_a->size);
	print_stack(stack_b->head, stack_b->size);
	//op_px(stack_a, stack_b, e_stack_b);
	quicksort(stack_a, stack_b, 0);
	print_stack(stack_a->head, stack_a->size);
	print_stack(stack_b->head, stack_b->size);
	return (0);
}
