/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:09:10 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/09 17:13:10 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	safe_free(void **ptr)
{
	if (ptr != NULL)
	{
		if (*ptr != NULL)
		{
			free(*ptr);
			*ptr = NULL;
		}
	}
}

int	free_stacks(t_node *node, t_stack *stack_a, t_stack *stack_b, int ret)
{
	safe_free((void **)&node);
	if (stack_a != NULL)
	{
		safe_free((void **)&stack_a->values);
		safe_free((void **)&stack_a);
	}
	if (stack_b != NULL)
	{
		safe_free((void **)&stack_b->values);
		safe_free((void **)&stack_b);
	}
	if (ret)
		ft_printf("Error\n");
	return (ret);
}

int	check_for_duplicates(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a->size)
	{
		while (j < i)
		{
			if (stack_a->values[i] == stack_a->values[j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	top;
	int	middle;
	int	bottom;

	if (is_sorted(stack_a))
		return ;
	top = stack_a->values[stack_a->size - 1];
	middle = stack_a->values[stack_a->size - 2];
	bottom = stack_a->values[stack_a->size - 3];
	if (top > middle && middle > bottom)
	{
		operation(SA, stack_a, stack_b, ops);
		operation(RRA, stack_a, stack_b, ops);
	}
	else if (top < middle && middle > bottom && top > bottom)
		operation(RRA, stack_a, stack_b, ops);
	else if (top > middle && middle < bottom && top > bottom)
		operation(RA, stack_a, stack_b, ops);
	else if (top < middle && middle > bottom && top < bottom)
	{
		operation(SA, stack_a, stack_b, ops);
		operation(RA, stack_a, stack_b, ops);
	}
	else if (top > middle && middle < bottom && top < bottom)
		operation(SA, stack_a, stack_b, ops);
}
