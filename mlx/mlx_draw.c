/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:13:20 by demane            #+#    #+#             */
/*   Updated: 2026/01/03 21:49:33 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_put_pixel(t_img *img, t_pixel p)
{
	char			*pixel;
	unsigned int	*pix_color;

	pixel = img->addr + (p.y * img->line_len) + (p.x * (img->bpp / 8));
	pix_color = (unsigned int *)pixel;
	pix_color[0] = p.color;
}
