/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:02:51 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/28 23:09:37 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			start_params(t_fractol *a)
{
	a->x = -(a->w_x / 2);
	a->y = -(a->w_y / 2);
	a->col_mod = 1;
	a->cl_x = a->w_x;
	a->cl_y = a->w_y;
	a->z = 300;
	a->option_x = a->w_x / 2;
	a->option_y = a->w_y / 2;
	a->color_end = 0x00;
	a->color_st = 0xFFFFFF;
	a->i_max = 1000;
	a->touch_1 = 0;
	a->touch_2 = 0;
}

void			open_window_and_hooks(t_fractol *a)
{
	start_params(a);
	a->mlx_ptr = mlx_init();
	a->win_ptr = mlx_new_window(a->mlx_ptr, a->w_x, a->w_y, a->name);
	a->img_ptr = mlx_new_image(a->mlx_ptr, a->w_x, a->w_y);
	a->img_adr = mlx_get_data_addr(a->img_ptr, &a->bpp,
					&a->stride, &a->endian);
	a->bpp /= 8;
	mlx_hook(a->win_ptr, 2, 2, key_press, a);
	mlx_hook(a->win_ptr, 17, 17, say_good_buy, a);
	mlx_hook(a->win_ptr, 4, 4, mouse_click_hook, a);
	mlx_hook(a->win_ptr, 6, 6, mouse_move_hook, a);
	send_arguments(a);
	mlx_loop(a->mlx_ptr);
}

void			openlc_init(t_fractol *a)
{
	a->w_x = 2560;
	a->w_y = 1280;
	a->ret = clGetPlatformIDs(1, &a->platform_id, &a->ret_num_platforms);
	a->ret = clGetDeviceIDs(a->platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
				&a->device_id, &a->ret_num_devices);
	a->context = clCreateContext(NULL, 1, &a->device_id, NULL, NULL, &a->ret);
	a->command_queue = clCreateCommandQueue(a->context,
				a->device_id, 0, &a->ret);
	init_cl(a);
	a->count_a = ft_strlen(a->file);
	a->program = clCreateProgramWithSource(a->context, 1,
			(const char **)&a->file, (const size_t *)&a->count_a, &a->ret);
	a->ret = clBuildProgram(a->program, 1, &a->device_id, NULL, NULL, NULL);
	a->kernel = clCreateKernel(a->program, "kerjulia", &a->ret);
	a->xyb = a->w_x * a->w_y;
	a->arr = (cl_int *)malloc(sizeof(cl_int) * a->xyb);
	a->memobj = clCreateBuffer(a->context, CL_MEM_READ_WRITE, a->xyb *
				sizeof(cl_int), NULL, &a->ret);
}

int				my_way_fract(char *av, t_fractol *a)
{
	if (!av)
		a->way = 0;
	else if (!(ft_strcmp("mandelbrot", av)))
		a->way = 1;
	else if (!(ft_strcmp("julia", av)))
		a->way = 2;
	else if (!(ft_strcmp("burningship", av)))
		a->way = 3;
	else if (!(ft_strcmp("tricorn", av)))
		a->way = 4;
	else if (!(ft_strcmp("fract1", av)))
		a->way = 5;
	else if (!(ft_strcmp("fract2", av)))
		a->way = 6;
	else if (!(ft_strcmp("fract3", av)))
		a->way = 7;
	else if (!(ft_strcmp("fract4", av)))
		a->way = 8;
	else
		return (1);
	return (0);
}

int				main(int ac, char **av)
{
	t_fractol	*a;

	if (!(a = (t_fractol *)malloc(sizeof(t_fractol))))
		return (ft_printf("Memory not worcking!!!\n"));
	if (ac != 2 || my_way_fract(av[1], a))
	{
		ft_printf("Usage: %s \"mandelbrot\", \"julia\",%s,%s",
			av[0], " \"burningship\", \"tricorn\"",
			" \"fract1\", \"fract2\", \"fract3\", \"fract4\".\n");
		exit(0);
	}
	a->name = av[1];
	openlc_init(a);
	open_window_and_hooks(a);
	return (0);
}
