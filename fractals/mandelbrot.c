/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 5026/01/03 21:56:26 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 15:58:47 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_complex	ft_zn_carre(t_complex z, t_complex c)
{
	return ((t_complex){
		.re = (ft_carre(z.re) - ft_carre(z.im) + c.re),
		.im = ((2 * z.re * z.im) + c.im)
	});
}

double	ft_calculation_iteration_mandelbrot(t_complex c, int max_iteration)
{
	int			i;
	t_complex	z;

	i = 0;
	z.im = 0;
	z.re = 0;
	while (i < max_iteration && (ft_abs_complex(z) <= 4))
	{
		z = ft_zn_carre(z, c);
		i++;
	}
	return (i);
}
