/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:56:19 by demane            #+#    #+#             */
/*   Updated: 2026/01/01 18:40:50 by demane           ###   ########.fr       */
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
		mlx_loop(mlx.mlx);
	}
}
