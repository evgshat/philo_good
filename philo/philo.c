/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:41:07 by lcharlet          #+#    #+#             */
/*   Updated: 2022/01/03 18:41:09 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo[200];

	if (philo_parser(argc, argv, &data) != 0 || philo_init(&data, philo) != 0
		|| philo_start(&data, philo) != 0)
		return (1);
	philo_waiter(&data, philo);
	return (0);
}
