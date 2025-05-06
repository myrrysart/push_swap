/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_execution_functions_helpers.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:37:55 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 16:44:07 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_b_index(t_stack *stack_b, int target_value)
{
	int	b_index;

	b_index = 0;
	while (b_index < stack_b->size)
	{
		if (stack_b->values[b_index] == target_value)
			break ;
		b_index++;
	}
	return (b_index);
}

void	calculate_rotation_costs(t_stack *stack_a, t_stack *stack_b,
		t_node *node, int *costs)
{
	int	a_index;
	int	b_index;

	a_index = node->index;
	b_index = find_b_index(stack_b, node->value);
	if (a_index == stack_a->size - 1)
		costs[0] = 0;
	else
		costs[0] = stack_a->size - 1 - a_index;
	costs[1] = a_index + 1;
	if (b_index == stack_b->size - 1)
		costs[2] = 0;
	else
		costs[2] = stack_b->size - 1 - b_index;
	costs[3] = b_index + 1;
}
