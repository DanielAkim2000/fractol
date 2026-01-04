/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:19:18 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 00:20:36 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_abs(double d)
{
	if (d <= 0)
		return (-d);
	return (d);
}

double	ft_carre(double d)
{
	return (d * d);
}

int	ft_floor(float f)
{
	return ((int)f);
}

int	ft_ceil(float f)
{
	int	i;

	i = (int)f;
	if ((float)i < f)
		i++;
	return (i);
}
