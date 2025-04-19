/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:48:41 by yohasega          #+#    #+#             */
/*   Updated: 2025/04/19 14:52:26 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 色の深さを計算するのにdoubleで座標を宣言するが、実際に色計算する時はint
static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	// img->addr（画像データの開始アド）からのオフセットした位置をセット
	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	// 上記の位置にカラーを追記
	*(int *)pixel = color;
}

static int	julia(double x, double y, t_fractol *f)
{
	double	zr;	// 複素数の実部
	double	zi;	// 複素数の虚部
	double	tmp;
	int		iter;

	zr = x;
	zi = y;
	iter = 0;
	while (iter < f->max_iter)
	{
		tmp = 2 * zr * zi - f->arg_i;
		zr = zr * zr - zi * zi + f->arg_r;
		zi = tmp;
		// zrの2乗 + ziの2乗 が4.0を超える場合は無限大に発散すると判断してループ終了
		if ((zr * zr + zi * zi) > 4)
			break ;
		iter++;
	}
	return (iter);
}

static int	mandelbrot(double x, double y, t_fractol *f)
{
	double	zr;	// 複素数の実部
	double	zi;	// 複素数の虚部
	double	tmp;
	int		iter;

	zr = 0;
	zi = 0;
	iter = 0;
	while (iter < f->max_iter)
	{
		tmp = 2 * zr * zi + y;
		zr = zr * zr - zi * zi + x;
		zi = tmp;
		// zrの2乗 + ziの2乗 が4.0を超える場合は無限大に発散すると判断してループ終了
		if ((zr * zr + zi * zi) > 4)
			break ;
		iter++;
	}
	return (iter);
}

static void	get_fractal_image(t_fractol *f)
{
	double	x;
	double	y;
	double	map_r;
	double	map_i;
	int		iter;

	x = -1;
	iter = 0;
	// 高さ×幅の全ピクセルについて計算
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			map_r = f->min_r + (x * (f->max_r - f->min_r)) / WIDTH;
			map_i = f->min_i + (y * (f->max_i - f->min_i)) / HEIGHT;
			// Mandelbrotの場合
			if (f->kind == 1)
				iter = mandelbrot(map_r, map_i, f);
			// Juliaの場合
			else if (f->kind == 2)
				iter = julia(map_r, map_i, f);
			// 収束していれば黒色、そうでなければ基準色に深さをもたせる
			if (iter == f->max_iter)
				img_pix_put(&f->img, x, y, 0x000000);
			else
				img_pix_put(&f->img, x, y, f->color * iter * iter);
		}
	}
}

int	render(t_fractol *f)
{
	// 現在のウィンドウをクリア（MLXのポインタ、ウィンドウのポインタ）
	mlx_clear_window(f->mlx, f->win);
	// フラクタル計算
	get_fractal_image(f);
	// ウィンドウに新しい画像を描画（MLXのポインタ、ウィンドウのポインタ、画像のポインタ、X座標、Y座標）
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (1);
}
