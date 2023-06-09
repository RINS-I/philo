/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:43:15 by niboukha          #+#    #+#             */
/*   Updated: 2023/05/25 15:46:21 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	ft_atoi(char *str)
{
	int			i;
	long		result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	if (str[i])
		return (-1);
	return (result * sign);
}

int	print_error(void)
{
	printf("error\n");
	return (0);
}

int	check_args(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < 5 || (i < 6 && ac == 6))
	{
		if (ft_atoi(av[i]) == -1)
		{
			printf("error\n");
			return (-1);
		}
		else
			if (ft_atoi(av[i]) == 0)
				return (-2);
		i++;
	}
	return (1);
}
