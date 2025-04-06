#include "../include/nemergent.h"

int init_threads(t_data *data)
{
	int	i;

	i = 0;
	data->th = malloc(sizeof(pthread_t) * data->thread_num);
	if (!data->th)
		return (perror("init_threads: "), EXIT_FAILURE);
	while (i < data->thread_num)
	{
		if (pthread_create(&data->th[i], NULL, &routine, data) != 0)
			return (perror("pthread_create: "), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int join_threads(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->thread_num)
	{
		if (pthread_join(data->th[i], NULL))
			return (perror("join_threads: "),EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	destroy_mutex(t_data *data)
{
	if (pthread_mutex_destroy(&data->m_even) != 0)
		perror("destroy_mutex even: ");

	if (pthread_mutex_destroy(&data->m_odd) != 0)
		perror("destroy_mutex odd: ");
}
