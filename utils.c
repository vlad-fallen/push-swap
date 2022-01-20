/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:41:37 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/20 16:54:00 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void err_arg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void print_operation(enum e_operation id)
{
	if (id == e_op_sa)
		write(1, "sa\n", 3);
	else if (id == e_op_sb)
		write(1, "sb\n", 3);
	else if (id == e_op_ss)
		write(1, "ss\n", 3);
	else if (id == e_op_ra)
		write(1, "ra\n", 3);
	else if (id == e_op_rb)
		write(1, "rb\n", 3);
	else if (id == e_op_rr)
		write(1, "rr\n", 3);
	else if (id == e_op_pa)
		write(1, "pa\n", 3);
	else if (id == e_op_pb)
		write(1, "pb\n", 3);
	else if (id == e_op_rra)
		write(1, "rra\n", 4);
	else if (id == e_op_rrb)
		write(1, "rrb\n", 4);
	else if (id == e_op_rrr)
		write(1, "rrr\n", 4);
}

//УБРАТЬ ФУНКЦИЮ
void print_stack(t_elem_of_stack *start_stack, int size_stack)
{
	int i;
	t_elem_of_stack *tmp;

	i = 0;
	tmp = start_stack;
	while (i < size_stack)
	{
		printf("%d\t", tmp->num);
		tmp = tmp->next;
		i++;
	}
	printf("size: %d\n", size_stack);
}