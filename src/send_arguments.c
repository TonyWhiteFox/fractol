/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:21:31 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/09 14:27:54 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		send_arguments2(t_fractol *a)
{
	a->cl_sx = a->x;
	a->cl_sy = a->y;
	a->cl_z = (long int)a->z;
	a->iter = a->i_max;
	a->opt_x = a->option_x;
	a->opt_y = a->option_y;
	a->ret = clEnqueueWriteBuffer(a->command_queue, a->memobj, CL_TRUE, 0,
					a->xyb * sizeof(cl_int), a->arr, 0, NULL, NULL);
	a->ret = clSetKernelArg(a->kernel, 0, sizeof(cl_mem), (void *)&a->memobj);
	a->ret = clSetKernelArg(a->kernel, 1, sizeof(cl_int), &a->cl_x);
	a->ret = clSetKernelArg(a->kernel, 2, sizeof(cl_int), &a->cl_y);
	a->ret = clSetKernelArg(a->kernel, 3, sizeof(cl_int), &a->iter);
	a->ret = clSetKernelArg(a->kernel, 4, sizeof(cl_double), &a->opt_x);
	a->ret = clSetKernelArg(a->kernel, 5, sizeof(cl_double), &a->opt_y);
	a->ret = clSetKernelArg(a->kernel, 6, sizeof(cl_double), &a->cl_sx);
	a->ret = clSetKernelArg(a->kernel, 7, sizeof(cl_double), &a->cl_sy);
	a->ret = clSetKernelArg(a->kernel, 8, sizeof(cl_long), &a->cl_z);
}

void		send_arguments(t_fractol *a)
{
	if (a->way != 2)
	{
		a->cl_sx = a->x;
		a->cl_sy = a->y;
		a->cl_z = (long int)a->z;
		a->iter = a->i_max;
		a->ret = clEnqueueWriteBuffer(a->command_queue, a->memobj, CL_TRUE, 0,
					a->xyb * sizeof(cl_int), a->arr, 0, NULL, NULL);
		a->ret = clSetKernelArg(a->kernel, 0, sizeof(cl_mem),
					(void *)&a->memobj);
		a->ret = clSetKernelArg(a->kernel, 1, sizeof(cl_int), &a->cl_x);
		a->ret = clSetKernelArg(a->kernel, 2, sizeof(cl_int), &a->cl_y);
		a->ret = clSetKernelArg(a->kernel, 3, sizeof(cl_int), &a->iter);
		a->ret = clSetKernelArg(a->kernel, 4, sizeof(cl_double), &a->cl_sx);
		a->ret = clSetKernelArg(a->kernel, 5, sizeof(cl_double), &a->cl_sy);
		a->ret = clSetKernelArg(a->kernel, 6, sizeof(cl_long), &a->cl_z);
	}
	else
		send_arguments2(a);
	out(a);
}
