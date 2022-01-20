/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:18 by mbutter           #+#    #+#             */
/*   Updated: 2022/01/20 15:59:32 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_num(const char *str)
{
	int	i;
	unsigned int	n;
	int sign;
	
	i = 0;
	n = 0;
	sign = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '-')
		sign = sign * (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '\0'))
		err_arg();
	if (str[i] == '\0' && n == 0)
		err_arg();
	if (!((sign == 0 && n <= 2147483647) || (sign == 1 && n <= 2147483648)))
		err_arg();
}

t_stack *parsing_args(int argc, char **argv)
{
	t_stack *stack;
	int i;

	i = 1;
	while (i < argc)
		check_num(argv[i++]);
	stack = init_stack();
	i = 0;

	while (i < argc - 1)
	{
		add_elem(stack, create_elem(ft_atoi(argv[i + 1])));
		i++;
		stack->size++;
	}
	return (stack);
}
