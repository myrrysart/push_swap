/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:39:37 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/09 17:04:41 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	safe_free_split_args(char ***args, int ret)
{
	int	i;

	i = 0;
	while ((*args)[i])
	{
		free((*args)[i]);
		i++;
	}
	free(*args);
	return (ret);
}

static int	handle_arg(char *arg, t_stack *stack_a, t_stack *stack_b)
{
	char	**split_args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (1);
	while (split_args[count])
		count++;
	stack_a->values = malloc(sizeof(int) * count);
	stack_b->values = malloc(sizeof(int) * count);
	if (!stack_b->values || !stack_a->values)
		return (safe_free_split_args(&split_args, 1));
	stack_a->size = count;
	stack_b->size = 0;
	while (i < count)
	{
		if (is_valid_number(split_args[i], &stack_a->values[count - 1 - i]))
			return (safe_free_split_args(&split_args, 1));
		i++;
	}
	return (safe_free_split_args(&split_args, 0));
}

static int	init_stacks(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[j])
		j++;
	j -= 1;
	stack_a->values = ft_calloc(j, sizeof(int));
	if (!stack_a->values)
		return (1);
	stack_b->values = ft_calloc(j, sizeof(int));
	if (!stack_b->values)
		return (1);
	stack_a->size = j;
	while (argv[++i])
	{
		if (is_valid_number(argv[i], &stack_a->values[--j]))
			return (1);
	}
	stack_b->size = 0;
	return (0);
}

static int	handle_initialization(int argc, char **argv, t_stack *stack_a,
		t_stack *stack_b)
{
	if (argc == 2)
	{
		if (handle_arg(argv[1], stack_a, stack_b))
			return (1);
	}
	else
	{
		if (init_stacks(argv, stack_a, stack_b))
			return (1);
	}
	if (check_for_duplicates(stack_a))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*node;
	int		ops;

	ops = 0;
	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_b = ft_calloc(1, sizeof(t_stack));
	node = ft_calloc(1, sizeof(t_node));
	if (!stack_a || !stack_b || !node || argc < 2)
		return (free_stacks(node, stack_a, stack_b, 1));
	if (handle_initialization(argc, argv, stack_a, stack_b))
		return (free_stacks(node, stack_a, stack_b, 1));
	if (handle_small_sort(stack_a, stack_b, &ops))
		return (free_stacks(node, stack_a, stack_b, 0));
	if (stack_a->size > 3)
		sort_turk(stack_a, stack_b, &ops);
	else
		sort_small(stack_a, stack_b, &ops);
	return (free_stacks(node, stack_a, stack_b, 0));
}
