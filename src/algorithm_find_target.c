/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_find_target.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:23:33 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 15:28:13 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_index(t_stack *stack);
static int	find_smallest_bigger_target(t_stack *stack_a, t_node *node);

void	find_target(t_stack *stack_a, t_stack *stack_b, t_node *node,
		int b_index)
{
	int	smallest_index;
	int	found_target;

	smallest_index = find_smallest_index(stack_a);
	node->value = stack_b->values[b_index];
	found_target = find_smallest_bigger_target(stack_a, node);
	if (!found_target)
	{
		node->target = stack_a->values[smallest_index];
		node->index = smallest_index;
	}
}

static int	find_smallest_index(t_stack *stack)
{
	int	i;
	int	smallest_index;
	int	smallest_value;

	smallest_value = stack->values[0];
	smallest_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->values[i] < smallest_value)
		{
			smallest_value = stack->values[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

static int	find_smallest_bigger_target(t_stack *stack_a, t_node *node)
{
	int	i;
	int	found_target;

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
	return (found_target);
}
