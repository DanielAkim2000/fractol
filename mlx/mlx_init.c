/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:20:59 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 22:18:24 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_mandlebrot(t_mlx *mlx)
{
	mlx->name_fractal = "mandelbrot";
	mlx->view.max_im = 1.5;
	mlx->view.max_re = 1;
	mlx->view.min_re = -2;
	mlx->view.min_im = -1.5;
}

void	ft_init_julia(t_mlx *mlx, t_complex z)
{
	mlx->name_fractal = "julia";
	mlx->view.max_im = 1.5;
	mlx->view.max_re = 1.5;
	mlx->view.min_re = -1.5;
	mlx->view.min_im = -1.5;
	mlx->julia_cnst = z;
}

void	ft_init_burning_ship(t_mlx *mlx)
{
	mlx->name_fractal = "burning_ship";
	mlx->view.max_im = 1.0;
	mlx->view.max_re = 1.5;
	mlx->view.min_re = -2.0;
	mlx->view.min_im = -2.0;
}

void	ft_init_fractol(t_mlx *mlx, int width, int height, char **av)
{

	mlx->mlx = mlx_init();
	if (!mlx)
		exit(1);
	mlx->width = width;
	mlx->height = height;
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "fractol");
	if (!mlx->win)
	{
		ft_free(&mlx->mlx);
		exit(1);
	}
	mlx->img[0].img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	if (!mlx->img[0].img)
	{
		ft_free(&mlx->mlx);
		ft_free(&mlx->win);
		exit(1);
	}
	mlx->img[1].img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	if (!mlx->img[1].img)
	{
		ft_free(&mlx->mlx);
		ft_free(&mlx->win);
		ft_free(&mlx->img[0].img);
		exit(1);
	}
	mlx->img[0].addr = mlx_get_data_addr(mlx->img[0].img, &mlx->img[0].bpp, &mlx->img[0].line_len, \
			&mlx->img[0].endian);
	if (!mlx->img[0].addr)
	{
		ft_free(&mlx->mlx);
		ft_free(&mlx->mlx);
		ft_free(&mlx->win);
		ft_free(&mlx->img[0].img);
		ft_free(&mlx->img[1].img);
		exit(1);
	};
	mlx->img[1].addr = mlx_get_data_addr(mlx->img[1].img, &mlx->img[1].bpp, &mlx->img[1].line_len, \
			&mlx->img[1].endian);
	if (!mlx->img[1].addr)
	{
		ft_free(&mlx->mlx);
		ft_free(&mlx->mlx);
		ft_free(&mlx->win);
		ft_free(&mlx->img[0].img);
		ft_free(&mlx->img[1].img);
		ft_free(&mlx->img[0].addr);
		exit(1);
	};
	mlx->palet.colors = (int *)malloc(sizeof(int) * 9);
	if (!mlx->palet.colors)
	{
		ft_free(&mlx->mlx);
		ft_free(&mlx->mlx);
		ft_free(&mlx->win);
		ft_free(&mlx->img[0].img);
		ft_free(&mlx->img[1].img);
		ft_free(&mlx->img[0].addr);
		ft_free(&mlx->img[1].addr);
	}
	ft_assgin_palet_colors(&(mlx->palet));
	mlx->img_render = 0;
	mlx->max_iteration = 50;
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		ft_init_mandlebrot(mlx);
	if (ft_strncmp(av[1], "julia", 5) == 0)
		ft_init_julia(mlx, (t_complex){
		.re = ft_atod(av[2]),
		.im = ft_atod(av[3])
	});
	if (ft_strncmp(av[1], "burning_ship", 12) == 0)
		ft_init_burning_ship(mlx);
}
