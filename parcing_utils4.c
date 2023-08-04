/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:22:21 by ylachhab          #+#    #+#             */
/*   Updated: 2023/08/01 09:03:48 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		str[i] = NULL;
		i++;
	}
	free (str);
	str = NULL;
}

void	ft_empty_line(char *line, int fd)
{
	if (!line)
	{
		close(fd);
		ft_print_error("Error in file\n");
	}
}

void	ft_valid_map(t_cub3d *data)
{
	char	*str;
	int		i;
	int		len;

	i = 1;
	while (data->map[i] && i < (data->height - 1))
	{
		str = ft_strtrim_line(data->map[i]);
		len = ft_strlen(str) - 1;
		if (str[0] != '1' || str[len] != '1')
		{
			free(str);
			ft_free_str(data->map);
			ft_print_error("Error in map\n");
		}
		free(str);
		i++;
	}
}

void	ft_is_wall(char *str, t_cub3d *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
		{
			free(str);
			ft_free_str(data->map);
			ft_print_error("map is not closed\n");
		}
		i++;
	}
	free(str);
}

void	ft_map_close(t_cub3d *data)
{
	char	*str;

	str = ft_strtrim_line(data->map[0]);
	ft_is_wall(str, data);
	str = ft_strtrim_line(data->map[data->height - 1]);
	ft_is_wall(str, data);
}
