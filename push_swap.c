/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:53 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/20 18:25:40 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		err_arg();
	stack_a = parsing_args(argc, argv);
	stack_b = init_stack();
	print_stack(stack_a->head, stack_a->size);
	print_stack(stack_b->head, stack_b->size);
	op_px(stack_a, stack_b, e_op_ra);
	print_stack(stack_a->head, stack_a->size);
	print_stack(stack_b->head, stack_b->size);
	return (0);
}
