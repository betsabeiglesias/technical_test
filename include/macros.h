#ifndef MACROS_H
# define MACROS_H




# define HELP_MSG 			"Usage: ./technical_test -f|--file <path/to/config_file.txt> (must be a .txt file)"

# define BUF_SIZE			42
# define NB_PER_THREAD		"numbers_per_thread"
# define THREAD_NUM			"thread_num"


# define ERR_NB_ARGS		1
# define ERR_ROOT_FILE		2
# define ERR_ARGS			3
# define ERR_EXT_FILE		4
# define ERR_NO_DATA		5
# define ERR_INT_MAX		6





# define ERR_MSG_NB_ARGS	"Incorrect number of arguments"
# define ERR_MSG_ROOT_FILE	"Root config file is required"
# define ERR_MSG_ARGS		"Invalid argument: Use -h or --help for usage information"
# define ERR_MSG_EXT_FILE	"Incorrect extension file"
# define ERR_MSG_NO_DATA	"Invalid or missing configuration value"
# define ERR_MSG_INT_MAX	"Value exceeds maximum allowed integer (INT_MAX)"

# define ERR_OPEN			"Error opening file"

#endif