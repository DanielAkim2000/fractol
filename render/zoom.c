/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 02:23:32 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 21:17:37 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom_at(t_mlx *mlx, int x, int y, float zoom_val)
{
	t_complex	center;
	double		new_width;
	double		new_heigth;
	t_pixel		pixel;

	pixel.x = x;
	pixel.y = y;
	center = ft_convert_screen_to_complex(&pixel, mlx);
	new_width = (mlx->view.max_re - mlx->view.min_re) * zoom_val;
	new_heigth = (mlx->view.max_im - mlx->view.min_im) * zoom_val;
	mlx->view.max_im = center.im + new_heigth / 2;
	mlx->view.max_re = center.re + new_width / 2;
	mlx->view.min_re = center.re - new_width / 2;
	mlx->view.min_im = center.im - new_heigth / 2;
}
