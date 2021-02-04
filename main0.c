#include <stdio.h>
//#include "libft.a"
#include "cub3d.h"
# include "mlx_mms/mlx.h"
//#	include "libft/libft.h"
#	include "cub3d.h"
#	include <stdlib.h>
#	include <zconf.h>
#	include <fcntl.h>
//#include "libft/libft.h"
//#	include "libft/libft.h"
#	include "cub3d.h"
//#	include <stdlib.h>
////#	include <unistd.h>
////#	include <stdio.h>
////#	include <zconf.h>
////#	include <fcntl.h>
////#include <tclDecls.h>
//

//typedef struct  s_vars {
//	void    *mlx;
//	void    *win;
//}               t_vars;
//
//
//int             ft_exit(int key, t_vars *vars)
//{
//	(void)key;
//	(void)vars;
//	exit(0);
//}
//
//int             ft_action(int key, t_vars *vars)
//{
//	//mlx_destroy_window(vars->mlx, vars->win);
//	printf("key-%d\n", key);
//
//	if (key == 13) //W
//	{
//		mlx_pixel_put(vars->mlx, vars->win, 50, 50, 0xFFFFFF);
//	}
//	if (key == 0) // A
//	{
//		mlx_pixel_put(vars->mlx, vars->win, 50, 50, 0xFFFFFF);
//	}
//	if (key == 1) // S
//	{
//		mlx_clear_window(vars->mlx, vars->win);
//	}
//	if (key == 2) // D
//	{
//		mlx_clear_window(vars->mlx, vars->win);
//	}
//	if (key == 124) // left
//	{
//		mlx_clear_window(vars->mlx, vars->win);
//	}
//	if (key == 123) // right
//	{
//		mlx_clear_window(vars->mlx, vars->win);
//	}
//
//	if (key == 53)
//	{
//		mlx_destroy_window(vars->mlx, vars->win);
//		ft_exit(53,vars);
//		//exit(0);
//	}
//	return 0;
//}

//	if (key == 0)
//		mlx_pixel_put(vars->mlx, vars->win, 50,50, 0xFFFFFF);
//	if (key == 1)
//		mlx_destroy_window(vars->mlx, vars->win);
//
//
//[ cos(a) -sin(a) ]
//[ sin(a)  cos(a) ]

//int deal_key(int key, void *param)
//	{
//		write(1,"X",1);
//		//mlx_pixel_put(mlx_ptr, win_ptr )
//		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, 25,50, 0xFFFFFF);
//		return (0);
//}

int     render_next_frame(void *YourStruct);

int             main(void)
{
//	t_vars vars;

	int fd = 0;
	t_params *prm = NULL;
//	(void)vars;

//	int sizex;
//  int sizey;

	////	if ((fd = open("/Users/lesia/Study/21_school/cum3d/params.cub", O_RDONLY)) < 0)
////		return -1;
	prm = ft_parcer(prm, fd);
	printf("%d,%d",prm->player.r, prm->player.c);
//	vars.mlx = mlx_init();
////	mlx_get_screen_size(vars.mlx, &sizex, &sizey);
//	printf("%d,%d",prm->r.x  ,prm->r.y);
//
////	if (prm->r.x > sizex)
////		prm->r.x = sizex;
////	if (prm->r.y > sizey)
////		prm->r.y = sizey;
////	vars.win = mlx_new_window(vars.mlx, sizex ,sizey, "Cub3d");
//	vars.win = mlx_new_window(vars.mlx, prm->r.x  ,prm->r.y, "Cub3d");
//
//	mlx_hook(vars.win, 2, 1L << 0, ft_action, &vars);
//	mlx_hook(vars.win, 17, 0, ft_exit, &vars);
////	mlx_loop_hook(mlx, render_next_frame, YourStruct);
//	mlx_loop(vars.mlx);

//
//
//	int length;
//	int width;
//
//
//	int n = 20;
//
//	length = 0;
//	width = 0;
//	while (length < n)
//	{
//		while (width < n)
//		{
//			mlx_pixel_put(vars.mlx, vars.win, 40 + length, 40 + width, 0xFFFFFF);
//			mlx_pixel_put(vars.mlx, vars.win, 40 + width, 40 + length, 0x00FF00);
//			mlx_pixel_put(vars.mlx, vars.win,  40 + n - length , 40 + n- width, 0xFFFFFF);
//			mlx_pixel_put(vars.mlx, vars.win, 40 + n- width, 40 + n - length, 0x00FF00);
//			width++;
//		}
//		length++;
//	}
	//mlx_hook(mlx, 17, 0, &func, param);

}



//gcc main.c parcer.c libft.a ./mlx_mms/libmlx.dylib  -framework OpenGL -framework AppKit
