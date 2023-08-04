/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:43:58 by ylachhab          #+#    #+#             */
/*   Updated: 2023/08/03 15:52:05 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define RADIUS 6

typedef struct s_cub3d
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**map;
	int		width;
	int		height;
	char	*north;
	char	*soulth;
	char	*west;
	char	*east;
	int		floor[3];
	int		ceiling[3];
	int		p_x;
	int		p_y;
}	t_cub3d;

int		ft_check_file_name(char *str);
void	ft_stock_map(t_cub3d *data, char *file);
void	ft_read_line(t_cub3d *data, char *line, int fd);
void	ft_read_map(t_cub3d *data, char *file);
void	ft_print_error(char *str);
void	ft_empty_line(char *line, int fd);
void	ft_count_map_height(t_cub3d *data, char *line, int fd);
int		ft_open(char *str);
void	ft_init_var(t_cub3d *data);
void	ft_check_floor_ceiling_var(int *var, char *value);
void	ft_check_variable(t_cub3d *data, char *line);
char	*ft_strtrim_line(char const *s1);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi_util(char *str);
void	ft_stock_var(t_cub3d *data, char *key, char *value);
void	ft_free_str(char **str);
int		my_strlen(char *s);
void	ft_check_space(t_cub3d *data);
void	ft_valid_content(t_cub3d *data);
void	ft_check_lenght_map(t_cub3d *data);
void	ft_is_space(t_cub3d *data, char *str, int *i);
void	ft_map_close(t_cub3d *data);
void	ft_is_wall(char *str, t_cub3d *data);
void	ft_valid_map(t_cub3d *data);

void	ft_init(t_cub3d *data);
int	ft_draw(t_cub3d *data);
int		key_move(int keycode, t_cub3d *data);
void	ft_draw_line(t_cub3d *data);

#endif