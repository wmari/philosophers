/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <wmari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:15:28 by wmari             #+#    #+#             */
/*   Updated: 2022/07/19 14:23:51 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	ft_put_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1,&str[i++], 1);
}

static void	ft_put_lnbr(long int nbr)
{
	char	c;
	
	if (nbr / 10 > 0)
		ft_put_lnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

static void	ft_put_nbr(int nbr)
{
	char	c;
	
	if (nbr / 10 > 0)
		ft_put_nbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	ft_put_all(long int time, int id, char *str)
{
	ft_put_lnbr(time);
	write(1, "\t", 1);
	ft_put_nbr(id);
	write(1, "\t", 1);
	ft_put_str(str);
	write(1, "\n", 1);
}