#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		l;
	char	*dup;

	i = -1;
	l = ft_strlen(s);
	dup = malloc(sizeof(char) * (l + 1));
	if (!dup)
		return (0);
	while (s[++i] != '\0')
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
