/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:41:43 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 15:13:55 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_move_up(t_mlx *mlx)
{
	double	step;

	step = (mlx->view.max_im - mlx->view.min_im) * 0.05;
	mlx->view.max_im += step;
	mlx->view.min_im += step;
	ft_render_fractal(mlx);
}

void	ft_move_down(t_mlx *mlx)
{
	double	step;

	step = (mlx->view.max_im - mlx->view.min_im) * 0.05;
	mlx->view.max_im -= step;
	mlx->view.min_im -= step;
	ft_render_fractal(mlx);
}

void	ft_move_left(t_mlx *mlx)
{
	double	step;

	step = (mlx->view.max_im - mlx->view.min_im) * 0.05;
	mlx->view.max_re -= step;
	mlx->view.min_re -= step;
	ft_render_fractal(mlx);
}

void	ft_move_right(t_mlx *mlx)
{
	double	step;

	step = (mlx->view.max_im - mlx->view.min_im) * 0.05;
	mlx->view.max_re += step;
	mlx->view.min_re += step;
	ft_render_fractal(mlx);
}
