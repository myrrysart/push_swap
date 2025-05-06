/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:09:10 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 17:14:26 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	safe_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

int	free_stacks(t_node *node, t_stack *stack_a, t_stack *stack_b, int ret)
{
	if (node)
		safe_free(node);
	if (stack_a)
	{
		if (stack_a->values)
			safe_free(stack_a->values);
		safe_free(stack_a);
	}
	if (stack_b)
	{
		if (stack_b->values)
			safe_free(stack_b->values);
		safe_free(stack_b);
	}
	if (ret)
		ft_printf("Error\n");
	return (ret);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
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
