#ifndef FUNCTIONS_H
# define FUNCTIONS_h

/* check_args.c*/
int	check_args(int argc, char **argv);
int	str_equal(char *s1, char *s2);
int	help_flag(char *arg);
int	file_flag(char *arg);
void	help_doc(void);

/* aux.c */
void	print_error(char *str, int i);
int		handle_error(int error_type);

/* parse_file.c */
int		check_extension(char *str);
int		parse_file(char *pathfile, t_data *data);
char	*gnl(int fd);
char	*strtrim(const char *s1, const char *set);
char	*is_key_value(char *line, char *key);
void	get_data(char *line, t_data *data);
void	free_mat(char **matrix);
int		handle_error(int error_type);
int		check_file(char *pathfile, t_data *data);

/* ft_split.c */
char	**ft_split(char const *s, char c);

/* main.c */
void	init_data(t_data *data);
void	print_list(t_list *list);

/* threads.c */
int		init_threads(t_data *data);
int		join_threads(t_data *data);
void	destroy_mutex(t_data *data);

/* routine.c */
void	*routine(void *arg);
void	add_node(t_list **list, int num, t_data *data, int class);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		is_duplicated(int *arr, int size, int value);;

# endif