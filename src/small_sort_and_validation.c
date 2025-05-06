/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_and_validation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:51:33 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 18:51:42 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_small_sort(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	if (stack_a->size == 2 || is_sorted(stack_a))
	{
		if (stack_a->size == 2 && stack_a->values[1] > stack_a->values[0])
			operation(SA, stack_a, stack_b, ops);
		return (1);
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->size <= 1)
		return (1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->values[i] < stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}
