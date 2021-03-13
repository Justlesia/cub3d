/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:56:39 by sbrenton          #+#    #+#             */
/*   Updated: 2021/03/12 20:16:44 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUM3D_CUB3D_H
#	define CUM3D_CUB3D_H
#	include <stdlib.h>
#	include <unistd.h>
#	include <stdio.h>
#	include <zconf.h>
#	include "../libft/libft.h"
# 	include <math.h>
#	include "../mlx_mms/mlx.h"
#	include <fcntl.h>

typedef struct				s_resolution
{
	long long				x;
	long long				y;
}							t_resolution;

typedef struct				s_dist
{
	double					nw;
	double					sw;
	double					se;
	double					ne;
}							t_dist;

typedef struct				s_color
{
	int						r;
	int						g;
	int						b;
}							t_color;

typedef struct				s_pics
{
	char					*we;
	char					*no;
	char					*so;
	char					*ea;
	char					*s;
}							t_pics;

typedef struct				s_texture
{
	void					*obj;
	int						img_width;
	int						img_height;
	unsigned int			*data;
	int						bpp;
	int						sizeline;
	int						endian;
}							t_texture;

typedef struct				s_dt_pics
{
	t_texture				we;
	t_texture				no;
	t_texture				so;
	t_texture				ea;
	t_texture				s;
}							t_dt_pics;

typedef struct				s_plr
{
	double					r;
	double					c;
	char					view;
	double					dir;
}							t_plr;

typedef struct				s_line
{
	int						line_height;
	int						start;
	int						end;
}							t_line;

typedef struct				s_map
{
	char					**self;
	int						r;
	int						*c;
}							t_map;

typedef struct				s_vars
{
	void					*mlx;
	void					*win;
}							t_vars;

typedef struct				s_params
{
	t_resolution			r;
	t_pics					p_pics;
	t_dt_pics				dt_pics;
	t_color					f;
	t_color					c;
	t_map					map;
	t_plr					player;
	t_vars					vars;
	t_texture				screen;
}							t_params;

typedef struct				s_pic_and_x
{
	t_texture				pic;
	int						local_x;
}							t_pic_and_x;

typedef struct				s_dir_info
{
	double					angle;
	double					dir;
	double					dir_end;
	double					w_angle;
	int						x;
	float					c_dir;
	float					s_dir;
	double					wall_x;
	double					wall_y;
	int						spr;
	double					s_wall_x[500];
	double					s_wall_y[500];
}							t_dir_info;

t_params					*ft_parcer(t_params *prm, int fd, int count,
										int mark);
char						*ft_safe_l(char *line);
t_map						ft_map(t_list *list_map, int i, int count_r);
t_plr						ft_player(t_map *map, int count, int r, int c);
int							ft_is_in_set(const char *set, char c);
double						ft_start_dir(char position);
t_dt_pics					ft_pars_pic(t_params *prm);
double						distance(double x1, double y1,
										double x2, double y2);
void						ft_error(t_params *prm, int fd, int err);
int							ft_basic_frame(t_params *prm, t_texture screen);
int							ft_walls(t_params *prm);
int							render_next_frame(t_params *prm);
int							ft_action(int key, t_params *prm);
int							ft_exit(int key, t_params *prm);
char						**ft_protect(char **res, int w);
int							ft_save(t_params *prm);
int							ft_strncmp_181(const char *s1,
							const char *s2, size_t n);
char						**ft_check_map(char **map, int n_rows,
							int n_icol[n_rows + 1], int r);
int							ft_exit(int key, t_params *prm);
void						ft_exit_esc(t_params *prm);
void						draw_sprite_line(t_params *prm, double w_x,
												double w_y, int x);
void						draw_wall_line(t_params *prm, int line_height,
											t_pic_and_x pic_x, int x);
t_pic_and_x					ft_what_pic_and_local_x(t_params *prm, double w_x,
											double w_y, int line_height);
t_color						ft_color(char *line, t_color color);
char						*ft_path(char *line);
char						*ft_mystrim(char *line);
t_resolution				ft_resolution(char *line);
t_params					*ft_init(t_params *prm);

int							ft_parcer_outsource_r(t_params *prm, char *line,
									int *count);
int							ft_parcer_outsource_no_so(t_params *prm, char *line,
									int *count);
int							ft_parcer_outsource_we_ea(t_params *prm, char *line,
									int *count);
int							ft_parcer_outsource_f_c(t_params *prm, char *line,
									int *count);
int							ft_parcer_outsource_s_other(t_params *prm,
									char *line, int *count);
int							ft_r(t_params *prm, char *line, int *count);
t_map						ft_protect_map(t_map map_t, int cnt_r);
int							ft_error_2(t_params *prm, int fd, int err);

#	endif
