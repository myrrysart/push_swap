/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:21:01 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/07 16:26:59 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_median(t_stack *stack_a, int *median)
{
	int	*copy;
	int	i;
	int	j;
	int	temp;

	i = 1;
	copy = ft_calloc(stack_a->size, sizeof(int));
	if (!copy)
		return ;
	ft_memcpy(copy, stack_a->values, sizeof(int) * stack_a->size);
	while (i < stack_a->size)
	{
		temp = copy[i];
		j = i - 1;
		while (j >= 0 && copy[j] > temp)
		{
			copy[j + 1] = copy[j];
			j--;
		}
		copy[j + 1] = temp;
		i++;
	}
	*median = copy[stack_a->size / 2];
	free(copy);
}
