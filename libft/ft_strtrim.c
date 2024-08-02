#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		l;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	l = ft_strlen(s1);
	while (l && ft_strchr(set, s1[l]))
		l--;
	trim = ft_substr(&s1[i], 0, l - i + 1);
	return (trim);
}
