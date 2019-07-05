#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

int		test_vdprintf(int fd, char *format, ...)
{
	va_list	va1;
	va_list	va2;

	va_start(va1, format);
	va_copy(va2, va1);
	dprintf(fd, "Testing vdprintf(\"%s\", ...):\nExpected: '", format);
	vdprintf(fd, format, va1);
	dprintf(fd, "'\n  Actual: '");
	fflush(fdopen(fd, "w"));
	ft_vdprintf(fd, format, va2);
	va_end(va1);
	va_end(va2);
}

int		main(int ac, char **av)
{
	test_vdprintf(1, "Hello, world!");
	return (0);
}
