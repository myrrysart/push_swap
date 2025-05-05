/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:48:45 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/05 17:50:12 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_stack *stack_a, t_stack *stack_b, t_node *node,
		int b_index)
{
	int	i;
	int	smallest_index;
	int	smallest_value;
	int	found_target;

	smallest_value = stack_a->values[0];
	smallest_index = 0;
	i = 1;
	while (i < stack_a->size)
	{
		if (stack_a->values[i] < smallest_value)
		{
			smallest_value = stack_a->values[i];
			smallest_index = i;
		}
		i++;
	}
	node->value = stack_b->values[b_index];
	node->target = INT_MAX;
	found_target = 0;
	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->values[i] > node->value
			&& stack_a->values[i] < node->target)
		{
			node->target = stack_a->values[i];
			node->index = i;
			found_target = 1;
		}
		i++;
	}
	if (!found_target)
	{
		node->target = smallest_value;
		node->index = smallest_index;
	}
}

void	calculate_cost(t_stack *stack_a, t_stack *stack_b, t_node *node,
		int b_index)
{
	if (node->index <= stack_a->size / 2)
		node->cost_a = node->index;
	else
		node->cost_a = stack_a->size - node->index;
	if (b_index <= stack_b->size / 2)
		node->cost_b = b_index;
	else
		node->cost_b = stack_b->size - b_index;
	node->total_cost = node->cost_a + node->cost_b;
}
void	execute_operations(t_stack *stack_a, t_stack *stack_b, t_node *node,
		int *ops)
{
	int	b_index;
	int	a_index;
	int	ra_cost;
	int	rra_cost;
	int	rb_cost;
	int	rrb_cost;
	int	use_ra;
	int	use_rb;

	a_index = node->index;
	for (b_index = 0; b_index < stack_b->size; b_index++)
	{
		if (stack_b->values[b_index] == node->value)
			break ;
	}
	ra_cost = (a_index == stack_a->size - 1) ? 0 : stack_a->size - 1 - a_index;
	rra_cost = a_index + 1;
	rb_cost = (b_index == stack_b->size - 1) ? 0 : stack_b->size - 1 - b_index;
	rrb_cost = b_index + 1;
	use_ra = (ra_cost <= rra_cost);
	use_rb = (rb_cost <= rrb_cost);
	while (stack_a->values[stack_a->size - 1] != node->target
		&& stack_b->values[stack_b->size - 1] != node->value)
	{
		if (use_ra && use_rb)
			operation(RR, stack_a, stack_b, ops);
		else if (!use_ra && !use_rb)
			operation(RRR, stack_a, stack_b, ops);
		else
			break ;
	}
	while (stack_a->values[stack_a->size - 1] != node->target)
	{
		if (use_ra)
			operation(RA, stack_a, stack_b, ops);
		else
			operation(RRA, stack_a, stack_b, ops);
	}
	while (stack_b->values[stack_b->size - 1] != node->value)
	{
		if (use_rb)
			operation(RB, stack_a, stack_b, ops);
		else
			operation(RRB, stack_a, stack_b, ops);
	}
	operation(PA, stack_a, stack_b, ops);
}

void	final_rotate(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	smallest_index;
	int	i;
	int	rotations_needed;

	smallest_index = 0;
	for (i = 1; i < stack_a->size; i++)
	{
		if (stack_a->values[i] < stack_a->values[smallest_index])
			smallest_index = i;
	}
	if (smallest_index == stack_a->size - 1)
		return ;
	if (smallest_index >= stack_a->size / 2)
	{
		while (smallest_index < stack_a->size - 1)
		{
			operation(RA, stack_a, stack_b, ops);
			smallest_index++;
		}
	}
	else
	{
		rotations_needed = smallest_index + 1;
		for (i = 0; i < rotations_needed; i++)
			operation(RRA, stack_a, stack_b, ops);
	}
}

void	sort_turk(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	t_node	cheapest_node;
	int		i;
	t_node	current_node;

	while (stack_a->size > 3)
		operation(PB, stack_a, stack_b, ops);
	sort_small(stack_a, stack_b, ops);
	while (stack_b->size > 0)
	{
		cheapest_node.total_cost = INT_MAX;
		i = 0;
		while (i < stack_b->size)
		{
			find_target(stack_a, stack_b, &current_node, i);
			calculate_cost(stack_a, stack_b, &current_node, i);
			if (current_node.total_cost < cheapest_node.total_cost)
				cheapest_node = current_node;
			i++;
		}
		execute_operations(stack_a, stack_b, &cheapest_node, ops);
	}
	final_rotate(stack_a, stack_b, ops);
}
