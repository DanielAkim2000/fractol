/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:29:33 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 15:34:02 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>

double ft_atod(char *str)
{
    int sign = 1;
    double result = 0.0;
    double fraction = 0.0;
    double div = 10.0;

    // 1. Ignorer les espaces
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;

    // 2. Gérer le signe
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // 3. Partie entière
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10.0 + (*str - '0');
        str++;
    }

    // 4. Partie décimale
    if (*str == '.')
    {
        str++;
        while (*str >= '0' && *str <= '9')
        {
            fraction += (*str - '0') / div;
            div *= 10.0;
            str++;
        }
    }

    return sign * (result + fraction);
}
