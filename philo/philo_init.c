/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:40:39 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 18:43:14 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (error_message("Mutex init error!\n"));
	if (pthread_mutex_init(&data->mutex_write, NULL) != 0
		|| pthread_mutex_init(&data->mutex_eat, NULL) != 0)
		return (error_message("Mutex init error!\n"));
	return (0);
}

int	philo_init(t_data *data, t_philo *philo)
{
	int	i;

	if (philo_init_mutexes(data) != 0
		|| gettimeofday(&data->start_time, NULL) != 0)
		return (1);
	i = -1;
	while (++i < data->num_philos)
	{
		philo[i].right_fork = i;
		philo[i].left_fork = (i + 1) % data->num_philos;
		philo[i].philo_ind = i;
		philo[i].num_of_eat = 0;
		philo[i].data = data;
		philo[i].time_last_eat = data->start_time;
	}
	return (0);
}
