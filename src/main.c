#include <stdio.h>
#include <pthread.h>
#include  <math.h>
#include <libft.h>
#include "main.h"
#include "mlx.h"


#define MAX_ITER 25
void init_complex(float re, float im, t_complex *foo)
{
	foo->re = re;
	foo->im = im;
}


void init_color(struct s_graphics *old, int x, int y, int iter)
{
	char	rgba[4];
	double t = (double)iter / (double)MAX_ITER;

	int i = x * old->bpp /8 + y * old->size_y;
	rgba[0] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	rgba[1] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	rgba[2] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	rgba[3] = 0;

	old->pic_pixels[i] = rgba[3];
	old->pic_pixels[++i] = rgba[2];
	old->pic_pixels[++i] = rgba[1];
	old->pic_pixels[++i] = rgba[0];
}

int main()
{
	struct s_graphics info;
	printf("Hello, World!\n");
	info.mlx = mlx_init();

	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "Fractol");
	info.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	info.pic_pixels = mlx_get_data_addr(info.img, &info.bpp, &info.size_y, &info.endian);

	t_complex min, max, factor, c, z;
	min.re = -2.0;
	max.re = 2.0;
	min.im = -2.0;
	max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;

	factor.re = (max.re - min.re) / (WIDTH - 1);
	factor.im = (max.im - min.im) / (HEIGHT - 1);

	int y = 0, x, iteration;
	y = 0;
	while (y < HEIGHT)
	{
		c.im = max.im - y * factor.im;
		x = 0;
		while (x < WIDTH)
		{
			c.re = min.re + x * factor.re;
			init_complex(c.re, c.im, &z);
			iteration = 0;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < MAX_ITER)
			{
				init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
						2.0 * z.re * z.im + c.im, &z);
				iteration++;
			}
			init_color(&info,x,y, iteration);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window ( info.mlx, info.win, info.img , 0, 0);
//	mlx_loop_hook(info.mlx, draw_image, &info);
//	mlx_loop_hook(info.mlx, draw_image, &info);
//	mlx_mouse_hook(info.win, deal_mouse, &info);
//	mlx_hook(info.win, 2, 1L << 17, deal_key, &info);
//	mlx_hook(info.win, 17, 1L << 17, exit_x, &info);
	mlx_loop(info.mlx);
	return 0;
}
