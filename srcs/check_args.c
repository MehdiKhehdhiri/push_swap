#include "../push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_error_args(int argc, char **args)
{
	if (argc == 2)
		ft_free(args);
	ft_error("Error");
}

void	ft_check_args(int argc, char **argv)
{
	int			i;
	long long	tmp;
	char		**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		if (ft_strlen(args[i]) > 11)
			ft_error_args(argc, args);
		tmp = ft_atoll(args[i]);
		if ((tmp < -2147483648 || tmp > 2147483647)
			|| !ft_isnum(args[i]) || ft_contains(tmp, args, i))
			ft_error_args(argc, args);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
