/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:10:23 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 16:00:32 by demane           ###   ########.fr       */
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

double	ft_calculation_iteration_julia(t_complex complex, t_complex c, int max_iteration)
{
	int			i;
	t_complex	z;

	i = 0;
	z.im = complex.im;
	z.re = complex.re;
	while (i < max_iteration && (ft_abs_complex(z) <= 4))
	{
		z = ft_zn_carre(z, c);
		i++;
	}
	return (i);
}
