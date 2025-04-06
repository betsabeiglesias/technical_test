#ifndef FUNCTIONS_H
# define FUNCTIONS_H

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

/* sort.c */
t_list	*sort_list(t_list *list);
int		*list_to_array(t_list *list);
t_list	*array_to_list(int *arr, int size);
t_list	*ft_lstnew(int nb);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_bubble_sort(int *array, int size);
int		ft_array_is_sorted(int *array, int size);
void	ft_swap_nbr(int *a, int *b);
void	final_list(t_list *list, char *class);

# endif