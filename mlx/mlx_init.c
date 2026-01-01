/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:20:59 by demane            #+#    #+#             */
/*   Updated: 2026/01/01 18:51:09 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init(t_mlx *mlx, t_img *img)
{
	mlx->mlx = mlx_init();
	if (!mlx)
		exit(1);
	mlx->win = mlx_new_window(mlx->mlx, 800, 600, "fractol");
	if (!mlx->win)
	{
		ft_free(&mlx->mlx);
		exit(1);
	}
	img->img = mlx_new_image(mlx->mlx, 800, 600);
	if (!img->addr)
	{
		ft_free(&mlx->mlx);
		ft_free(&mlx->win);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, \
			&img->endian);
	if (!img->addr)
	{
		ft_free(&mlx->mlx);
		ft_free(&mlx->mlx);
		ft_free(&mlx->win);
		ft_free(&img->img);
		exit(1);
	}
}
