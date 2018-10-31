#include "libft/libft.h"
#include "ft_printf.h"
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
/*
int			ft_write_c(t_printer *printer)
{
	char				c;

	if (ft_strchr("lwL", printer->size) != NULL)
		return (ft_write_C(printer));
	c = (char)va_arg(*printer->args, int);
	return (printer->write(printer, &c, sizeof(char)));
}

int			ft_write_C(t_printer *printer)
{
	return (ft_putwc(printer, va_arg(*printer->args, wchar_t)));
}

int			ft_write_s(t_printer *printer)
{
	char				*arg;

	if (ft_strchr("lwL", printer->size))
		return (ft_write_S(printer));
	arg = va_arg(*printer->args, char*);
	if (arg == NULL)
		return (printer->write(printer, "(null)", sizeof("(null)") - 1));
	return (printer->write(printer, arg, ft_strlen(arg)));
}

int			ft_write_S(t_printer *printer)
{
	wchar_t				*arg;
	size_t				i;

	arg = va_arg(*printer->args, wchar_t*);
	if (arg == NULL)
		return (printer->write(printer, "(null)", sizeof("(null)") - 1));
	i = 0;
	while (arg[i] != L'\0')
		ft_putwc(printer, arg[i++]);
	return (i);
}
*/
int			ft_write_pct(t_printer *printer)
{
	return (printer->write(printer, "%", 1));
}
