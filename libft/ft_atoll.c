#include "libft.h"

long long	ft_atoll(const char *str)
{
	long long	ret;
	int			minus;
	int			i;

	ret = 0;
	minus = 1;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return ((long long)INT_MAX + 1);
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	return (ret * minus);
}
