/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:56:19 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 16:28:20 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_verif(int ac, char **av)
{
	if (ac < 2)
		exit(1);
	if (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) == 0)
	{
		if (ac != 2)
			exit (1);
		return ((void)0);
	}
	if (ft_strncmp(av[1], "julia", ft_strlen(av[1])) == 0)
	{
		if (ac != 4)
			exit (1);
		return ((void)0);
	}
	if (ft_strncmp(av[1], "burning_ship", ft_strlen(av[1])) == 0)
	{
		if (ac != 2)
			exit(1);
		return ((void)0);
	}
	exit(1);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	ft_verif(ac, av);
	ft_init_fractol(&mlx, 800, 600, av);
	ft_render_fractal(&mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_key_hook(mlx.win, ft_key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_exit_mlx, &mlx);
	mlx.loop = 1;
	mlx_loop(mlx.mlx);
}
