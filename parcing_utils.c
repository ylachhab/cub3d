/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:36:43 by ylachhab          #+#    #+#             */
/*   Updated: 2023/07/29 11:32:24 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_open(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_print_error("Error in file\n");
	return (fd);
}

void	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (1);
}

char	*ft_strtrim_line(char const *s1)
{
	char	*str;
	size_t	debut;
	size_t	fin;
	size_t	i;

	i = 0;
	debut = 0;
	if (!s1)
		return (NULL);
	fin = strlen(s1);
	while (s1[debut] && ((s1[debut] >= 9 && s1[debut] <= 13)
			|| s1[debut] == 32))
		debut++;
	while (fin > debut && ((s1[fin - 1] >= 9 && s1[fin - 1] <= 13)
			|| s1[fin - 1] == 32))
		fin--;
	str = (char *)malloc(sizeof(char) * (fin - debut + 1));
	if (!str)
		return (0);
	while (debut < fin)
		str[i++] = s1[debut++];
	return (str[i] = '\0', str);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi_util(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		ft_print_error("Error in color\n");
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		if (result > 255)
		{
			printf("Error in color\n");
			exit (1);
		}
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		ft_print_error("Error in color\n");
	return (result);
}
