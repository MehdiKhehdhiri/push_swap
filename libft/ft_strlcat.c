#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[j] && j < size)
		j++;
	while (src[k] != '\0')
		k++;
	if (size == 0 || size <= j)
		return (size + k);
	while (src[i] != '\0' && i < (size - 1 - j))
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + k);
}
