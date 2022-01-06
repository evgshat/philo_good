/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:19:51 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 20:21:53 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	end_main(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->sem_write);
	sem_close(data->sem_eat);
	sem_unlink("forks");
	sem_unlink("sem_write");
	sem_unlink("sem_eat");
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo[200];
	int		i;
	int		wait_status;

	philo_parser(argc, argv, &data);
	philo_init(&data, philo);
	philo_start(&data, philo);
	i = -1;
	while (++i < data.num_philos)
	{
		waitpid(-1, &wait_status, 0);
		if (wait_status != 0)
		{
			i = -1;
			while (++i < data.num_philos)
				kill(philo->philo_pid, SIGTERM);
			break ;
		}
	}
	end_main(&data);
	return (0);
}
