#include "../include/nemergent.h"

int main(int argc, char **argv)
{
	t_data data;

	init_data(&data);
	if (check_args(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (check_file(argv[2], &data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
		
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
