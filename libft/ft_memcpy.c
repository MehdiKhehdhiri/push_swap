#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	while (i < n)
	{
		*((char *)d + i) = *((char *)s + i);
		i++;
	}
	return (d);
}
