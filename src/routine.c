#include "../include/nemergent.h"

void	*routine(void *arg)
{
	t_data *data;
	int		*arr;
	int		i;

	data = (t_data *)arg;
	arr = get_rand_nb(data->nb_per_thread);
	i = 0;
	while (i < data->nb_per_thread)
	{
		if(arr[i] % 2 == 0)
			add_node(&data->even, arr[i], data, EVEN);
		else
			add_node(&data->odd, arr[i], data, ODD);
		i++;
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