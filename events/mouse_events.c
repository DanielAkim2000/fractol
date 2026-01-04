/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 02:17:53 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 22:18:33 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = ((t_mlx *)param);
	if (x < 0 || y < 0 || x >= mlx->width || y >= mlx->height)
		return (0);
	if (button == 4)
	{
		ft_zoom_at((t_mlx *)param, x, y, 0.7);
		if (mlx->max_iteration < 200)
			mlx->max_iteration += 10;
	}
	else if (button == 5)
	{
		ft_zoom_at((t_mlx *)param, x, y, 1.30);
		if (mlx->max_iteration > 50)
			mlx->max_iteration -= 10;
	}
	ft_render_fractal(mlx);
	return (0);
}
