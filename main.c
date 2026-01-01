/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:56:19 by demane            #+#    #+#             */
/*   Updated: 2026/01/01 19:16:47 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_img	img;

	if (ac || av)
	{
		ft_init(&mlx, &img);
		ft_put_pixel(&img, 300, 300, 0x00FF0000);
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
		mlx_loop(mlx.mlx);
	}
}
