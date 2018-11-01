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
	void	*arg;

	printer->flags.hash = 1;
	printer->flags.plus = 0;
	printer->flags.space = 0;
	arg = va_arg(*printer->args, void*);
	if (arg == NULL)
		return (printer->write(printer, "(nil)", sizeof("(nil)") - 1));
	return (printer->write("0x") +
			ft_write_uimax(printer, (uintmax_t)arg, 0, "0123456789abcdef"));
}
