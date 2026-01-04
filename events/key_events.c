/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 02:16:56 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 22:13:39 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	ft_printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 122)
		ft_move_up(mlx);
	else if (keycode == 115)
		ft_move_down(mlx);
	else if (keycode == 113)
		ft_move_left(mlx);
	else if (keycode == 100)
		ft_move_right(mlx);
	else if (keycode == 114)
		ft_reset_view(mlx);
	return (0);
}
