#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*substr;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		substr = malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	j = start;
	l = 0;
	while (s[j++] != '\0' && len-- > 0)
		l++;
	substr = malloc(sizeof(char) * (l + 1));
	if (!substr)
		return (0);
	i = -1;
	while (++i < l && s[start + i] != '\0')
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}
