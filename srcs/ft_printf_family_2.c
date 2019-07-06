#include "ft_printf.h"
#include "libft.h"
#include "t_vdprinter.h"
#include "t_vasprinter.h"
#include "t_vsnprinter.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>	// Debug only

int				ft_vdprintf(int fd, const char *format, va_list args)
{
	t_vdprinter	*printer;
	va_list		args_cpy;
	int			ret_val;

	va_copy(args_cpy, args);
	if ((printer = ft_vdprinter_new(fd, &args_cpy)) == NULL)
		return (EALLOC);
	ret_val = ft_print(format, &(printer->super));
	va_end(args_cpy);
	printer->del(printer);
	return (ret_val);
}
/*
int				ft_vdprintf(int fd, const char *format, va_list args)
{
	char	*formatted;
	int		ret_val;

	ret_val = ft_vasprintf(&formatted, format, args);
	write(fd, formatted, ft_strlen(formatted));
	free(formatted);
	return (ret_val);
}
*/
int				ft_vasprintf(char **dstp, const char *format, va_list args)
{
	t_vasprinter	*printer;
	va_list			args_cpy;
	int				ret_val;

	va_copy(args_cpy, args);
	if ((printer = ft_vasprinter_new(dstp, &args_cpy)) == NULL)
		return (EALLOC);
	ret_val = ft_print(format, &(printer->super));
	va_end(args_cpy);
	printer->del(printer);
	return (ret_val);
}
/*
int				ft_vsnprintf(char *str, int size, const char *format, va_list args)
{
	t_vsnprinter	*printer;
	va_list			args_cpy;
	int				ret_val;

	va_copy(args_cpy, args);
	if ((printer = ft_vsnprinter_new(str, size, &args_cpy)) == NULL)
		return (EALLOC);
	ret_val = ft_print(format, &(printer->super));
	va_end(args_cpy);
	printer->del(printer);
	return (ret_val);
}
*/
