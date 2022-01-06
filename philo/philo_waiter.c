/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_waiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:03 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 18:54:17 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_die(t_data *data, t_philo *philo, t_timeval current_time)
{
	if (timeval_to_ms(current_time)
		- timeval_to_ms(philo->time_last_eat)
		> (unsigned long)data->time_to_die)
	{
		pthread_mutex_lock(&data->mutex_write);
		printf("%ld %d %s\n", get_current_time(data),
			philo->philo_ind + 1, "died");
		return (1);
	}
	return (0);
}

void	philo_waiter(t_data *data, t_philo *philo)
{
	int			i;
	t_timeval	current_time;

	i = 0;
	usleep(200);
	while (1)
	{
		if (i == data->num_philos)
			i = 0;
		pthread_mutex_lock(&data->mutex_eat);
		gettimeofday(&current_time, NULL);
		if (check_die(data, &philo[i], current_time))
			break ;
		pthread_mutex_unlock(&data->mutex_eat);
		if (data->num_of_fed_up >= data->num_philos)
		{
			pthread_mutex_lock(&data->mutex_write);
			break ;
		}
		++i;
	}
}
