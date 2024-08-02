#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = ft_strlen(s);
	while (c > 256)
		c -= 256;
	while (l >= 0)
	{
		if (s[l] == (char) c)
			return ((char *)s + l);
		l--;
	}
	return (NULL);
}
