#include <stdio.h>
//#include "libft.a"
#include "cub3d.h"
# include "mlx_mms/mlx.h"
//# include "minilibx_opengl_20191021/mlx.h"
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

int             ft_exit(int key, t_vars *vars)
{
	(void)key;
	(void)vars;
	exit(0);
}


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
//			mlx_pixel_put(prm->vars.mlx, prm->vars.win, 40 + length, 40 + width, 0xFFFFFF);
//			mlx_pixel_put(prm->vars.mlx, prm->vars.win, 40 + width, 40 + length, 0x00FF00);
//			mlx_pixel_put(prm->vars.mlx, prm->vars.win,  40 + n - length , 40 + n- width, 0xFFFFFF);
//			mlx_pixel_put(prm->vars.mlx, prm->vars.win, 40 + n- width, 40 + n - length, 0x00FF00);
//			width++;
//		}
//		length++;
//	}


int             ft_action(int key, t_params *prm)
{
	//mlx_destroy_window(vars->mlx, vars->win);
	printf("key-%d\n", key);

 	ft_basic_frame(prm);
	double moveSpeed = 0.02;

 	if (key == 13) //W
	{
		if(prm->map.self[(int)(prm->player.c + prm->p_cam.dirX * moveSpeed)][(int)(prm->player.r)] == '0')
			prm->player.c += prm->p_cam.dirX * moveSpeed;
	}
	if (key == 1) // S
	{
		if(prm->map.self[(int)(prm->player.c - prm->p_cam.dirX * moveSpeed)][(int)(prm->player.r)] == '0')
			prm->player.c -= prm->p_cam.dirX * moveSpeed;
	}
	if (key == 0) // A
	{
		if(prm->map.self[(int)(prm->player.c)][(int)(prm->player.r + prm->p_cam.dirY * moveSpeed)] == '0')
			prm->player.r += prm->p_cam.dirY * moveSpeed;
	}
	if (key == 2) // D
	{
		if(prm->map.self[(int)(prm->player.c)][(int)(prm->player.r - prm->p_cam.dirY * moveSpeed)] == '0')
			prm->player.r -= prm->p_cam.dirY * moveSpeed;
	}
	double oldDirX;
	double oldPlaneX;
	double rotSpeed = 0.001;

	if (key == 123) // right
	{
		oldDirX = prm->p_cam.dirX;
		prm->p_cam.dirX = prm->p_cam.dirX * cos(-rotSpeed) - prm->p_cam.dirY * sin(-rotSpeed);
		prm->p_cam.dirY = oldDirX * sin(-rotSpeed) + prm->p_cam.dirY * cos(-rotSpeed);
		oldPlaneX = prm->p_cam.planeX;
		prm->p_cam.planeX = prm->p_cam.planeX * cos(-rotSpeed) - prm->p_cam.planeY * sin(-rotSpeed);
		prm->p_cam.planeY = oldPlaneX * sin(-rotSpeed) + prm->p_cam.planeY * cos(-rotSpeed);
	}
	if (key == 124) // left
	{
		oldDirX = prm->p_cam.dirX;
		prm->p_cam.dirX = prm->p_cam.dirX * cos(rotSpeed) - prm->p_cam.dirY * sin(rotSpeed);
		prm->p_cam.dirY = oldDirX * sin(rotSpeed) + prm->p_cam.dirY * cos(rotSpeed);
		oldPlaneX = prm->p_cam.planeX;
		prm->p_cam.planeX = prm->p_cam.planeX * cos(rotSpeed) - prm->p_cam.planeY * sin(rotSpeed);
		prm->p_cam.planeY = oldPlaneX * sin(rotSpeed) + prm->p_cam.planeY * cos(rotSpeed);
	}
	if (key == 53)
	{
		mlx_destroy_window(prm->vars.mlx, prm->vars.win);
		ft_exit(53,&prm->vars);
		//exit(0);
	}

	ft_walls(prm);

	return 0;
}

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

int     render_next_frame(t_params *prm)
{
	ft_basic_frame(prm);

	return 0;
}

int             main(void)
{
	//t_vars vars;

	int fd = 0;
	t_params *prm = NULL;

	int sizex;
  	int sizey;

////	if ((fd = open("/Users/lesia/Study/21_school/cum3d/params.cub", O_RDONLY)) < 0)
////		return -1;
	prm = ft_parcer(prm, fd);
	prm->vars.mlx = mlx_init();
//	mlx_get_screen_size(prm->vars.mlx, &sizex, &sizey);
	printf("%d,%d",prm->r.x ,prm->r.y);
//
//	if (prm->r.x > sizex)
//		prm->r.x = sizex;
//	if (prm->r.y > sizey)
//		prm->r.y = sizey;
	prm->vars.win = mlx_new_window(prm->vars.mlx, prm->r.x ,prm->r.y, "Cub3d");
	ft_basic_frame(prm);
	ft_walls(prm);
	mlx_hook(prm->vars.win, 2, 1L << 0, ft_action, prm);
	mlx_hook(prm->vars.win, 17, 0, ft_exit, prm);
//	mlx_hook(prm->vars.win, 3, 1L<<1, ft_basic_frame, 0);

	mlx_loop_hook(prm->vars.win, render_next_frame, prm);
	mlx_loop(prm->vars.mlx);



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
