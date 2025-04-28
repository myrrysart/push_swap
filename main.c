#include "push_swap.h"

typedef struct s_struct
{
	int	values[MAX_SIZE];
	int	size;
} t_struct;

int	main(int argc, char **argv)
{
	t_struct	*stack_a;
	t_struct	*stack_b;

	stack_b = NULL;
	if (argc == 2)
		parse_to_stack(argv[1], stack_a);
	else
	{
		ft_printf("0.1: No proper argument handling implemented");
		return (1);
	}
	while (i > stack_a.size)
		ft_printf("%d\n", stack_a.values[i++]);
	return (0);
}
