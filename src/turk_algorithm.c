/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:48:45 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 16:59:21 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pre_sort_to_stack_b(t_stack *stack_a, t_stack *stack_b, int median,
		int *ops)
{
	while (stack_a->size > 3)
	{
		if (stack_a->values[stack_a->size - 1] < median)
		{
			operation(PB, stack_a, stack_b, ops);
			operation(RB, stack_a, stack_b, ops);
		}
		else
			operation(PB, stack_a, stack_b, ops);
	}
}

void	find_cheapest_node(t_stack *stack_a, t_stack *stack_b,
		t_node *cheapest_node)
{
	t_node	current_node;
	int		i;

	cheapest_node->total_cost = INT_MAX;
	i = 0;
	while (i < stack_b->size)
	{
		find_target(stack_a, stack_b, &current_node, i);
		calculate_cost(stack_a, stack_b, &current_node, i);
		if (current_node.total_cost < cheapest_node->total_cost)
			*cheapest_node = current_node;
		i++;
	}
}

void	sort_turk(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	t_node	cheapest_node;
	int		median;

	find_median(stack_a, &median);
	pre_sort_to_stack_b(stack_a, stack_b, median, ops);
	sort_small(stack_a, stack_b, ops);
	while (stack_b->size > 0)
	{
		find_cheapest_node(stack_a, stack_b, &cheapest_node);
		execute_operations(stack_a, stack_b, &cheapest_node, ops);
	}
	final_rotate(stack_a, stack_b, ops);
}
