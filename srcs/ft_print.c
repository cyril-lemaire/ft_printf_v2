#include "ft_printf.h"
#include "libft.h"

int		ft_print(const char *format, t_printer *printer)
{
	char	*next_format;
	int		f_ret;

	if (format == NULL)
		return (EFORMAT);
	while ((next_format = ft_strchr(format, '%')) != NULL)
	{
		if ((f_ret = printer->write(printer, format, next_format - format)) < 0)
			return (f_ret);
		printer->written += f_ret;
		format = next_format;
		if ((f_ret = ft_format(format, printer)) < 0)
			return (f_ret);
		format += f_ret;
	}
	if ((f_ret = printer->write(printer, format, ft_strlen(format))) < 0)
		return (f_ret);
	printer->written += f_ret;
	if ((f_ret = printer->flush(printer)) < 0)
		return (f_ret);
	return (printer->written);
}