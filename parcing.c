/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:34:47 by ylachhab          #+#    #+#             */
/*   Updated: 2023/07/31 14:56:32 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_var(t_cub3d *data)
{
	data->height = 0;
	data->width = 0;
	data->north = NULL;
	data->soulth = NULL;
	data->east = NULL;
	data->west = NULL;
	data->ceiling[0] = 0;
	data->ceiling[1] = 0;
	data->ceiling[2] = 0;
	data->floor[0] = 0;
	data->floor[1] = 0;
	data->floor[2] = 0;
	data->p_x = 0;
	data->p_y = 0;
}

int	ft_check_file_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'b' && str[i - 1] == 'u' && str[i - 2] == 'c'
		&& str[i - 3] == '.' && str[i - 4])
		return (1);
	else
	{
		printf("Error files without .cub extension is not accepted\n");
		return (0);
	}
}

void	ft_read_map(t_cub3d *data, char *file)
{
	char	*line;
	int		fd;
	int		nb;
	char	*str;

	nb = 0;
	fd = ft_open(file);
	while (nb < 6)
	{
		line = get_next_line(fd);
		ft_empty_line(line, fd);
		if (!ft_strcmp(line, "\n"))
		{
			free (line);
			continue ;
		}
		str = ft_strtrim_line(line);
		ft_check_variable(data, str);
		free (str);
		free (line);
		nb++;
	}
	ft_count_map_height(data, line, fd);
}

void	ft_read_line(t_cub3d *data, char *line, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (line)
	{
		j = 0;
		while ((line[j] >= 9 && line[j] <= 13) || line[j] == 32)
			j++;
		if (line[j] == '\0')
		{
			free (line);
			close(fd);
			ft_print_error("Error in file\n");
		}
		data->map[i] = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close (fd);
}

void	ft_stock_map(t_cub3d *data, char *file)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = ft_open(file);
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!ft_strcmp(line, "\n"))
		{
			free (line);
			continue ;
		}
		free (line);
		i++;
	}
	line = get_next_line(fd);
	while (!ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(fd);
	}
	ft_read_line(data, line, fd);
}
