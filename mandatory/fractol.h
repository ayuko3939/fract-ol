/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:14:53 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/25 20:16:14 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>

// ===========================================

# define WIDTH 1000.00
# define HEIGHT 1000.00

// ===========================================

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		kind;
	double	arg_r;
	double	arg_i;
	double	max_r;
	double	max_i;
	double	min_r;
	double	min_i;
	double	max_iter;
	int		color;
	t_img	img;
}			t_fractol;

// ===========================================

int			msg_error(void);
int			msg_julia_prm(void);
int			msg_operation(void);
double		ft_atof(const char *str);
int			init_data(t_fractol *f);
int			close_win(t_fractol *f);
int			key_event(int key, t_fractol *f);
int			mouse_zoom(int key, int x, int y, t_fractol *f);
int			render(t_fractol *f);
int			validate(int ac, char **av, t_fractol *f);

#endif