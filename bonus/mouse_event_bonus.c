/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:56:31 by yohasega          #+#    #+#             */
/*   Updated: 2024/08/26 10:52:14 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
		f->max_iter += 2;
	}
	if (key == 5)
	{
		f->min_r -= width * (x / (double)WIDTH) / 5;
		f->max_r += width * (1 - x / (double)WIDTH) / 5;
		f->min_i -= height * (y / (double)HEIGHT) / 5;
		f->max_i += height * (1 - y / (double)HEIGHT) / 5;
		if (f->max_iter > 30)
			f->max_iter -= 2;
	}
	return (0);
}
