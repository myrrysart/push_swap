/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:57:52 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/29 19:00:39 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef MAX_SIZE
#  define MAX_SIZE 500
# endif

# include "libft.h"

typedef struct s_stack
{
	int	*values;
	int	size;
} t_stack;

enum e_op
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

typedef void (*t_operation)(t_stack*, t_stack*, int*);

#endif
