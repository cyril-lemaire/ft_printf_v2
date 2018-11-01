#include "libft/libft.h"
#include "ft_printf.h"
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>

static int	ft_tools_printwc(t_printer *printer, wchar_t wc)
{
	char				s[MB_CUR_MAX + 1];
	int					f_ret;

	bzero(s, MB_CUR_MAX);
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
	return (ft_tools_printwc(printer, c));
}

int			ft_write_s(t_printer *printer)
{
	char				*arg;

	if (ft_strchr("lwL", printer->size) != NULL && printer->size != '\0')
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
		ft_tools_printwc(printer, arg[i++]);
	return (i);
}