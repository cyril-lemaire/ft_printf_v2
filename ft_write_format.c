#include "ft_printf.h"
#include "t_printer.h"
#include <stddef.h>
#include <unistd.h>

int							ft_not_implemented(t_printer *printer)
{
	write(2, "Not implemented type '", sizeof("Not implemented type '") - 1);
	write(2, &printer->type, 1);
	write(2, "' !\n", sizeof("' !\n") - 1);
	return (0);
}

static const t_printer_ft*	ft_get_writers(void)
{
	static const t_printer_ft	writers[sizeof(PRINTF_TYPES) - 1] = {
		ft_write_pct,			// %
		ft_write_d,				// d
		ft_write_d,				// i
		ft_write_u,				// u
		ft_write_b,				// b
		ft_write_o,				// o
		ft_write_x,				// x
		ft_write_X,				// X
/*		ft_write_c,				// c
		ft_write_C,				// C
		ft_write_s,				// s
		ft_write_S,				// S
		ft_not_implemented,		// f
		ft_not_implemented,		// g
		ft_not_implemented,		// G
		ft_not_implemented,		// a*/
		ft_not_implemented		// A
	};
	return (writers);
}

int							ft_write_format(t_printer *printer)
{
	const t_printer_ft	*funcs = ft_get_writers();
	int					f_ret;
	int					i;

	i = 0;
	while (PRINTF_TYPES[i] != '\0')
	{
		if (printer->type == PRINTF_TYPES[i])
		{
			printf("calling format for %c\n", PRINTF_TYPES[i]);
			return (((f_ret = funcs[i](printer)) < 0) ? -2 : f_ret);
		}
		++i;
	}
	write(2, "Error! unknown conversion type character ‘",
		sizeof("Error! unknown conversion type character ‘") - 1);
	write(2, &printer->type, 1);
	write(2, "'!\n", sizeof("'!\n") - 1);
	return (EFORMAT);
}
