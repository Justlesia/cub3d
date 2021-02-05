/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:48 by sbrenton          #+#    #+#             */
/*   Updated: 2021/02/05 19:34:08 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft/libft.h"
#	include "cub3d.h"
#	include <stdlib.h>
#	include <zconf.h>
#	include <fcntl.h>
# 	include "mlx_mms/mlx.h"
#include <math.h>

t_cam_params ft_camera_params(char position, t_cam_params p_cam)
{
	if (position == 'N')
	{
		p_cam.dirX = 0;
		p_cam.dirY = -1;
		p_cam.planeX = 0.66;
		p_cam.planeY = 0;
	}
	if (position == 'E')
	{
		p_cam.dirX = 1;
		p_cam.dirY = 0;
		p_cam.planeX = 0;
		p_cam.planeY = 0.66;
	}
	if (position == 'S')
	{
		p_cam.dirX = 0;
		p_cam.dirY = 1;
		p_cam.planeX = -0.66;
		p_cam.planeY = 0;
	}
	else
	{
		p_cam.dirX = -1;
		p_cam.dirY = 0;
		p_cam.planeX = 0;
		p_cam.planeY = -0.66;
	}
	return p_cam;
}


int ft_basic_frame(t_params *prm)
{
//	mlx_string_put (prm->vars.mlx, prm->vars.win, 55, 55, 0xFFFFFF,"THIS");
//
	int width;
	int length;

	prm->c.r = 255;
	prm->c.g = 255;
	prm->c.b = 255;

	int c =  prm->c.b <<  16 | prm->c.r << 8| prm->c.g ;
	int f =  prm->f.b <<  16 | prm->f.r << 8| prm->f.g ;

	width = 0;
	while(width < prm->r.x + 0)
	{
//		mlx_string_put (prm->vars.mlx, prm->vars.win, 55, 55, 0xFFFFFF,".");
		length = 0;
		while(length < prm->r.y)
		{
			if (length < prm->r.y/2)
				mlx_pixel_put(prm->vars.mlx, prm->vars.win, 0 + width, 0+length, c);
			else
				mlx_pixel_put(prm->vars.mlx, prm->vars.win, 0 + width, 0+length, f);
//			mlx_string_put (prm->vars.mlx, prm->vars.win, 66, 66, 0xFFFFFF,".");
			length++;
		}
		width++;
	}
	return 0;
}

int ft_walls(t_params *prm)
{


//	for(int x = 0; x < w; x++)
//	{
//		//calculate ray position and direction
//		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
//		double rayDirX = dirX + planeX * cameraX;
//		double rayDirY = dirY + planeY * cameraX;
//		//which box of the map we're in
//		int mapX = (int)(posX);
//		int mapY = (int)(posY);
//
//		//length of ray from current position to next x or y-side
//		double sideDistX;
//		double sideDistY;
//
//		//length of ray from one x or y-side to next x or y-side
//		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
//		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
//		double perpWallDist;
//
//		//what direction to step in x or y-direction (either +1 or -1)
//		int stepX;
//		int stepY;
//
//		int hit = 0; //was there a wall hit?
//		int side; //was a NS or a EW wall hit?
//		//calculate step and initial sideDist
//		if(rayDirX < 0)
//		{
//			stepX = -1;
//			sideDistX = (posX - mapX) * deltaDistX;
//		}
//		else
//		{
//			stepX = 1;
//			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
//		}
//		if(rayDirY < 0)
//		{
//			stepY = -1;
//			sideDistY = (posY - mapY) * deltaDistY;
//		}
//		else
//		{
//			stepY = 1;
//			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
//		}
//		//perform DDA
//		while (hit == 0)
//		{
//			//jump to next map square, OR in x-direction, OR in y-direction
//			if(sideDistX < sideDistY)
//			{
//				sideDistX += deltaDistX;
//				mapX += stepX;
//				side = 0;
//			}
//			else
//			{
//				sideDistY += deltaDistY;
//				mapY += stepY;
//				side = 1;
//			}
//			//Check if ray has hit a wall
//			if(prm->map.self[mapY][mapX] > 0) hit = 1;
//		}
//		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
//		if(side == 0)
//		{
//			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
//			printf("mapX-%d,posX-%d, stepX - %f, rayDirX - %f, perpWallDist - %f\n", mapX, posX, stepX, rayDirX, perpWallDist);
//		}
//		else
//		{
//			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
//			printf("mapY-%d,posY-%d, stepY - %f, rayDirY - %f, perpWallDist - %f\n", mapY, posY, stepY, rayDirY, perpWallDist);
//		}
//
//
//
////		perpWallDist = 1;
//		//Calculate height of line to draw on screen
//		int lineHeight = (int)(h / perpWallDist);
//
//		//calculate lowest and highest pixel to fill in current stripe
//		int drawStart = -lineHeight / 2 + h / 2;
//		if(drawStart < 0)drawStart = 0;
//		int drawEnd = lineHeight / 2 + h / 2;
//		if(drawEnd >= h)drawEnd = h - 1;
//
//		int color = 0x344577;
//		//give x and y sides different brightness
//		if(side == 1) {color = color / 2;}
//
////		printf("mapX-%d,mapY-%d, sideDistX - %f, sideDistY - %f, perpWallDist - %f\n", mapX, mapY, sideDistX, sideDistY, perpWallDist);
//
//		//draw the pixels of the stripe as a vertical line
//		while(drawStart < drawEnd)
//		{
//			mlx_pixel_put(prm->vars.mlx, prm->vars.win, 0 + x, 0 + drawStart, color);
//			drawStart++;
//		}
//	}

//	for (int x = 0; x < prm->r.x; x++)
//	{
//		//calculate ray position and direction
//		double cameraX = 2 * x / (double)prm->map.r - 1; //x-coordinate in camera space
//		double rayDirX = prm->p_cam.dirX + prm->p_cam.planeX * cameraX;
//		double rayDirY = prm->p_cam.dirY + prm->p_cam.planeY * cameraX;
//		//which box of the map we're in
//		int mapX = (int)prm->player.r;
//		int mapY = (int)prm->player.c;
//
//		//length of ray from current position to next x or y-side
//		double sideDistX;
//		double sideDistY;
//
//		//length of ray from one x or y-side to next x or y-side
//		double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
//		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
//		double perpWallDist;
//
//		//what direction to step in x or y-direction (either +1 or -1)
//		int stepX;
//		int stepY;
//
//		int hit = 0; //was there a wall hit?
//		int side; //was a NS or a EW wall hit?
//		//calculate step and initial sideDist
//		if (rayDirX > 0)
//		{
//			stepX = -1;
//			sideDistX = (prm->player.c - mapX) * deltaDistX;
//		} else
//		{
//			stepX = 1;
//			sideDistX = (mapX + 1.0 - prm->player.c) * deltaDistX;
//		}
//		if (rayDirY > 0)
//		{
//			stepY = -1;
//			sideDistY = (prm->player.r - mapY) * deltaDistY;
//		} else
//		{
//			stepY = 1;
//			sideDistY = (mapY + 1.0 - prm->player.r) * deltaDistY;
//		}
//		//perform DDA
//		perpWallDist = 0;
//		while (hit == 0)
//		{
//			//jump to next map square, OR in x-direction, OR in y-direction
//			if (sideDistX < sideDistY)
//			{
//				sideDistX += deltaDistX;
//				mapX += stepX;
//				side = 0;
//			} else
//			{
//				sideDistY += deltaDistY;
//				mapY += stepY;
//				side = 1;
//			}
//			//Check if ray has hit a wall
//			if (prm->map.self[mapX][mapY] > 0)
//			{
//				hit = 1;
//			}
//		}
//		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
//		if (side == 0)
//		{
//			perpWallDist = (mapX - prm->player.c + (1 - stepX) / 2) / rayDirX;
//		} else
//		{
//			perpWallDist = (mapY - prm->player.r + (1 - stepY) / 2) / rayDirY;
//		}
//
//
//
//
//
//
//		//Calculate height of line to draw on screen
//		int lineHeight = (int)(prm->r.y / perpWallDist);
//
//		//calculate lowest and highest pixel to fill in current stripe
//		int drawStart = -lineHeight / 2 + prm->r.y / 2;
//		if (drawStart < 0)
//			drawStart = 0;
//		int drawEnd = lineHeight / 2 + prm->r.y / 2;
//		if (drawEnd >= prm->r.y)
//			drawEnd = prm->r.y - 1;
//
//
//		int color = 0x344577;
//		//give x and y sides different brightness
//		if (side == 1)
//		{ color = color / 2; }
//
//		printf("mapX-%d,mapY-%d, sideDistX - %f, sideDistY - %f, perpWallDist - %f\n", mapX, mapY, sideDistX, sideDistY, perpWallDist);
//
//		//draw the pixels of the stripe as a vertical line
//		while (drawStart < drawEnd)
//		{
//			mlx_pixel_put(prm->vars.mlx, prm->vars.win, 0 + x, 0 + drawStart, color);
//			drawStart++;
//		}
//	}


	int w = prm->r.x;
	int h = prm->r.y;
	double dirX = prm->p_cam.dirX ;
	double dirY = prm->p_cam.dirY ;

	double planeX = prm->p_cam.planeX ;
	double planeY = prm->p_cam.planeY ;

	double posX = prm->player.c + 0.5;
	double posY = prm->player.r + 0.5;

	char **map = prm->map.self;

	int x, mapX, mapY, stepX, stepY, hit, side, lineHeight, drawStart, drawEnd;
	double cameraX, rayDirX, rayDirY, deltaDistX, deltaDistY, perpWallDist, \
			sideDistX, sideDistY;

	for (x = 0; x < w; x++)
	{
		cameraX = 2 * x / (double)(w)-1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;

		deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
		deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));

		mapX = (int)(posX);
		mapY = (int)(posY);

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		} else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		} else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		hit = 0;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			} else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (map[mapY][mapX] > 0)
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)drawEnd = h - 1;

		int color = 0x344577;
		//give x and y sides different brightness
		if(side == 1) {color = color / 2;}

		printf("mapX-%d,mapY-%d, sideDistX - %f, sideDistY - %f, perpWallDist - %f\n", mapX, mapY, sideDistX, sideDistY, perpWallDist);

		//draw the pixels of the stripe as a vertical line
		while(drawStart < drawEnd)
		{
			mlx_pixel_put(prm->vars.mlx, prm->vars.win, 0 + x, 0 + drawStart, color);
			drawStart++;
		}
	}

	return 0;
}