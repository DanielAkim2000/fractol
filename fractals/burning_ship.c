/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:42:32 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 16:00:51 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_complex	ft_zn_carre(t_complex z, t_complex c)
{
	return ((t_complex){
		.re = (ft_carre(ft_abs(z.re)) - ft_carre(ft_abs(z.im)) + c.re),
		.im = ((2 * ft_abs(z.re) * ft_abs(z.im)) + c.im)
	});
}

double	ft_calculation_iteration_burning_ship(t_complex c, int max_iteration)
{
	int			i;
	t_complex	z;

	i = 0;
	z.im = 0;
	z.re = 0;
	while (i < max_iteration && (ft_abs_complex(z) <= 2))
	{
		z = ft_zn_carre(z, c);
		i++;
	}
	return (i);
}
