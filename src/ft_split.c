#include "../include/nemergent.h"

static size_t	count_splits(char const *s, char c)
{
	size_t	split;
	int		in_split;

	split = 0;
	in_split = 0;
	if (s == NULL || *s == '\0')
		split = 0;
	while (*s != '\0')
	{
		if (*s == c)
			in_split = 0;
		else
		{
			if (in_split == 0)
			{
				split++;
				in_split = 1;
			}
		}
		s++;
	}
	return (split);
}

static size_t	count_split_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	**free_matrix(char **matrix, size_t len_matrix)
{
	while (len_matrix--)
		free((void *)matrix[len_matrix]);
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	j;
	size_t	subs_len;

	i = 0;
	j = 0;
	matrix = (char **)malloc((count_splits(s, c) + 1) * sizeof(char *));
	if (!matrix || !s)
		return (NULL);
    while (i < count_splits(s, c))
    {
        while (s[j] == c && s[j] != '\0')
            j++;
        if (s[j] != c && s[j] != '\0')
            subs_len = count_split_len(s + j, c);
        matrix[i] = (char *)malloc((subs_len + 1) * sizeof(char));
        if (!matrix[i])
            return (free_matrix(matrix, i));
        strncpy(matrix[i], s + j, subs_len);
        matrix[i][subs_len] = '\0';  // ✅ aquí está la clave
        i++;
        j += subs_len;
    }
	matrix[i] = NULL;
	return (matrix);
}