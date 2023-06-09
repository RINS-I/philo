/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:57:46 by niboukha          #+#    #+#             */
/*   Updated: 2023/05/25 15:38:12 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	calcul_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(int i)
{
	long long	_time;

	_time = calcul_time_ms() + i;
	while (calcul_time_ms() < _time)
		usleep(100);
}

int	stop_phils(t_philo *f)
{
	int	i;
	int	cmt;

	while (1)
	{
		i = 0;
		cmt = 0;
		while (i < f->data.number_of_philosophers)
		{
			pthread_mutex_lock(&(f->mutex->p));
			if (f[i].data.number_eat == 0)
				cmt++;
			if (f->data.number_of_philosophers == cmt)
				return (0);
			if ((calcul_time_ms() - f[i].last_meal) > f[i].data.time_to_die)
			{
				pthread_mutex_lock(&(f->mutex->print));
				printf("%s", "\033[0;31m");
				ft_print(f, "is deid", 1);
				return (0);
			}
			pthread_mutex_unlock(&(f->mutex->p));
			i++;
		}
	}
}

void	ft_print(t_philo *f, const char *txt, int x)
{
	if (x == 0)
	{
		pthread_mutex_lock(&(f->mutex->print));
		printf("%lld philo %d %s\n",
			calcul_time_ms() - f->start_time, f->id, txt);
		pthread_mutex_unlock(&f->mutex->print);
	}
	else
		printf("%lld philo %d %s\n",
			calcul_time_ms() - f->start_time, f->id, txt);
}

void	destroy_mut(t_philo *f)
{
	int	i;

	i = -1;
	while (++i < f->data.number_of_philosophers)
		pthread_mutex_destroy(f[i].data.forks);
	pthread_mutex_destroy(&f->mutex->p);
	pthread_mutex_destroy(&f->mutex->print);
}
