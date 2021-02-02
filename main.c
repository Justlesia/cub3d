#include <stdio.h>
//#include "libft.a"
#include "cub3d.h"
# include "mlx_mms/mlx.h"
#	include "libft/libft.h"
#	include "cub3d.h"
#	include <stdlib.h>
#	include <zconf.h>
#	include <fcntl.h>
//#include "libft/libft.h"
//#	include "libft/libft.h"
//#	include "cub3d.h"
//#	include <stdlib.h>
////#	include <unistd.h>
////#	include <stdio.h>
////#	include <zconf.h>
////#	include <fcntl.h>
////#include <tclDecls.h>
//

typedef struct  s_vars {
	void    *mlx;
	void    *win;
}               t_vars;


int             ft_close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}

int             main(void)
{
	t_vars    vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);


int deal_key(int key, void *param)
{
	write(1,"X",1);
	//mlx_pixel_put(mlx_ptr, win_ptr )
	mlx_pixel_put(param->mlx_ptr, param->win_ptr, 25,50, 0xFFFFFF);
	return (0);
}


//int main(void)
//{
//	void *mlx_ptr;
//	void *win_ptr;
//
//	t_params *prm;
//	int fd;
//
//	int sizex;
//	int sizey;
//
//
//
////	if ((fd = open("/Users/lesia/Study/21_school/cum3d/params.cub", O_RDONLY)) < 0)
////		return -1;
//	prm = ft_parcer(prm, fd);
//	printf("%d - %d \n", prm->r.x, prm->r.y);
//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr,  prm->r.x,prm->r.y, "test");
//	mlx_pixel_put(mlx_ptr, win_ptr, 50,50, 0xFFFFFF);
//
//	mlx_key_hook(win_ptr, deal_key, mlx_ptr);
//
//	mlx_loop(mlx_ptr);
//
////	printf("Hello, World!\n");
//	return 0;
//}


//gcc main.c parcer.c libft.a ./mlx_mms/libmlx.dylib  -framework OpenGL -framework AppKit


