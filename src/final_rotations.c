/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:51:04 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 16:53:29 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_index_in_stack(t_stack *stack)
{
	int	smallest_index;
	int	i;

	smallest_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->values[i] < stack->values[smallest_index])
			smallest_index = i;
		i++;
	}
	return (smallest_index);
}

static void	rotate_up_to_top(t_stack *stack_a, t_stack *stack_b, int index,
		int *ops)
{
	while (index < stack_a->size - 1)
	{
		operation(RA, stack_a, stack_b, ops);
		index++;
	}
}

static void	rotate_down_to_top(t_stack *stack_a, t_stack *stack_b,
		int rotations_needed, int *ops)
{
	int	i;

	i = 0;
	while (i < rotations_needed)
	{
		operation(RRA, stack_a, stack_b, ops);
		i++;
	}
}

void	final_rotate(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	smallest_index;
	int	rotations_needed;

	smallest_index = find_smallest_index_in_stack(stack_a);
	if (smallest_index == stack_a->size - 1)
		return ;
	if (smallest_index >= stack_a->size / 2)
	{
		rotate_up_to_top(stack_a, stack_b, smallest_index, ops);
	}
	else
	{
		rotations_needed = smallest_index + 1;
		rotate_down_to_top(stack_a, stack_b, rotations_needed, ops);
	}
}
