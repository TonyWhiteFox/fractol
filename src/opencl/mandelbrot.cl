__kernel void kerjulia(__global int* arr, const int wx, const int wy,
						const int iter, const double cl_sx, const double cl_sy,
						const long z)
{
	int gid = get_global_id(0);
	if ((gid % wx) < 256 && ((gid / wx) < 256))
		arr[gid] = iter;
	else
	{
		int i = 0;
		long double x = cl_sx + (gid % wx);
		long double y = cl_sy + (gid / wx);
		long double zr = 0;
		long double zi = 0;
		long double cr = x / z;
		long double ci = y / z;
		long double tmp;
		while (i < iter)
		{
			tmp = zr;
			zr = zr * zr - zi * zi + cr;
			zi = 2 * zi * tmp + ci;
			if (zr * zr + zi * zi >= 4)
			{
				arr[gid] = i;
				i = iter + 2;
			}
			i++;
		}
		if (i == iter)
			arr[gid] = i;
	}
}