/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:21:01 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/07 18:57:13 by jyniemit         ###   ########.fr       */
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

static int	ft_atoi_isvalid(const char *str, int *result)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		num = num * 10 + (*str - '0');
		if ((sign > 0 && num > INT_MAX) || (sign < 0 && num * sign < INT_MIN))
			return (1);
		str++;
	}
	*result = (int)(num * sign);
	return (0);
}

int	is_valid_number(char *str, int *result)
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
	if (ft_atoi_isvalid(str, result))
		return (1);
	return (0);
}
