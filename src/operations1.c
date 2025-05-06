/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:15:58 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/06 17:19:18 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;

	(void)stack_b;
	if (stack_a->size < 2)
		return ;
	temp = stack_a->values[stack_a->size - 1];
	stack_a->values[stack_a->size - 1] = stack_a->values[stack_a->size - 2];
	stack_a->values[stack_a->size - 2] = temp;
	(*ops)++;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;

	(void)stack_a;
	if (stack_b->size < 2)
		return ;
	temp = stack_b->values[stack_b->size - 1];
	stack_b->values[stack_b->size - 1] = stack_b->values[stack_b->size - 2];
	stack_b->values[stack_b->size - 2] = temp;
	(*ops)++;
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int *ops)
{
	int	temp;

	temp = stack_b->values[stack_b->size - 1];
	stack_b->values[stack_b->size - 1] = stack_b->values[stack_b->size - 2];
	stack_b->values[stack_b->size - 2] = temp;
	temp = stack_a->values[stack_a->size - 1];
	stack_a->values[stack_a->size - 1] = stack_a->values[stack_a->size - 2];
	stack_a->values[stack_a->size - 2] = temp;
	(*ops)++;
	ft_putendl_fd("ss", 1);
}

void	operation(enum e_op op, t_stack *stack_a, t_stack *stack_b, int *ops)
{
	t_operation	operations[11];

	operations[PA] = &pa;
	operations[PB] = &pb;
	operations[SA] = &sa;
	operations[SB] = &sb;
	operations[RA] = &ra;
	operations[RB] = &rb;
	operations[RRA] = &rra;
	operations[RRB] = &rrb;
	operations[SS] = &ss;
	operations[RR] = &rr;
	operations[RRR] = &rrr;
	if (op >= 0 && op < 11)
		operations[op](stack_a, stack_b, ops);
}
