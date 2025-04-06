#include "../include/nemergent.h"

int check_args(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		return (handle_error(ERR_NB_ARGS),EXIT_FAILURE);
	if (!help_flag(argv[1]))
		return (help_doc(), EXIT_FAILURE);
	if (!file_flag(argv[1]))
    {
        if (argc != 3)
			return (handle_error(ERR_ROOT_FILE),EXIT_FAILURE);
		return (EXIT_SUCCESS);
    }
	return (handle_error(ERR_ARGS),EXIT_FAILURE);
}

int	str_equal(char *s1, char *s2)
{
	int	len1;
	int	len2;
	
	len1 = strlen(s1);
  	len2 = strlen(s2);
 	if ((len1 == len2) && !strncmp(s1,s2, len1))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int help_flag(char *arg)
{
	if (!str_equal(arg, "-h"))
		return (EXIT_SUCCESS);
	else if (!str_equal(arg, "--help"))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int file_flag(char *arg)
{
	if (!str_equal(arg, "-f"))
		return (EXIT_SUCCESS);
	else if (!str_equal(arg, "--file")) 
		return (EXIT_SUCCESS);
    else
		return (EXIT_FAILURE);  
}

void	help_doc(void)
{
	write(1, HELP_MSG, strlen(HELP_MSG));
	write(1, "\n", 1);	
}
