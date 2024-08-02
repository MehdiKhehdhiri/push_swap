#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			i++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (i);
}

char	*words(char const *s, int start, int end, char **split)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	j = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
	{
		while (split[j])
		{
			free (split[j]);
			j++;
		}
		free (split);
		return (0);
	}
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**split_logic(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	int		flag;
	char	*word;

	i = -1;
	j = 0;
	flag = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || i == ft_strlen(s)) && flag >= 0)
		{
			word = words(s, flag, i, split);
			if (!word)
				return (0);
			split[j++] = word;
			flag = -1;
		}
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (0);
	if (!split_logic(s, c, split))
		return (0);
	return (split);
}
