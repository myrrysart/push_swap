/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:57:52 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/07 12:38:43 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int			*values;
	int			size;
}				t_stack;

typedef struct s_node
{
	int			value;
	int			index;
	int			target;
	int			cost_a;
	int			cost_b;
	int			total_cost;
	int			use_ra;
	int			use_rb;
}				t_node;
enum			e_op
{
	PA,
	PB,
	SA,
	SB,
	RA,
	RB,
	RRA,
	RRB,
	SS,
	RR,
	RRR
};

typedef void	(*t_operation)(t_stack *, t_stack *, int *);

// sorting
void			sort_turk(t_stack *stack_a, t_stack *stack_b, int *ops);
void			operation(enum e_op op, t_stack *stack_a, t_stack *stack_b,
					int *ops);
void			sort_small(t_stack *stack_a, t_stack *stack_b, int *ops);
void			find_median(t_stack *stack_a, int *median);
void			find_target(t_stack *stack_a, t_stack *stack_b, t_node *node,
					int b_index);
void			execute_operations(t_stack *stack_a, t_stack *stack_b,
					t_node *node, int *ops);
void			calculate_rotation_costs(t_stack *stack_a, t_stack *stack_b,
					t_node *node, int *costs);
void			final_rotate(t_stack *stack_a, t_stack *stack_b, int *ops);
int				check_for_duplicates(t_stack *stack_a);
void			sort_small(t_stack *stack_a, t_stack *stack_b, int *ops);
void			safe_free(void **ptr);
int				free_stacks(t_node *node, t_stack *stack_a, t_stack *stack_b,
					int ret);
int				is_valid_number(char *str);
int				is_sorted(t_stack *stack);
// Operations
void			operation(enum e_op op, t_stack *stack_a, t_stack *stack_b,
					int *ops);
void			sa(t_stack *stack_a, t_stack *stack_b, int *ops);
void			sb(t_stack *stack_a, t_stack *stack_b, int *ops);
void			ss(t_stack *stack_a, t_stack *stack_b, int *ops);
void			pa(t_stack *stack_a, t_stack *stack_b, int *ops);
void			pb(t_stack *stack_a, t_stack *stack_b, int *ops);
void			ra(t_stack *stack_a, t_stack *stack_b, int *ops);
void			rb(t_stack *stack_a, t_stack *stack_b, int *ops);
void			rr(t_stack *stack_a, t_stack *stack_b, int *ops);
void			rra(t_stack *stack_a, t_stack *stack_b, int *ops);
void			rrb(t_stack *stack_a, t_stack *stack_b, int *ops);
void			rrr(t_stack *stack_a, t_stack *stack_b, int *ops);
//main helpers
int				handle_small_sort(t_stack *stack_a, t_stack *stack_b, int *ops);
#endif
