/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:00:12 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 13:12:31 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	ft_complex_carre(t_complex z)
{
	return ((t_complex){
		.re = (ft_carre(z.re) - ft_carre(z.im)),
		.im = 2 * z.im * z.re
	});
}

double	ft_abs_complex(t_complex z)
{
	return (sqrt(ft_carre(z.re) + ft_carre(z.im)));
}
