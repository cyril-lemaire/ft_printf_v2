#include "ft_printf.h"
#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vdprintf(1, format, args);
	va_end(args);

	return (res);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vdprintf(fd, format, args);
	va_end(args);

	return (res);
}

int		ft_vprintf(const char *format, va_list args)
{
	return (ft_vdprintf(1, format, args));
}

int		ft_asprintf(char **dstp, const char *format, ...)
{
	va_list		args;
	int			res;

	va_start(args, format);
	res = ft_vasprintf(dstp, format, args);
	va_end(args);
	return (res);
}
/*
int		ft_snprintf(char *s, size_t size, const char *format, ...)
{
	va_list		args;
	int			res;

	va_start(args, format);
	res = ft_vsnprintf(s, size, format, args);
	va_end(args);
	return (res);
}
*/