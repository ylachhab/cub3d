/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:24:14 by ylachhab          #+#    #+#             */
/*   Updated: 2023/08/03 10:46:48 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	ft_newline(char *line, int fd)
{
	if (!ft_strcmp(line, "\n"))
	{
		close (fd);
		free (line);
		ft_print_error("Error in map\n");
	}
}

void	ft_count_map_height(t_cub3d *data, char *line, int fd)
{
	line = get_next_line(fd);
	ft_empty_line(line, fd);
	while (!ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(fd);
		ft_empty_line(line, fd);
	}
	while (line)
	{
		ft_newline(line, fd);
		if (data->width < my_strlen(line))
			data->width = my_strlen(line);
		data->height++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		exit (1);
}

void	ft_check_floor_ceiling_var(int *var, char *value)
{
	char	**split;
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(value) - 1;
	while ((value[len] >= 9 && value[len] <= 13) || value[len] == 32)
		len--;
	if (value[len] == ',')
		ft_print_error("----Error---\n");
	split = ft_split(value, ',');
	if (!split)
		ft_print_error("Error in malloc\n");
	while (split[i])
		i++;
	if (i != 3)
	{
		ft_free_str(split);
		ft_print_error("Error in floor\n");
	}
	i = 0;
	while (split[i])
	{
		str = ft_strtrim_line(split[i]);
		var[i] = ft_atoi_util(str);
		free(str);
		i++;
	}
	ft_free_str(split);
}

void	ft_check_variable(t_cub3d *data, char *line)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	key = NULL;
	value = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			key = ft_substr(line, 0, i);
			value = ft_substr(line, i + 1, ft_strlen(line));
			break ;
		}
		i++;
	}
	ft_stock_var(data, key, value);
	free (key);
	free (value);
}
