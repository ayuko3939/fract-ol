/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:44:13 by yohasega          #+#    #+#             */
/*   Updated: 2025/04/19 14:53:29 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 0:NG  1:Mandelbrot  2:Julia
static int	get_kind_of_fractal(char *str)
{
	if (ft_strncmp(str, "Mandelbrot", 11) == 0 || ft_strncmp(str, "M", 2) == 0)
		return (1);
	if (ft_strncmp(str, "Julia", 6) == 0 || ft_strncmp(str, "J", 2) == 0)
		return (2);
	return (0);
}

static int	is_number(char *str)
{
	// スペース ( 9:\t  10:\n  11:\v  12:\f  13:\r  32:' ' )
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	// 符号
	if (*str == '-' || *str == '+')
		str++;
	// このタイミングで数字でなければアウト
	if (!ft_isdigit(*str))
		return (0);
	// 数字
	while (ft_isdigit(*str))
		str++;
	// 小数点と数字
	if (*str == '.')
	{
		str++;
		// 小数点の隣が数字でなければアウト
		if (!ft_isdigit(*str))
			return (0);
		while (ft_isdigit(*str))
			str++;
	}
	// 最後まで到達していればOK、してなければアウト
	if (!*str)
		return (1);
	return (0);
}

static int	is_julia_prm(int ac, char **av, t_fractol *f)
{
	// fractol Julia の場合
	if (ac == 2)
		return (0);
	// fractol Julia 0.35 0.01 の場合、数字か確認
	if (!is_number(av[2]))
		return (0);
	if (!is_number(av[3]))
		return (0);
	// パラメータを取得して範囲チェック
	f->arg_r = ft_atof(av[2]);
	f->arg_i = ft_atof(av[3]);
	if (f->arg_r < -2.0 || f->arg_r > 2.0)
		return (0);
	if (f->arg_i <= -2.0 || f->arg_i >= 2.0)
		return (0);
	return (1);
}

// f->kind ( 0:NG  1:Mandelbrot  2:Julia )
int	validate(int ac, char **av, t_fractol *f)
{
	// 引数が明らかにおかしい場合はエラー処理
	if (ac < 2 || ac > 4 || ac == 3)
		return (msg_error());
	// フラクタルの種類を取得（おかしければ(0)エラー処理）
	f->kind = get_kind_of_fractal(av[1]);
	if (f->kind == 0)
		return (msg_error());
	// Mandelbrotかつ引数が2か確認
	if (f->kind == 1 && ac != 2)
		return (msg_error());
	// Juliaかつパラメーター確認
	if (f->kind == 2 && !is_julia_prm(ac, av, f))
		return (msg_julia_prm());
	return (1);
}
