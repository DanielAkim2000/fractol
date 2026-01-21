/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:56:19 by demane            #+#    #+#             */
/*   Updated: 2026/01/21 14:14:18 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_init_fn_j_a(int *i, int *nbr_number, int *nbr_point, int *is_zero)
{
	*i = 0;
	*nbr_number = 0;
	*nbr_point = 0;
	*is_zero = 1;
}

void	ft_skip_minus_or_space(int *i, char *double_str)
{
	while (double_str[*i] && double_str[*i] == ' ')
		(*i)++;
	if (double_str[*i] && double_str[*i] == '-')
		(*i)++;
}

int	ft_is_julia_accepted(char *double_str)
{
	int	i;
	int	nbr_point;
	int	nbr_number;
	int	is_zero;

	ft_init_fn_j_a(&i, &nbr_number, &nbr_point, &is_zero);
	ft_skip_minus_or_space(&i, double_str);
	while (double_str[i] != '\0')
	{
		if (!ft_isdigit(double_str[i]) && double_str[i] != '.')
			return (0);
		if (ft_isdigit(double_str[i]) && double_str[i] != '0'
			&& double_str[i] != '.')
			is_zero = 0;
		if (double_str[i++] == '.')
			nbr_point++;
		else
			nbr_number++;
	}
	if (is_zero && nbr_point <= 1)
		return (1);
	if (nbr_number > 15 || nbr_point > 1)
		return (0);
	return (1);
}

void	ft_verif(int ac, char **av)
{
	if (ac < 2)
		ft_print_params_accepted();
	if (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) == 0)
	{
		if (ac != 2)
			ft_print_params_accepted();
		return ((void)0);
	}
	if (ft_strncmp(av[1], "julia", ft_strlen(av[1])) == 0)
	{
		if (ac != 4)
			ft_print_params_accepted();
		if (!ft_is_julia_accepted(av[2]) || !ft_is_julia_accepted(av[3]))
			ft_print_params_accepted();
		return ((void)0);
	}
	if (ft_strncmp(av[1], "burning_ship", ft_strlen(av[1])) == 0)
	{
		if (ac != 2)
			ft_print_params_accepted();
		return ((void)0);
	}
	ft_print_params_accepted();
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	ft_verif(ac, av);
	ft_init_fractol(&mlx, 1000, 800, av);
	ft_render_fractal(&mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_key_hook(mlx.win, ft_key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_exit_mlx, &mlx);
	mlx.loop = 1;
	mlx_loop(mlx.mlx);
}
