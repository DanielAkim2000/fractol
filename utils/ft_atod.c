/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:29:33 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 15:19:02 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>

void	ft_init_atod(int *sign, double *result, double *fraction, double *div)
{
	*sign = 1;
	*result = 0.0;
	*fraction = 0.0;
	*div = 10.0;
}

double	ft_atod(char *str)
{
	int		sign;
	double	result;
	double	fraction;
	double	div;

	ft_init_atod(&sign, &result, &fraction, &div);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*(str++) - '0');
	if (*(str++) == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			fraction += (*str - '0') / div;
			div *= 10.0;
			str++;
		}
	}
	return (sign * (result + fraction));
}
