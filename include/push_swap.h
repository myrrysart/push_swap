/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:57:52 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/26 20:05:28 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	struct s_stack *next;
	struct s_stack *prev;
	struct s_stack *target;
	int	value;
	int	from_median;
	int	cost;
}t_stack;

typedef struct s_stacks
{
	t_stack	stack_a;
	t_stack stack_b;
}t_stacks;

typedef int	(*sort_strategy)(t_stacks *stacks, char **ops);

typedef struct s_sort_context
{
	sort_strategy	strategy;
	t_stacks		stacks;
	char			**operations;
} t_sort_context;

#endif
