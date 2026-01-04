/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:04:26 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 22:17:32 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_reset_view(t_mlx *mlx)
{
	if (ft_strncmp(mlx->name_fractal, "mandlebrot", 11) == 0)
		ft_init_mandlebrot(mlx);
	if (ft_strncmp(mlx->name_fractal, "julia", 5) == 0)
		ft_init_julia(mlx, mlx->julia_cnst);
	if (ft_strncmp(mlx->name_fractal, "burning_ship", 12) == 0)
		ft_init_burning_ship(mlx);
	mlx->max_iteration = 50;
	ft_render_fractal(mlx);
}
