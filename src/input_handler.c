#include "push_swap.h"

void	handle_single_ac(char *ac)
{
	char	**pointer;

	pointer = ft_split(ac, ' ');
	if (pointer == NULL)
		exit (1);
	split_ac(ac, pointer);
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
