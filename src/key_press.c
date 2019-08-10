/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:51:08 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/09 14:25:31 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_click_hook(int k, int x, int y, t_fractol *a)
{
	if (k == 1)
		a->touch_1++;
	if (k == 2)
		a->touch_2++;
	if (k == 4 && (((a->way == 8 || a->way < 4) && a->z < 25883354416738875)
			|| a->z < 2322146744))
	{
		a->x += x / 6;
		a->y += y / 6;
		a->z = a->z * 1.2;
		a->y = a->y * 1.2;
		a->x = a->x * 1.2;
	}
	if (k == 5 && a->z > 100)
	{
		a->x -= x / 6;
		a->y -= y / 6;
		a->z = a->z / 1.2;
		a->y = a->y / 1.2;
		a->x = a->x / 1.2;
	}
	send_arguments(a);
	return (0);
}

int		say_good_buy(t_fractol *a)
{
	free(a);
	exit(0);
	return (0);
}

void	key_press2(int key, t_fractol *a)
{
	if (key == 12)
	{
		a->col_mod = 2;
		a->color_end = 0xFFFFFF;
		a->color_st = 0x220000;
		a->i_max = 255;
	}
	if (key == 13)
	{
		a->col_mod = 2;
		a->color_end = 0xFFFFFF;
		a->color_st = 0x880000;
		a->i_max = 255;
	}
	if (key == 14)
	{
		a->col_mod = 2;
		a->color_end = 0xFFFFFF;
		a->color_st = 0x22;
		a->i_max = 255;
	}
}

void	key_press1(int key, t_fractol *a)
{
	if (key == 0)
	{
		a->col_mod = 1;
		a->color_end = 0x0;
		a->color_st = 0xFFFFFF;
		a->i_max = 1000;
	}
	if (key == 1)
	{
		a->col_mod = 3;
		a->color_end = 0x0;
		a->color_st = 0xFFFFFF;
		a->i_max = 1000;
	}
	if (key == 24 || key == 69)
	{
		a->i_max += 50;
	}
}

int		key_press(int key, t_fractol *a)
{
	if (key == 53)
		say_good_buy(a);
	if (key == 126)
		a->y += 50;
	if (key == 125)
		a->y -= 50;
	if (key == 123)
		a->x += 50;
	if (key == 124)
		a->x -= 50;
	key_press1(key, a);
	key_press2(key, a);
	if ((key == 27 || key == 78) && a->i_max > 50)
	{
		a->i_max -= 50;
	}
	send_arguments(a);
	return (0);
}
