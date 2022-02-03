/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:24:39 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/03 17:43:05 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	execution_op(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		op_sx(stack_a, stack_a->name_stack, 0);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		op_sx(stack_b, stack_b->name_stack, 0);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		op_ss(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		op_rx(stack_a, stack_a->name_stack, 0);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		op_rx(stack_b, stack_b->name_stack, 0);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		op_rr(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		op_px(stack_b, stack_a, stack_a->name_stack, 0);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		op_px(stack_a, stack_b, stack_b->name_stack, 0);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		op_rrx(stack_a, stack_a->name_stack, 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		op_rrx(stack_b, stack_b->name_stack, 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		op_rrr(stack_a, stack_b, 0);
	else
		err_arg(1);
}

static void	read_operation(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execution_op(stack_a, stack_b, line);
		free (line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		err_arg(0);
	stack_a = parsing_args(argc, argv);
	stack_b = init_stack(e_stack_b);
	if (stack_a->size > 0)
	{
		read_operation(stack_a, stack_b);
		if (!check_sort(stack_a) && stack_b->size == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	delete_stack(stack_a);
	delete_stack(stack_b);
	return (0);
}
