#include "push_swap.h"

typedef struct s_struct
{
	int	*values;
	int	size;
} t_struct;

void	init_stacks(char **argv, t_struct *stack_a, t_struct *stack_b)
{
	int	i = 0;
	int j = 0;
	while (argv[j])
		j++;
	j -= 1;
	stack_a->values = malloc(sizeof(int) * j);
	stack_b->values = malloc(sizeof(int) * j);
	stack_a->size = j;
	while (argv[++i])
		stack_a->values[--j] = ft_atoi(argv[i]);
	stack_b->size = 0;
}

int	main(int argc, char **argv)
{
	t_struct	*stack_a = malloc(sizeof(t_struct));
	t_struct	*stack_b = malloc(sizeof(t_struct));
	int			i = 0;

	argc = 0;
	init_stacks(argv, stack_a, stack_b);
	while (i < stack_a->size)
		ft_printf("%d\n", stack_a->values[i++]);
	free(stack_a->values);
	free(stack_a);
	free(stack_b->values);
	free(stack_b);
	return (0);
}
