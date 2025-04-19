/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:14:26 by yohasega          #+#    #+#             */
/*   Updated: 2025/04/19 14:38:22 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	if (!validate(ac, av, &f))
		return (-1);
	if (!init_data(&f))
		return (0);
	msg_operation();
	mlx_loop_hook(f.mlx, &render, &f);
	mlx_hook(f.win, 2, 1L << 0, &key_event, &f);
	mlx_hook(f.win, 4, 1L << 2, &mouse_zoom, &f);
	mlx_hook(f.win, 17, 0L, &close_win, &f);
	mlx_loop(f.mlx);
	return (0);
}
