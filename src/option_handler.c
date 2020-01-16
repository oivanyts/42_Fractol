
#include "option_handler.h"

const char *a[] = {
		"Mandelbrot",
		"Julia",
		"Third"
};

void usage_print()
{
	ft_printf("Usage: fractol [-aDde] [-f | -g] "
	"[-n number] [-b b_arg | -c c_arg] req1 req2 [opt1 [opt2]]");
}

bool option_handle(int num, char *argv[])
{
	int i;
	i = sizeof(a)/ sizeof(*a);
	if (num != 1)
		return (false);
	while (i--)
	{
		if (!ft_strcmp(argv[0], a[i]))
			//initFractFunc
			return(true);
	}
	return (false);
}