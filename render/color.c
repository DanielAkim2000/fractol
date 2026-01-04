/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 23:41:10 by demane            #+#    #+#             */
/*   Updated: 2026/01/04 22:34:20 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_assign_rgb1(int rgb[3], t_palet *palet, int step[2])
{
	rgb[0] = (palet->colors[step[0]] >> 16) & 0xFF;
	rgb[1] = (palet->colors[step[0]] >> 8) & 0xFF;
	rgb[2] = (palet->colors[step[0]]) & 0xFF;
}

static void	ft_assign_rgb2(int rgb[3], t_palet *palet, int step[2])
{
	rgb[0] = (palet->colors[step[1]] >> 16) & 0xFF;
	rgb[1] = (palet->colors[step[1]] >> 8) & 0xFF;
	rgb[2] = (palet->colors[step[1]]) & 0xFF;
}

static void	ft_assign_rgb_final(int rgb3[3], int rgb2[3], int rgb1[3], \
	float fract)
{
	rgb3[0] = rgb1[0] + fract * (rgb2[0] - rgb1[0]);
	rgb3[1] = rgb1[1] + fract * (rgb2[1] - rgb1[1]);
	rgb3[2] = rgb1[2] + fract * (rgb2[2] - rgb1[2]);
}

int	ft_get_color(double it, int max, t_palet *palet)
{
	float	norm;
	float	pos;
	int		step[2];
	int		rgb[3][3];

	norm = (float)it / (float)max;
	pos = (float)(norm * (palet->nb_colors - 1));
	step[0] = ft_floor(pos);
	step[1] = step[0] + 1;
	if (step[1] >= palet->nb_colors)
		step[1] -= 1;
	ft_assign_rgb1(rgb[0], palet, step);
	ft_assign_rgb2(rgb[1], palet, step);
	ft_assign_rgb_final(rgb[2], rgb[1], rgb[0], (float)(pos - step[0]));
	return ((rgb[2][0] << 16) | ((rgb[2][1]) << 8) | (rgb[2][2]));
}

void	ft_assgin_palet_colors(t_palet *palet)
{
	palet->colors[0] = 0x0f0c29;
	palet->colors[1] = 0x302b63;
	palet->colors[2] = 0x24243e;
	palet->colors[3] = 0x3a6073;
	palet->colors[4] = 0x5f9cff;
	palet->colors[5] = 0xa1c4fd;
	palet->colors[6] = 0xd4fcff;
	palet->colors[7] = 0xffffff;
	palet->colors[8] = 0x000000;
	palet->nb_colors = 9;
}
