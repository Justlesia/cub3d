/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/13 00:29:33 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "cub3d.h"

void		ft_error(t_params *prm, int fd, int err)
{
	if (err == 0)
		ft_putstr_fd("Error\nIncorrect number of arguments\n", 1);
	else if (err == 4)
		ft_putstr_fd("Error\nSecond argument != '––save'\n", 1);
	else if (err == 1)
	{
		ft_putstr_fd("Error\nCheck if file .cub exist\n", 1);
		close(fd);
	}
	else if (err == 2)
	{
		ft_putstr_fd("Error\nFile .cub is not valid\n", 1);
		close(fd);
		free(prm);
		exit(0);
	}
	else if (err == 3)
	{
		ft_putstr_fd("Error\nAt least one of the pics is not valid\n", 1);
		ft_protect(prm->map.self, prm->map.r);
		free(prm);
	}
	else
		ft_putstr_fd("Error\nUnknown Error\n", 1);
	exit(0);
}

int			ft_error_2(t_params *prm, int fd, int err)
{
	if (err == 4)
	{
		ft_putstr_fd("Error\nFile .cub is not valid\n", 1);
		close(fd);
		free(prm);
	}
	exit(0);
}

int			ft_exit(int key, t_params *prm)
{
	(void)key;
	(void)prm;
	ft_putstr_fd("Bye!!!\n", 1);
	exit(0);
}
