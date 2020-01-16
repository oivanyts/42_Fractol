//
// Created by Oleh IVANYTSKYI on 2020-01-16.
//

#include "complex.h"

void init_complex(t_complex *com_ptr, double real, double imaginable)
{
	com_ptr->re = real;
	com_ptr->im = imaginable;
}
