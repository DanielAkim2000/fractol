/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:56:19 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 21:54:13 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac || av)
	{
		ft_init_fractol(&mlx, 800, 600, av);
		ft_render_fractal(&mlx);
		mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
		mlx_key_hook(mlx.win, ft_key_hook, &mlx);
		mlx_loop(mlx.mlx);
	}
}
