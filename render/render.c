/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 03:07:52 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 17:35:46 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	ft_calcul_iteration(t_mlx *mlx, t_complex z)
{
	if (ft_strncmp(mlx->name_fractal, "mandelbrot", 11) == 0)
		return (ft_calculation_iteration_mandelbrot(z, mlx->max_iteration));
	if (ft_strncmp(mlx->name_fractal, "julia", 5) == 0)
		return (ft_calculation_iteration_julia(z, mlx->julia_cnst, \
			mlx->max_iteration));
	if (ft_strncmp(mlx->name_fractal, "burning_ship", 12) == 0)
		return (ft_calculation_iteration_burning_ship(z, mlx->max_iteration));
	return (0);
}

void	ft_render_all_pixel(t_mlx *mlx, int i)
{
	t_pixel	pixel;
	int		it;
	int		j;

	j = -1;
	while (++j < mlx->width)
	{
		pixel.x = j;
		pixel.y = i;
		it = ft_calcul_iteration(
				mlx,
				ft_convert_screen_to_complex(&pixel, mlx));
		if (it >= mlx->max_iteration)
		{
			pixel.color = 0x00000000;
			ft_put_pixel(&(mlx->img[mlx->img_render]), pixel);
		}
		else
		{
			pixel.color = ft_get_color(it, mlx->max_iteration, &(mlx->palet));
			ft_put_pixel(&(mlx->img[mlx->img_render]), pixel);
		}
	}
}

void	ft_render_fractal(t_mlx *mlx)
{
	int		i;

	i = -1;
	while (++i < mlx->height)
		ft_render_all_pixel(mlx, i);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[mlx->img_render].img, \
		0, 0);
	mlx->img_render = 1 - mlx->img_render;
}
