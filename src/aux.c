#include "../include/nemergent.h"

void	print_error(char *str, int i)
{
	if (!str)
		return ;
	write(i, str, strlen(str));
	write(i, "\n", 1);
}

int	handle_error(int error_type)
{
	if (error_type == ERR_NB_ARGS)
		print_error(ERR_MSG_NB_ARGS, 1);
	if (error_type == ERR_ROOT_FILE)
		print_error(ERR_MSG_ROOT_FILE, 1);
	if (error_type == ERR_ARGS)
		print_error(ERR_MSG_ARGS, 1);
	if (error_type == ERR_EXT_FILE)
		print_error(ERR_MSG_EXT_FILE, 1);
	if (error_type == ERR_NO_DATA)
		print_error(ERR_MSG_NO_DATA, 1);
	if (error_type == ERR_INT_MAX)
		print_error(ERR_MSG_INT_MAX, 1);
	return (EXIT_FAILURE);
}