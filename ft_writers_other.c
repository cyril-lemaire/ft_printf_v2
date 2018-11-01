#include "ft_printf.h"

int			ft_write_pct(t_printer *printer)
{
	return (printer->write(printer, "%", 1));
}

int			ft_write_B(t_printer *printer)
{
	char	*arg;

	arg = va_arg(*printer->args, char*);
	if (arg == NULL)
		return (printer->write(printer, "(null)", sizeof("(null)") - 1));
	if (printer->flags.width)
		return (printer->write(printer, arg, printer->width));
	return (0);
}

int			ft_write_p(t_printer *printer)
{
	printer->flags.hash = 1;
	printer->size = 'j';
	return (ft_write_x(printer));
}
