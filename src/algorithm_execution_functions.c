/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_execution_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:02:13 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 16:45:30 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_both_rotations(t_stack *stack_a, t_stack *stack_b, t_node *node,
	int *ops)
{
	while (stack_a->values[stack_a->size - 1] != node->target
		&& stack_b->values[stack_b->size - 1] != node->value)
	{
		if (node->use_ra && node->use_rb)
			operation(RR, stack_a, stack_b, ops);
		else if (!node->use_ra && !node->use_rb)
			operation(RRR, stack_a, stack_b, ops);
		else
			break ;
	}
}

void	execute_a_rotations(t_stack *stack_a, t_stack *stack_b, t_node *node,
	int *ops)
{
	while (stack_a->values[stack_a->size - 1] != node->target)
	{
		if (node->use_ra)
			operation(RA, stack_a, stack_b, ops);
		else
			operation(RRA, stack_a, stack_b, ops);
	}
}

void	execute_b_rotations(t_stack *stack_a, t_stack *stack_b, t_node *node,
	int *ops)
{
	while (stack_b->values[stack_b->size - 1] != node->value)
	{
		if (node->use_rb)
			operation(RB, stack_a, stack_b, ops);
		else
			operation(RRB, stack_a, stack_b, ops);
	}
}

void	execute_operations(t_stack *stack_a, t_stack *stack_b, t_node *node,
	int *ops)
{
	int	costs[4];

	calculate_rotation_costs(stack_a, stack_b, node, costs);
	if (costs[0] <= costs[1])
		node->use_ra = 1;
	else
		node->use_ra = 0;
	if (costs[2] <= costs[3])
		node->use_rb = 1;
	else
		node->use_rb = 0;
	execute_both_rotations(stack_a, stack_b, node, ops);
	execute_a_rotations(stack_a, stack_b, node, ops);
	execute_b_rotations(stack_a, stack_b, node, ops);
	operation(PA, stack_a, stack_b, ops);
}
