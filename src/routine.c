#include "../include/nemergent.h"

void	*routine(void *arg)
{
	t_data *data;
	int		*arr;
	int		num;
	int		i;
	unsigned int seed;

	data = (t_data *)arg;
	i = 0;
	seed = time(NULL) ^ pthread_self();
	arr = malloc(sizeof(int) * data->nb_per_thread);
	if (!arr)
	{
		perror("routine: ");
		return  (NULL);
	}
	while (i < data->nb_per_thread)
	{
		num = rand_r(&seed);
		if (!is_duplicated(arr, i, num))
		{
			arr[i] = num;
			if(arr[i] % 2 == 0)
				add_node(&data->even, arr[i], data, EVEN);
			else
				add_node(&data->odd, arr[i], data, ODD);
			i++;
		}
	}
	free(arr);
	return (NULL) ;
}

void	add_node(t_list **list, int num, t_data *data, int class)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (perror("add_node: "));
	new->nb = num;
	new->next = NULL;
	if (class == EVEN)
		pthread_mutex_lock(&data->m_even);
	else if (class == ODD)
		pthread_mutex_lock(&data->m_odd);
	ft_lstadd_front(list, new);
	if (class == EVEN)
		pthread_mutex_unlock(&data->m_even);
	else if (class == ODD)
		pthread_mutex_unlock(&data->m_odd);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

int	is_duplicated(int *arr, int size, int value)
{
	int i;

	i = 0;
	while(i < size)
	{
		if (arr[i] == value)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}