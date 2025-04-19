/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:14:26 by yohasega          #+#    #+#             */
/*   Updated: 2025/04/19 14:45:38 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	// 引数チェック
	if (!validate(ac, av, &f))
		return (-1);
	// 初期化
	if (!init_data(&f))
		return (0);
	// 使い方説明
	msg_operation();
	// 描画
	mlx_loop_hook(f.mlx, &render, &f);
	// キーボード対応（イベント 2:キー押下   マスク 1L<<0:キープレスマスク）
	mlx_hook(f.win, 2, 1L << 0, &key_event, &f);
	// マウス対応（イベント 4:ボタン押下   マスク 1L<<2:ボタンプレスマスク）
	mlx_hook(f.win, 4, 1L << 2, &mouse_zoom, &f);
	// ×ボタンで閉じる（イベント 17:破棄通知   マスク 0L:イベントマスクなし）
	mlx_hook(f.win, 17, 0L, &close_win, &f);
	// ループ
	mlx_loop(f.mlx);
	return (0);
}
