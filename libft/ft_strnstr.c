#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	i = 0;
	j = 0;
	b = (char *) big;
	l = (char *) little;
	if (l[i] == '\0')
		return (b);
	while (b[i] != '\0' && i < len)
	{
		while (b[i + j] == l[j] && i + j < len)
		{
			if (l[j + 1] == '\0')
				return (&b[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
