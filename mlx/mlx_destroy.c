/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:22:09 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 15:00:23 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_destroy_all(t_mlx *mlx)
{
	if (mlx->img[0].img)
	{
		mlx_destroy_image(mlx->mlx, mlx->img[0].img);
		mlx->img[0].img = NULL;
		mlx->img[0].addr = NULL;
	}
	if (mlx->img[1].img)
	{
		mlx_destroy_image(mlx->mlx, mlx->img[1].img);
		mlx->img[1].img = NULL;
		mlx->img[1].addr = NULL;
	}
	if (mlx->win)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx->win = NULL;
	}
	if (mlx->loop)
		mlx_loop_end(mlx->mlx);
	mlx_destroy_display(mlx->mlx);
}
