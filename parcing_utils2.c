/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:30:21 by ylachhab          #+#    #+#             */
/*   Updated: 2023/08/03 10:12:20 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_open_tex_file(char *value, char *key)
{
	int	fd;

	fd = open(value, O_RDONLY);
	if (fd == -1)
	{
		free (key);
		free (value);
		ft_putstr_fd("Error in file\n", 2);
		exit (1);
	}
	close(fd);
}

void	ft_floor_ceiling(t_cub3d *data, char *value, char *key)
{
	if (!ft_strcmp(key, "F") && data->floor[0] == 0
		&& data->floor[1] == 0 && data->floor[2] == 0)
		ft_check_floor_ceiling_var(data->floor, value);
	else if (!ft_strcmp(key, "C") && data->ceiling[0] == 0
		&& data->ceiling[1] == 0 && data->ceiling[2] == 0)
		ft_check_floor_ceiling_var(data->ceiling, value);
	else
	{
		free (key);
		free (value);
		ft_print_error("Error in the element\n");
	}
}

void	ft_stock_var(t_cub3d *data, char *key, char *value)
{
	if (!key || !value)
		ft_print_error("Error\n");
	if (!ft_strcmp(key, "NO") && !data->north)
	{
		ft_open_tex_file(value, key);
		data->north = value;
	}
	else if (!ft_strcmp(key, "SO") && !data->soulth)
	{
		ft_open_tex_file(value, key);
		data->soulth = value;
	}
	else if (!ft_strcmp(key, "WE") && !data->west)
	{
		ft_open_tex_file(value, key);
		data->west = value;
	}
	else if (!ft_strcmp(key, "EA") && !data->east)
	{
		ft_open_tex_file(value, key);
		data->east = value;
	}
	else
		ft_floor_ceiling(data, value, key);
}
