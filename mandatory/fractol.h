/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:14:53 by yohasega          #+#    #+#             */
/*   Updated: 2025/04/19 14:46:53 by yohasega         ###   ########.fr       */
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
	void	*img;		// 画像のメモリアドレス
	void	*addr;		// 画像の中身のメモリアドレス
	int		bpp;		// bits_per_pixel : １ピクセルあたりのビット数
	int		line_size;	// 1行あたりのバイト数
	int		endian;		// 画像内のピクセルの色順序 0:低位バイトから  1:上位バイトから
}			t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		kind;
	double	arg_r;	// julia real constant
	double	arg_i;	// julia imaginary constant
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