/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:36:51 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/06/09 14:48:13 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include "math.h"
# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

typedef struct			s_fractol
{
	char				*name;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img_adr;
	cl_int				*arr;
	cl_int				cl_x;
	cl_int				cl_y;
	cl_int				iter;
	cl_double			opt_x;
	cl_double			opt_y;
	cl_double			cl_sx;
	cl_double			cl_sy;
	cl_long				cl_z;
	int					w_x;
	int					w_y;
	size_t				xyb;
	int					l_x;
	int					l_y;
	int					pyx;
	int					bpp;
	int					stride;
	int					endian;
	int					way;
	int					ret;
	int					fd;
	int					j;
	int					col_mod;
	double				temp;
	char				*file;
	char				*temp1;
	char				*temp2;
	size_t				count_a;
	size_t				jj;
	int					touch_1;
	int					touch_2;
	int					c_c;
	int					c_b;
	long double			x;
	long double			y;
	long double			z;
	unsigned int		color_st;
	unsigned int		color_end;
	int					col_rst;
	int					col_bst;
	int					col_gst;
	int					col_txt;
	int					option_x;
	int					option_y;
	int					i_max;
	cl_program			program;
	cl_kernel			kernel;
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_device_id		device_id;
	cl_uint				ret_num_devices;
	cl_context			context;
	cl_mem				memobj;
	cl_command_queue	command_queue;
}						t_fractol;

void					send_arguments(t_fractol *a);
void					send_arguments2(t_fractol *a);

void					info_window(t_fractol *a);
void					text(t_fractol *a, char *str);

void					init_cl(t_fractol *a);
void					out(t_fractol *a);
int						r_fdf(double x);
void					col_preset(t_fractol *a);
void					col_mod(t_fractol *a);

int						mouse_move_hook(int x, int y, t_fractol *a);
void					mouse_p2(int x, t_fractol *a);
void					mouse_p3(int y, t_fractol *a);

int						key_press(int key, t_fractol *a);
void					key_press1(int key, t_fractol *a);
void					key_press2(int key, t_fractol *a);
int						say_good_buy(t_fractol *a);
int						mouse_click_hook(int k, int x, int y, t_fractol *a);

int						my_way_fract(char *av, t_fractol *a);
void					openlc_init(t_fractol *a);
void					open_window_and_hooks(t_fractol *a);
void					start_params(t_fractol *a);

#endif
