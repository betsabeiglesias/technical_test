#include "../include/nemergent.h"

int main(int argc, char **argv)
{
	t_data data;

	init_data(&data);
	if (check_args(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (check_file(argv[2], &data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	
	if (init_threads(&data) != EXIT_SUCCESS)
		return(EXIT_FAILURE);
	
	if (join_threads(&data) != EXIT_SUCCESS)
		return(EXIT_FAILURE);
	
	printf("EVEN\n");
	print_list(data.even);

	printf("ODD\n");
	print_list(data.odd);

	destroy_mutex(&data);
	return (EXIT_SUCCESS);
}

void init_data(t_data *data)
{
	data->nb_per_thread = 0;
	data->thread_num = 0;
	data->th = NULL;
	data->even = NULL;
	data->odd = NULL;
	pthread_mutex_init(&data->m_even, NULL);
	pthread_mutex_init(&data->m_odd, NULL);
}

void	print_list(t_list *list)
{
	int	i;

	i = 1;	
	if(!list)
		return ;
	while(list)
	{
		printf("%d\n", list->nb);
		list = list->next;
		i++;
	}
}