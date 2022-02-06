/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:09:18 by mbutter           #+#    #+#             */
/*   Updated: 2022/02/04 16:15:06 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_num_util(const char *str, unsigned long n, int flag, int sign)
{
	if (!((*str >= '0' && *str <= '9') || *str == '\0'))
		err_arg(1);
	if (*str == '\0' && flag == 0)
		err_arg(1);
	if (!((sign == 0 && n <= 2147483647) || (sign == 1 && n <= 2147483648)))
		err_arg(1);
}

static void	check_num(const char *str)
{
	int				i;
	unsigned long	n;
	int				sign;
	int				flag;

	i = 0;
	n = 0;
	sign = 0;
	flag = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		flag = 1;
		n = n * 10 + (str[i++] - 48);
	}
	check_num_util(&(str[i]), n, flag, sign);
}

static void	check_dup(t_stack *stack)
{
	int				i;
	t_elem_of_stack	*tmp_i;
	t_elem_of_stack	*tmp_j;

	i = 0;
	tmp_i = stack->head;
	while (i < stack->size)
	{
		tmp_j = tmp_i->next;
		while (tmp_j != stack->head)
		{
			if (tmp_i->num == tmp_j->num)
			{
				delete_stack(stack);
				err_arg(1);
			}
			tmp_j = tmp_j->next;
		}
		i++;
		tmp_i = tmp_i->next;
	}
}

t_stack	*parsing_args(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 1;
	while (i < argc)
		check_num(argv[i++]);
	stack = init_stack(e_stack_a);
	i = 0;
	while (i < argc - 1)
	{
		add_elem(stack, create_elem(ft_atoi(argv[i + 1])));
		i++;
		stack->size++;
	}
	check_dup(stack);
	return (stack);
}

int	check_sort(t_stack *stack)
{
	int				flag;
	t_elem_of_stack	*tmp;

	flag = 0;
	tmp = stack->head;
	while (tmp != stack->head->prev)
	{
		if (tmp->num > tmp->next->num)
		{
			flag = 1;
			return (flag);
		}
		tmp = tmp->next;
	}
	return (flag);
}
