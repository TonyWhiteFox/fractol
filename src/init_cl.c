/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:17:24 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/09 14:24:18 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_cl(t_fractol *a)
{
	if (a->way == 1)
		a->fd = open("src/opencl/mandelbrot.cl", O_RDONLY);
	if (a->way == 2)
		a->fd = open("src/opencl/julia.cl", O_RDONLY);
	if (a->way == 3)
		a->fd = open("src/opencl/burningship.cl", O_RDONLY);
	if (a->way == 4)
		a->fd = open("src/opencl/tricorn.cl", O_RDONLY);
	if (a->way == 5)
		a->fd = open("src/opencl/mandelbrot.1.cl", O_RDONLY);
	if (a->way == 6)
		a->fd = open("src/opencl/mandelbrot.2.cl", O_RDONLY);
	if (a->way == 7)
		a->fd = open("src/opencl/mandelbrot.3.cl", O_RDONLY);
	if (a->way == 8)
		a->fd = open("src/opencl/julia.1.cl", O_RDONLY);
	a->file = ft_strnew(1);
	while ((a->j = get_next_line(a->fd, &a->temp1)))
	{
		a->temp2 = a->file;
		a->file = ft_strjoin(a->file, a->temp1);
		free(a->temp1);
		free(a->temp2);
	}
	close(a->fd);
}
