/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:21:34 by demane            #+#    #+#             */
/*   Updated: 2026/01/05 21:22:42 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx_lib/mlx.h"
# include <math.h>

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef struct s_palet
{
	int	colors[20];
	int	nb_colors;
}	t_palet;

typedef struct s_view
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_view;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	double		width;
	double		height;
	t_img		img[2];
	int			img_render;
	t_view		view;
	t_palet		palet;
	char		*name_fractal;
	t_complex	julia_cnst;
	int			max_iteration;
	int			loop;
}	t_mlx;


double		ft_abs(double d);
double		ft_carre(double d);
int			ft_floor(float f);
int			ft_ceil(float f);
double		ft_atod(char *str);
void		ft_move_up(t_mlx *mlx);
void		ft_move_down(t_mlx *mlx);
void		ft_move_left(t_mlx *mlx);
void		ft_move_right(t_mlx *mlx);
void		ft_reset_view(t_mlx *mlx);
void		ft_init_mandlebrot(t_mlx *mlx);
void		ft_init_julia(t_mlx *mlx, t_complex z);
void		ft_init_burning_ship(t_mlx *mlx);
void		ft_init_fractol(t_mlx *mlx, int width, int height, char **av);
void		ft_put_pixel(t_img *img, t_pixel p);
t_complex	ft_complex_carre(t_complex z);
double		ft_abs_complex(t_complex z);
t_complex	ft_convert_screen_to_complex(t_pixel *pixel, t_mlx *mlx);
double		ft_calculation_iteration_mandelbrot(t_complex c, int max_iteration);
void		ft_render_fractal(t_mlx *mlx);
int			ft_get_color(double it, int max, t_palet *palet);
void		ft_change_colors(t_mlx *mlx, int index_colors);
void		ft_assign_palet_colors(t_mlx *mlx, t_palet *palet_pre);
void		ft_zoom_at(t_mlx *mlx, int x, int y, float zoom_val);
int			ft_mouse_hook(int button, int x, int y, void *param);
int			ft_key_hook(int keycode, void *param);
void		ft_free_all_mlx(t_mlx *mlx);
int			ft_exit_mlx(void *params);
void		ft_destroy_all(t_mlx *mlx);
void		ft_print_params_accepted(void);
double		ft_calculation_iteration_julia(t_complex complex, t_complex c, \
	int max_iteration);
double		ft_calculation_iteration_burning_ship(t_complex c, \
	int max_iteration);
#endif
