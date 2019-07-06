#include "libft.h"
#include "ft_printf.h"
#include <wchar.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

static int	ft_tools_putwc(t_printer *printer, wchar_t wc)
{
	char	s[4];
	int		f_ret;

	if ((f_ret = ft_wctomb(s, wc)) < 1)
		return (EFORMAT);
	return (printer->write(printer, s, f_ret));
}

int			ft_write_c(t_printer *printer)
{
	char				c;

	if (ft_strchr("lwL", printer->size) != NULL && printer->size != '\0')
		return (ft_write_C(printer));
	c = (char)va_arg(*printer->args, int);
	return (printer->write(printer, &c, sizeof(char)));
}

int			ft_write_C(t_printer *printer)
{
	wchar_t				c;

	c = (wchar_t)va_arg(*printer->args, int);
	return (ft_tools_putwc(printer, c));
}
