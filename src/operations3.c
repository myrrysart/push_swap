/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:25:14 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 17:32:24 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	(void)stack_b;
	i = 0;
	temp = stack_a->values[i];
	while (i < (stack_a->size - 1))
	{
		stack_a->values[i] = stack_a->values[i + 1];
		i++;
	}
	stack_a->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	(void)stack_a;
	i = 0;
	temp = stack_b->values[i];
	while (i < (stack_b->size - 1))
	{
		stack_b->values[i] = stack_b->values[i + 1];
		i++;
	}
	stack_b->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack_b->values[i];
	while (i < (stack_b->size - 1))
	{
		stack_b->values[i] = stack_b->values[i + 1];
		i++;
	}
	stack_b->values[i] = temp;
	i = 0;
	temp = stack_a->values[i];
	while (i < (stack_a->size - 1))
	{
		stack_a->values[i] = stack_a->values[i + 1];
		i++;
	}
	stack_a->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rrr", 1);
}
