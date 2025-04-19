/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:56:31 by yohasega          #+#    #+#             */
/*   Updated: 2025/04/19 14:50:56 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int key, int x, int y, t_fractol *f)
{
	double	width;
	double	height;

	width = f->max_r - f->min_r;
	height = f->max_i - f->min_i;
	if (key == 4)
	{
		f->min_r += width * (x / (double)WIDTH) / 5;
		f->max_r -= width * (1 - x / (double)WIDTH) / 5;
		f->min_i += height * (y / (double)HEIGHT) / 5;
		f->max_i -= height * (1 - y / (double)HEIGHT) / 5;
		f->max_iter += 2;	// 計算回数の上限を加算
	}
	if (key == 5)
	{
		f->min_r -= width * (x / (double)WIDTH) / 5;
		f->max_r += width * (1 - x / (double)WIDTH) / 5;
		f->min_i -= height * (y / (double)HEIGHT) / 5;
		f->max_i += height * (1 - y / (double)HEIGHT) / 5;
		if (f->max_iter > 30)	// 計算回数の下限を設定
			f->max_iter -= 2;
	}
	return (0);
}

// 	// マウス位置（x,y）を考慮しない
// int	mouse_zoom(int key, int x, int y, t_fractol *f)
// {
// 	double width;
// 	double height;

// 	x = 1;
// 	y = 1;
// 	width = f->max_r - f->min_r;
// 	height = f->max_i - f->min_i;
// 	if (key == 4)
// 	{
// 		f->max_r -= width / 10;
// 		f->min_r += width / 10;
// 		f->max_i -= height / 10;
// 		f->min_i += height / 10;
// 	}
// 	if (key == 5)
// 	{
// 		f->max_r += width / 10;
// 		f->min_r -= width / 10;
// 		f->max_i += height / 10;
// 		f->min_i -= height / 10;
// 	}
// 	return (1);
// }
