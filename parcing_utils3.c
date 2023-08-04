/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:22:36 by ylachhab          #+#    #+#             */
/*   Updated: 2023/08/01 07:22:39 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_is_space(t_cub3d *data, char *str, int *i)
{
	int	j;

	j = 0;
	while (data->map[*i][j])
	{
		str[j] = data->map[*i][j];
		if (str[j] == '\n')
			str[j] = ' ';
		j++;
	}
	while (j < data->width)
		str[j++] = ' ';
	if (data->map[*i + 1])
		str[j++] = '\n';
	str[j] = '\0';
	data->map[*i] = str;
}

void	ft_check_lenght_map(t_cub3d *data)
{
	char	*tmp;
	char	*str;
	int		i;
	int		len;

	i = 0;
	while (data->map[i])
	{
		if (data->width > my_strlen(data->map[i]))
		{
			tmp = data->map[i];
			len = data->width - my_strlen(data->map[i]);
			str = malloc(sizeof(char *) * (data->width + 2));
			if (!str)
				exit (1);
			ft_is_space(data, str, &i);
			free(tmp);
		}
		i++;
	}
}

void	ft_error(t_cub3d *data, char *str)
{
	ft_free_str(data->map);
	ft_print_error(str);
}

void	ft_valid_content(t_cub3d *data)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	nbr = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != ' ' && data->map[i][j] != '1'
				&& data->map[i][j] != '0' && data->map[i][j] != 'N'
				&& data->map[i][j] != 'W' && data->map[i][j] != 'S'
				&& data->map[i][j] != 'E' && data->map[i][j] != '\n')
				ft_error(data, "Error in content of map\n");
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'E')
				nbr++;
			j++;
		}
		i++;
	}
	if (nbr != 1)
		ft_error(data, "Error in content of map\n");
}

void	ft_check_space(t_cub3d *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if ((i > 0 && data->map[i - 1][j] == ' ')
					|| (i < (data->height - 1) && data->map[i + 1][j] == ' ')
					|| (j > 0 && data->map[i][j - 1] == ' ')
					|| (j < data->width && data->map[i][j + 1] == ' '))
				{
					ft_free_str(data->map);
					ft_print_error("Error map is not closed\n");
				}
			}
			j++;
		}
		i++;
	}
}
