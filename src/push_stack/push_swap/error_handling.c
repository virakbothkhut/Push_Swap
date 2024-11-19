#include "push_stack.h"
#include "push_swap.h"
#include "utils.h"
#include "validation.h"

void	show_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	*allocate_memory(int size)
{
	int	*arr;

	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		show_error();
	}
	return (arr);
}
void	convert_t_integer(int ac, char **av, int *arr)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		arr[i] = atoi(av[i + 1]);
		i++;
	}
}

int	validate_argc(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!valid_integer(av[i]) || !with_range(av[i]))
		{
			show_error();
			return (1);
		}
		i++;
	}
	return (0);
}

int	handle_errors(int ac, char **av, t_stack *stack)
{
	int	*arr;

	if (ac == 1)
		return (0);
	if (validate_argc(ac, av))
		return (1);
	arr = allocate_memory(ac - 1);
	if (!arr)
		return (1);
	convert_t_integer(ac, av, arr);
	append_stack(stack, arr, ac - 1);
	if (duplicates(stack))
	{
		free(arr);
		free_stack(stack);
		show_error();
		return (1);
	}
	free(arr);
	return (0);
}
