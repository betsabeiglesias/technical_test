#ifndef VARIABLES_H
# define VARIABLES_H

typedef struct	s_list
{
	int				nb;
	struct s_list	*next;
}				t_list;

typedef struct	s_data
{
	int				nb_per_thread;
	int				thread_num;
	pthread_t		*th;
	t_list			*even;
	t_list			*odd;
	pthread_mutex_t	m_even;
	pthread_mutex_t	m_odd;
}				t_data;

# endif