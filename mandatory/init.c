/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:45:25 by yohasega          #+#    #+#             */
/*   Updated: 2025/04/19 14:49:34 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	release_all(t_fractol *f)
{
	if (f->img.img != NULL)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->win != NULL)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx != NULL)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
}

static void	clean_data(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->max_r = 0;
	f->max_i = 0;
	f->min_r = 0;
	f->min_i = 0;
	f->max_iter = 0;
	f->color = 0;
	f->img.img = NULL;
	f->img.addr = NULL;
	f->img.bpp = 0;
	f->img.line_size = 0;
	f->img.endian = 0;
}

static void	set_fractal(t_fractol *f)
{
	// mandelbrot
	if (f->kind == 1)
	{
		f->min_r = -2.2;
		f->max_r = 1.0;
		f->min_i = -1.5;
		f->max_i = (f->max_r - f->min_r) * HEIGHT / WIDTH + f->min_i;
		f->max_iter = 30;
		f->color = 265;
	}
	// julia
	else if (f->kind == 2)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = (f->max_r - f->min_r) * HEIGHT / WIDTH + f->min_i;
		f->max_iter = 30;
		f->color = 265;
	}
}

int	init_data(t_fractol *f)
{
	// 初期化
	clean_data(f);
	// MLXインスタンスのポインタを取得
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		return (0);
	// ウィンドウを新規作成（このMLXインスタンスのポインタ、幅、高さ、ウィンドウ名）
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (f->win == NULL)
	{
		release_all(f);
		return (0);
	}
	// イメージを新規作成（このMLXインスタンスのポインタ、幅、高さ）
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (f->img.img == NULL)
	{
		release_all(f);
		return (0);
	}
	// イメージデータのメモリアドレスを取得（画像のポインタ、bits/pixel、１行のバイト数、順序）
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.line_size,
			&f->img.endian);
	if (f->img.addr == NULL)
	{
		release_all(f);
		return (0);
	}
	// フラクタル情報を取得
	set_fractal(f);
	return (1);
}
