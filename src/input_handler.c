#include "push_swap.h"

void	handle_single_ac(char *ac)
{
	char	**pointer;

	pointer = ft_split(ac, ' ');
	if (pointer == NULL)
		exit (1);
	check_ac(pointer);
	free_pointer(pointer);
}

void	free_pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i] != NULL)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

void	handle_multi_ac(int ac, char **av)
{
	int		i;

	(void)ac;
	i = 0;
	while (av[i + 1])
	{
		if (!validate_ac(av[i + 1], av))
		{
			exit (1);
		}
		i++;
	}
}

t_stack	*create_stack_single(char *ac)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;
	char	**sgl;

	stack = NULL;
	i = 0;
	sgl = ft_split(ac, ' ');
	if (!sgl)
		return (NULL);
	while (sgl[i])
	{
		node = new_node(ft_atoi(sgl[i]));
		if (!node)
		{
			free(sgl);
			return (NULL);
		}
		add_to_stack(&stack, node);
		i++;
	}
	free(sgl);
	return (stack);
}

t_stack	*create_stack_multi(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		node = new_node(ft_atoi(av[i]));
		if (!node)
			return (NULL);
		add_to_stack(&stack, node);
		i++;
	}
	return (stack);
}
