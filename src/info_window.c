/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:31:21 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/09 14:24:08 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		text(t_fractol *a, char *str)
{
	mlx_string_put(a->mlx_ptr, a->win_ptr, a->c_b, a->c_c, a->col_txt, str);
}

void		info_window(t_fractol *a)
{
	if (a->col_mod == 3)
		a->col_txt = a->color_end;
	else
		a->col_txt = a->color_st;
	a->c_b = 10;
	a->c_c = 60;
	text(a, "Q/W/E/A/S change color");
	a->c_c += 20;
	text(a, "+/- change iteration");
	a->c_c += 20;
	text(a, "iteration: ");
	a->c_b = 130;
	a->temp1 = ft_itoa(a->iter);
	text(a, a->temp1);
	a->c_c += 20;
	a->c_b = 10;
	text(a, "left-mouse freese julia");
	a->c_c += 20;
	text(a, "right-mouse freese move");
	a->c_c += 20;
	text(a, "scrool - zoom");
	free(a->temp1);
}
