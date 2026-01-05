/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:20:35 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 15:08:55 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_exit_mlx(void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	ft_free_all_mlx(mlx);
	exit(1);
	return (0);
}
