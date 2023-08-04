/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:43:42 by ylachhab          #+#    #+#             */
/*   Updated: 2023/08/03 13:54:35 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ff()
{
	system("leaks cub3d");
}

void	ft_check(t_cub3d *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ' ')
				data->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	ft_player_position(t_cub3d *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'S')
			{
				data->map[i][j] = '0';
				data->p_x = (j * 32) + 16;
				data->p_y = (i * 32) + 16;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_parcing(t_cub3d *data, char *file)
{
	int	len;

	if (!ft_check_file_name(file))
		exit (1);
	ft_init_var(data);
	ft_read_map(data, file);
	ft_stock_map(data, file);
	len = ft_strlen(data->map[data->height - 1]);
	if (data->map[data->height - 1][len - 1] == '\n')
	{
		ft_free_str(data->map);
		ft_print_error("Error in the end of file\n");
	}
	ft_valid_content(data);
	ft_check_lenght_map(data);
	ft_check_space(data);
	ft_map_close(data);
	ft_valid_map(data);
	ft_player_position(data);
	ft_check(data);
}

int	main(int ac, char **av)
{
	t_cub3d	data;

	// atexit(ff);
	if (ac != 2)
	{
		printf("Error\n");
		exit (1);
	}
	ft_parcing(&data, av[1]);
	ft_init(&data);
	// int i = 0;
	// while (data.map[i])
	// {
	// 	printf("%s", data.map[i]);
	// 	i++;
	// }
	ft_free_str(data.map);
}
