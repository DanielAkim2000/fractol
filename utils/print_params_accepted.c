/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params_accepted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:28:36 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 23:03:18 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_print_params_accepted(void)
{
	ft_printf("#========================================================#\n");
	ft_printf("|| Bienvenue dans mon programme affichant les fractals  ||\n");
	ft_printf("||                                                      ||\n");
	ft_printf("|| *Les params valides pour le programme sont:          ||\n");
	ft_printf("||                                                      ||\n");
	ft_printf("|| # ./fractol mandelbrot                               ||\n");
	ft_printf("|| # ./fractol burning_ship                             ||\n");
	ft_printf("|| # ./fractol julia re im ex: ./fractol julia 0.3 0.2  ||\n");
	ft_printf("#========================================================#\n");
	exit(1);
}
