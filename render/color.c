/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 23:41:10 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 23:10:16 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_assign_rgb(int rgb1[3], int rgb2[3], t_palet *palet, int step[2])
{
	rgb1[0] = (palet->colors[step[0]] >> 16) & 0xFF;
	rgb1[1] = (palet->colors[step[0]] >> 8) & 0xFF;
	rgb1[2] = (palet->colors[step[0]]) & 0xFF;
	rgb2[0] = (palet->colors[step[1]] >> 16) & 0xFF;
	rgb2[1] = (palet->colors[step[1]] >> 8) & 0xFF;
	rgb2[2] = (palet->colors[step[1]]) & 0xFF;
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
	ft_assign_rgb(rgb[0], rgb[1], palet, step);
	ft_assign_rgb_final(rgb[2], rgb[1], rgb[0], (float)(pos - step[0]));
	return ((rgb[2][0] << 16) | ((rgb[2][1]) << 8) | (rgb[2][2]));
}

void	ft_change_colors(t_mlx *mlx, int index_colors)
{
	t_palet	palets[4];
	int		i;

	if (index_colors >= 4 || index_colors < 0)
		return ((void)0);
	palets[0] = (t_palet){
		.colors = {0x2c061f, 0x5a082d, 0x9a031e, 0xfb8b24, 0xe36414, 0xfec89a, \
			0xffddd2, 0xffffff, 0x000000}, .nb_colors = 9};
	palets[1] = (t_palet){
		.colors = {0x0f1021, 0x2b2d42, 0x8d99ae, 0xef233c, 0xff006e, 0x8338ec, \
			0x3a86ff, 0xffffff, 0x000000}, .nb_colors = 9};
	palets[2] = (t_palet){
		.colors = {0x081c15, 0x1b4332, 0x2d6a4f, 0x40916c, 0x52b788, 0x95d5b2, \
			0xd8f3dc, 0xffffff, 0x000000}, .nb_colors = 9};
	palets[3] = (t_palet){
		.colors = {0x0d1b2a, 0x1b263b, 0x415a77, 0x778da9, 0xe0e1dd, 0xbfc0c0, \
			0x8d99ae, 0xffffff, 0x000000}, .nb_colors = 9};
	i = -1;
	while (++i < palets[index_colors].nb_colors)
		mlx->palet.colors[i] = palets[index_colors].colors[i];
	ft_render_fractal(mlx);
}

void	ft_assign_palet_colors(t_mlx *mlx, t_palet *palet_pre)
{
	int	i;

	i = -1;
	while (++i < palet_pre->nb_colors)
		mlx->palet.colors[i] = palet_pre->colors[i];
	mlx->palet.nb_colors = palet_pre->nb_colors;
}
