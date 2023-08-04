/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:40:56 by ylachhab          #+#    #+#             */
/*   Updated: 2023/08/02 15:42:35 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc(int keycode)
{
	if (keycode == 53)
		exit(0);
}

void	ft_right(int keycode, t_cub3d *data)
{
	if (keycode == 2)
	{
		if (data->map[(data->p_y) / 32][(data->p_x + RADIUS) / 32] == '0')
		{
			data->p_x += 4;
			mlx_clear_window(data->mlx, data->mlx_win);
			ft_draw(data);
		}
	}
}

void	ft_left(int keycode, t_cub3d *data)
{
	if (keycode == 0)
	{
		if (data->map[(data->p_y) / 32][(data->p_x - RADIUS) / 32] == '0')
		{
			data->p_x -= 4;
			mlx_clear_window(data->mlx, data->mlx_win);
			ft_draw(data);
		}
	}
}

void	ft_down(int keycode, t_cub3d *data)
{
	if (keycode == 1)
	{
		if (data->map[(data->p_y + RADIUS) / 32][data->p_x / 32] == '0')
		{
			data->p_y += 4;
			mlx_clear_window(data->mlx, data->mlx_win);
			ft_draw(data);
		}
	}
}

void	ft_up(int keycode, t_cub3d *data)
{
	if (keycode == 13)
	{
		if (data->map[(data->p_y - RADIUS) / 32][data->p_x / 32] == '0')
		{
			data->p_y -= 4;
			mlx_clear_window(data->mlx, data->mlx_win);
			ft_draw(data);
		}
	}
}

int	key_move(int keycode, t_cub3d *data)
{
	esc(keycode);
	ft_right(keycode, data);
	ft_left(keycode, data);
	ft_down(keycode, data);
	ft_up(keycode, data);
	return (1);
}
