#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		l;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = -1;
	j = 0;
	l = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (l + 1));
	if (!new)
		return (0);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
