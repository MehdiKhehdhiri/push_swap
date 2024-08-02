#include "libft.h" 

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 1;
	if (!d && !s)
		return (NULL);
	if (s < d)
	{	
		while (i <= n)
		{	
			d[n - i] = s[n - i];
			i++;
		}
	}
	else
		while (n-- > 0)
			*(d++) = *(s++);
	return (dest);
}
