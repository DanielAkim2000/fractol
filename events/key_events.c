/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 02:16:56 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 18:09:15 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == 65307)
		ft_exit_mlx((void *)mlx);
	else if (keycode == 109)
		ft_change_colors(mlx, 3);
	else if (keycode == 108)
		ft_change_colors(mlx, 2);
	else if (keycode == 107)
		ft_change_colors(mlx, 1);
	else if (keycode == 110)
		ft_change_colors(mlx, 0);
	else if (keycode == 119)
		ft_move_up(mlx);
	else if (keycode == 115)
		ft_move_down(mlx);
	else if (keycode == 97)
		ft_move_left(mlx);
	else if (keycode == 100)
		ft_move_right(mlx);
	else if (keycode == 114)
		ft_reset_view(mlx);
	return (0);
}
