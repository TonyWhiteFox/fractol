/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:37:09 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/09 14:30:37 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		col_mod(t_fractol *a)
{
	if (((a->color_st & 0xFF0000) - (a->color_end & 0xFF0000)) > 0)
		a->col_rst = -((a->color_st >> 16) - (a->color_end >> 16));
	else
		a->col_rst = (a->color_end >> 16) - (a->color_st >> 16);
	if (((a->color_st & 0xFF00) - (a->color_end & 0xFF00)) > 0)
		a->col_bst = -(((a->color_st >> 8) & 0xFF) -
				((a->color_end >> 8) & 0xFF));
	else
		a->col_bst = (((a->color_end >> 8) & 0xFF) -
				((a->color_st >> 8) & 0xFF));
	if (((a->color_st & 0xFF) - (a->color_end & 0xFF)) > 0)
		a->col_gst = -((a->color_st & 0xFF) - (a->color_end & 0xFF));
	else
		a->col_gst = (a->color_end & 0xFF) - (a->color_st & 0xFF);
}

void		col_preset(t_fractol *a)
{
	if (a->col_mod == 1)
	{
		a->temp = (((double)(a->color_st - a->color_end) / (double)a->iter));
		while (a->jj < a->xyb)
		{
			*(int *)(a->img_adr + a->jj * 4) = (int)(a->temp * (a->iter -
						a->arr[a->jj]));
			a->jj++;
		}
	}
	if (a->col_mod == 3)
	{
		a->temp = (((double)(a->color_st - a->color_end) / (double)a->iter));
		while (a->jj < a->xyb)
		{
			*(int *)(a->img_adr + a->jj * 4) = (int)(a->temp * (a->arr[a->jj]));
			a->jj++;
		}
	}
}

int			r_fdf(double x)
{
	int		a;

	a = (int)x;
	x = x - a;
	if (x > 0)
	{
		if (x > 0.5)
			return (a + 1);
		else
			return (a);
	}
	if (x < -0.5)
		return (a - 1);
	return (a);
}

void		out(t_fractol *a)
{
	a->ret = clEnqueueNDRangeKernel(a->command_queue, a->kernel, 1, NULL,
									&a->xyb, NULL, 0, NULL, NULL);
	a->ret = clEnqueueReadBuffer(a->command_queue, a->memobj, CL_TRUE, 0,
								a->xyb * sizeof(float), a->arr, 0, NULL, NULL);
	a->jj = 0;
	col_preset(a);
	if (a->col_mod == 2)
	{
		col_mod(a);
		while (a->jj < a->xyb)
		{
			*(int *)(a->img_adr + a->jj * 4) = a->color_st +
				((r_fdf(a->col_rst * a->arr[a->jj] / a->iter) << 16) +
				(r_fdf(a->col_gst * a->arr[a->jj] / a->iter) << 8) +
				r_fdf(a->col_bst * a->arr[a->jj] / a->iter));
			a->jj++;
		}
	}
	mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->img_ptr, 0, 0);
	info_window(a);
}
