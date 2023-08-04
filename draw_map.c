/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:43:42 by ylachhab          #+#    #+#             */
/*   Updated: 2023/08/03 16:11:31 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_cub3d *data, int x, int y, int color)
{
	char	*dst;
	int		i;
	int		j;

	j = y;
	while (j < (y + 32))
	{
		i = x;
		while (i < (x + 32))
		{
			dst = data->addr + (j * data->line_length + i * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			i++;
		}
		j++;
	}
}

void	ft_draw_map(t_cub3d *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				ft_put_pixel(data, j * 32, i * 32, 0x000000CC);
			if (data->map[i][j] == '0')
				ft_put_pixel(data, j * 32, i * 32, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

void	ft_draw_player(t_cub3d *data)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	y = data->p_y - RADIUS;
	while (y <= (data->p_y + RADIUS))
	{
		x = data->p_x - RADIUS;
		while (x <= (data->p_x + RADIUS))
		{
			pos_x = x - data->p_x;
			pos_y = y - data->p_y;
			if ((pos_x * pos_x) + (pos_y * pos_y) <= RADIUS * RADIUS)
				mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0x00FF0000);
				// ft_put_pixel(data, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
}

void	ft_draw_line(t_cub3d *data)
{
	int x1 = data->p_x + 30 * cos(45 * (M_PI/ 180));
	int y1 = data->p_y + 30 * sin(45 * (M_PI/ 180));
	int	dx = abs(x1 - data->p_x);
	int	dy = abs(y1 - data->p_y);
	int sx = data->p_x < x1 ? 1 : -1;
	int sy = data->p_y < y1 ? 1 : -1;
	int err = dx - dy;
	while (data->p_x != x1 || data->p_y != y1)
	{
		mlx_pixel_put(data->mlx, data->mlx_win, data->p_x, data->p_y, 0x00000000);
		// ft_put_pixel(data, data->p_x, data->p_y, 0x00000000);
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			data->p_x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			data->p_y += sy;
		}
	}
}

int	ft_draw(t_cub3d *data)
{
	ft_draw_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	ft_draw_player(data);
	ft_draw_line(data);
	return (1);
}

void	ft_init(t_cub3d *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->width * 32, data->height * 32, "CUB3D");
	data->img = mlx_new_image(data->mlx, 1900, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	ft_draw(data);
	// mlx_loop_hook(data->mlx, ft_draw, data);
	mlx_hook(data->mlx_win, 2, 0, key_move, data);
	mlx_loop(data->mlx);
}
