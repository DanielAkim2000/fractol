/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:23:42 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 17:04:47 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_free_all_mlx(t_mlx *mlx)
{
	ft_destroy_all(mlx);
	ft_free((void **)&mlx->mlx);
	ft_free((void **)&mlx->win);
	ft_free((void **)&mlx->img[0].img);
	ft_free((void **)&mlx->img[1].img);
	ft_free((void **)&mlx->img[0].addr);
	ft_free((void **)&mlx->img[1].addr);
}
