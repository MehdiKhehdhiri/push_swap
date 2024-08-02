#include "libft.h"
#include <stdlib.h>

int	ft_intlen(int n)
{
	unsigned int	i;
	unsigned int	un;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	un = n;
	if (un == 0)
		i++;
	while (un > 0)
	{
		i++;
		un = un / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	un;
	int				l;

	result = malloc(sizeof(char) * ft_intlen(n) + 1);
	if (!result)
		return (0);
	l = ft_intlen(n);
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	un = n;
	result[l--] = '\0';
	if (n == 0)
		result[0] = '0';
	while (un > 0)
	{
		result[l--] = (un % 10) + '0';
		un = un / 10;
	}
	return (result);
}
