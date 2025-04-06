#include "../include/nemergent.h"

int	check_extension(char *str)
{
	int	len;

	len = strlen(str);
	if (!strncmp ((str + (len - 4)), ".txt", 4))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	parse_file(char *pathfile, t_data *data)
{
	int		fd;
	char	*line;

	line = NULL;
	if (check_extension(pathfile))
		return (handle_error(ERR_EXT_FILE), EXIT_FAILURE);
	fd = open(pathfile, O_RDONLY);
	if (fd == -1)
		return (perror(ERR_OPEN), EXIT_FAILURE);
	while ((line = gnl(fd)) != NULL)
	{
		get_data(line, data);
		free(line);
	}
	close (fd);
	return (EXIT_SUCCESS);
}

char	*gnl(int fd)
{
	static char		buffer[BUF_SIZE];
	static ssize_t	buf_pos = 0;
	static ssize_t	buf_len = 0;
	char 			*line = NULL;
	size_t 			line_len = 0;

	while (1)
	{
		if (buf_pos >= buf_len)
		{
			buf_len = read(fd, buffer, BUF_SIZE);
			if (buf_len <= 0)
				break ;
			buf_pos = 0;
		}
		char c = buffer[buf_pos++];
		char *new_line = realloc(line, line_len + 2); 
		if (!new_line)
		{
			free(line);
			return (NULL);
		}
		line = new_line;
		line[line_len++] = c;
		if (c == '\n')
			break ;
	}
	if (line_len == 0)
		return (NULL);
	line[line_len] = '\0';
	return (line);
}

char	*strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && strchr(set, s1[start]))
		start++;
	end = strlen(s1);
	while (end > start && strchr(set, s1[end - 1]))
		end--;
	trimmed = malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	strncpy(trimmed, s1 + start, end - start);
	trimmed[end - start] = '\0';
	return (trimmed);
}

char *is_key_value(char *line, char *key)
{
	char	**splited;
	char	*value = NULL;
	char	*trimmed_key = NULL;
	char	*trimmed_eq = NULL;
	char	*trimmed_value = NULL;

	if( !line || !key)
		return (NULL);
	splited = ft_split(line, ' ');
	if (!splited || !splited[0] || !splited[1] || !splited[2])
		return (free_mat(splited), NULL);
	trimmed_key = strtrim(splited[0], "\t\n\r\v\f");
	trimmed_eq = strtrim(splited[1], "\t\n\r\v\f");
	trimmed_value = strtrim(splited[2], "\t\n\r\v\f");
	if (trimmed_key && !str_equal(trimmed_key, key) && !str_equal(trimmed_eq, "="))
		value = strdup(trimmed_value);
    free(trimmed_value);
	free(trimmed_eq);
    free(trimmed_key);
	free_mat(splited);
	return (value);
}

void	get_data(char *line, t_data *data)
{
    char	*value;
    if ((value = is_key_value(line, NB_PER_THREAD)))
    {
        data->nb_per_thread = atoi(value);
        free(value);
    }
    if ((value = is_key_value(line, THREAD_NUM)))
	{
		data->thread_num = atoi(value);
		free(value);
	}
}

void free_mat(char **matrix)
{
	int i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
        i++;
	}
	free(matrix);
}

int	check_file(char *pathfile, t_data *data)
{
	if (parse_file(pathfile, data))
		return (EXIT_FAILURE);
	if (data->nb_per_thread <= 0 || data->thread_num <= 0)
		return (handle_error(ERR_NO_DATA), EXIT_FAILURE);
	if (data->nb_per_thread >= INT_MAX || data->thread_num >= INT_MAX)
		return (handle_error(ERR_INT_MAX), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
