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


# endif