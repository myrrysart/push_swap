/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:21:02 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 17:21:17 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	if (stack_b->size == 0)
		return ;
	stack_a->values[stack_a->size] = stack_b->values[stack_b->size - 1];
	stack_b->size--;
	stack_a->size++;
	(*ops)++;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	if (stack_a->size == 0)
		return ;
	stack_b->values[stack_b->size] = stack_a->values[stack_a->size - 1];
	stack_a->size--;
	stack_b->size++;
	(*ops)++;
	ft_putendl_fd("pb", 1);
}

void	ra(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	i = stack_a->size - 1;
	(void)stack_b;
	temp = stack_a->values[i];
	while (i > 0)
	{
		stack_a->values[i] = stack_a->values[i - 1];
		i--;
	}
	stack_a->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	i = stack_b->size - 1;
	(void)stack_a;
	temp = stack_b->values[i];
	while (i > 0)
	{
		stack_b->values[i] = stack_b->values[i - 1];
		i--;
	}
	stack_b->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;
	int	i;

	i = stack_b->size - 1;
	temp = stack_b->values[i];
	while (i > 0)
	{
		stack_b->values[i] = stack_b->values[i - 1];
		i--;
	}
	stack_b->values[i] = temp;
	i = stack_a->size - 1;
	temp = stack_a->values[i];
	while (i > 0)
	{
		stack_a->values[i] = stack_a->values[i - 1];
		i--;
	}
	stack_a->values[i] = temp;
	(*ops)++;
	ft_putendl_fd("rr", 1);
}
