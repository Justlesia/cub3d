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

int             ft_action(int key, t_params *prm)
{
	printf("key-%d\n", key);

	double oldDirX;
	double oldPlaneX;
	double rotSpeed = 0.8;

 	//ft_basic_frame(prm);
	double moveSpeed = 1;
	if (key == 13) //W
	{
		if(prm->map.self[(int)(prm->player.r)][(int)(prm->player.c + prm->p_cam.dirX * moveSpeed)] == '0')
			prm->player.c += prm->p_cam.dirX * moveSpeed;
	}
	if (key == 1) // S
	{
		if(prm->map.self[(int)(prm->player.r)][(int)(prm->player.c - prm->p_cam.dirX * moveSpeed)] == '0')
			prm->player.c -= prm->p_cam.dirX * moveSpeed;
	}
	if (key == 0) // A
	{
		if(prm->map.self[(int)(prm->player.r + prm->p_cam.dirY * moveSpeed)][(int)(prm->player.c)] == '0')
			prm->player.r += prm->p_cam.dirY * moveSpeed;
	}
	if (key == 2) // D
	{
		if(prm->map.self[(int)(prm->player.r - prm->p_cam.dirY * moveSpeed)][(int)(prm->player.c)] == '0')
			prm->player.r -= prm->p_cam.dirY * moveSpeed;
	}
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
	}
	//ft_walls(prm);
	printf("prm->player.c: %f,prm->player.r: %f,prm->p_cam.dirX: %f, prm->p_cam.dirY: %f", prm->player.c,prm->player.r,prm->p_cam.dirX, prm->p_cam.dirY);
	return 0;
}

int     render_next_frame(t_params *prm)
{
	ft_basic_frame(prm);
	ft_walls(prm);
	return 0;
}

int             main(void)
{
	int fd = 0;
	t_params *prm = NULL;

	int sizex;
  	int sizey;

////	if ((fd = open("/Users/lesia/Study/21_school/cum3d/params.cub", O_RDONLY)) < 0)
////		return -1;
	prm = ft_parcer(prm, fd);
	prm->vars.mlx = mlx_init();
	mlx_get_screen_size(prm->vars.mlx, &sizex, &sizey);
	printf("%d,%d",prm->r.x ,prm->r.y);
//
	if (prm->r.x > sizex)
		prm->r.x = sizex;
	if (prm->r.y > sizey)
		prm->r.y = sizey;
	prm->vars.win = mlx_new_window(prm->vars.mlx, prm->r.x ,prm->r.y, "Cub3d");
	ft_basic_frame(prm);
	ft_walls(prm);
	mlx_hook(prm->vars.win, 2, 1L << 0, ft_action, prm);
	mlx_hook(prm->vars.win, 17, 0, ft_exit, prm);
//	mlx_hook(prm->vars.win, 3, 1L<<1, ft_basic_frame, 0);
	mlx_loop_hook(prm->vars.win, render_next_frame, prm);
	mlx_loop(prm->vars.mlx);
}

//gcc main.c parcer.c libft.a ./mlx_mms/libmlx.dylib  -framework OpenGL -framework AppKit