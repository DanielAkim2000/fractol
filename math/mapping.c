/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 22:27:34 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 02:49:49 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	ft_convert_screen_to_complex(t_pixel *pixel, t_mlx *mlx)
{
	return ((t_complex){
		.re = mlx->view.min_re + pixel->x * \
			(mlx->view.max_re - mlx->view.min_re) / mlx->width,
		.im = mlx->view.max_im - pixel->y * (mlx->view.max_im - mlx->view.min_im) / \
			mlx->height
	});
}
