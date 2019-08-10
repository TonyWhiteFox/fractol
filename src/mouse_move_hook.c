/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 13:49:23 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/09 14:24:39 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_p3(int y, t_fractol *a)
{
	while (a->l_y != y)
	{
		if (a->l_y < y)
		{
			a->l_y++;
			a->y--;
		}
		else
		{
			a->l_y--;
			a->y++;
		}
	}
}

void	mouse_p2(int x, t_fractol *a)
{
	while (a->l_x != x)
	{
		if (a->l_x < x)
		{
			a->l_x++;
			a->x--;
		}
		else
		{
			a->l_x--;
			a->x++;
		}
	}
}

int		mouse_move_hook(int x, int y, t_fractol *a)
{
	if (!(x < 0 || x >= a->w_x || y < 0 || y >= a->w_y || a->touch_1 % 2
				|| a->way != 2))
	{
		a->touch_2 = 0;
		a->option_x = x * 2;
		a->option_y = y * 2;
	}
	else if (!(x < 0 || x >= a->w_x || y < 0 || y >= a->w_y ||
				!(a->touch_2 % 2)))
	{
		mouse_p2(x, a);
		mouse_p3(y, a);
	}
	else
	{
		a->l_x = x;
		a->l_y = y;
		return (0);
	}
	send_arguments(a);
	a->l_x = x;
	a->l_y = y;
	return (0);
}
