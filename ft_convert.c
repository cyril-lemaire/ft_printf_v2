#include "ft_printf.h"
#include "libft/libft.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>	// Debug only

static int	ft_read_flag(const char *format, t_printer *printer)
{
	int		read_size;

	read_size = 0;
	if (format[0] == '-')
		printer->flags.minus = ++read_size;
	else if (format[0] == '+')
		printer->flags.plus = ++read_size;
	else if (format[0] == '#')
		printer->flags.hash = ++read_size;
	else if (format[0] == '0')
		printer->flags.zero = ++read_size;
	else if (format[0] == ' ')
		printer->flags.space = ++read_size;
	return (read_size);
}

static int	ft_read_flags(const char *format, t_printer *printer)
{
	int		read_size;
	int		*flag_ptr;

	read_size = 0;
	while (1)
	{
		if (format[read_size] == '-')
			flag_ptr = &(printer->flags.minus);
		else if (format[read_size] == '+')
			flag_ptr = &(printer->flags.plus);
		else if (format[read_size] == '#')
			flag_ptr = &(printer->flags.hash);
		else if (format[read_size] == '0')
			flag_ptr = &(printer->flags.zero);
		else if (format[read_size] == ' ')
			flag_ptr = &(printer->flags.space);
		else
			break ;
		*flag_ptr = 1;
		++read_size;
	}
	return (read_size);
}

static int	ft_read_width(const char *format, t_printer *printer)
{
	if ((format[0] < '1' || format[0] > '9') && format[0] != '*')
		return (printer->flags.width = 0);
	printer->flags.width = 1;
	if (format[0] == '*')
	{
		printer->width = va_arg(*printer->args, int);
		if (printer->width < 0)
		{
			printer->flags.minus = 1;
			printer->width = -printer->width;
		}
		return (1);
	}
	return (ft_tools_atoi(format, &printer->width));
}

static int		ft_read_prec(const char *format, t_printer *printer)
{
	printer->flags.prec = (format[0] == '.');
	if (!printer->flags.prec)
		return (0);
	if (format[1] == '*')
	{
		printer->prec = va_arg(*printer->args, int);
		if (printer->prec < 0)
			printer->prec = -printer->prec;
		return (1);
	}
	return (1 + ft_tools_atoi(format + 1, &printer->prec));
}

static int	ft_read_size(const char *format, t_printer *printer)
{
	int		read_size;

	read_size = 1;
	printer->size = format[0];
	if ((format[0] == 'l' || format[0] == 'h') && format[0] == format[1])
	{
		++read_size;
		printer->size = ft_toupper(printer->size);
	}
	if (format[0] == 'I')
	{
		if (ft_strnequ(format + 1, "32", 2) || ft_strnequ(format + 1, "64", 2))
		{
			read_size += 2;
			printer->size = (format[1] == '3') ? 'I' - 32 : 'I' - 64;
		}
	}
	else if (ft_strchr("lhIjz", format[0]) == NULL || format[0] == '\0')
		read_size = 0;
	printer->size = (read_size) ? printer->size : '\0';
	return (read_size);
}

int		ft_convert(const char *format, t_printer *printer)
{
	int		read_size;
	int		f_ret;

	ft_bzero(&printer->flags, sizeof(printer->flags));/*
	read_size = 1;
	while ((f_ret = ft_read_flag(format + read_size, printer)) > 0)
		read_size += f_ret;*/
	read_size = 1 + ft_read_flags(format + 1, printer);
#ifdef FT_PRINTF_DEBUG
#endif
	read_size += ft_read_width(format + read_size, printer);
	read_size += ft_read_prec(format + read_size, printer);
	read_size += ft_read_size(format + read_size, printer);
	if ((printer->type = format[read_size]) != '\0')
		++read_size;
#ifdef FT_PRINTF_DEBUG
	printf("\nFlags: %c%c%c%c%c\n",
		   printer->flags.minus ? '-' : ' ',
		   printer->flags.plus ? '+' : ' ',
		   printer->flags.space ? 's' : ' ',
		   printer->flags.zero ? '0' : ' ',
		   printer->flags.hash ? '#' : ' '); fflush(stdout);
	printf("\nWidth: %s (%d)\n", printer->flags.width ? "Yes" : "No",
		   printer->width);fflush(stdout);
	printf("\nPrecision: %s (%d)\n", printer->flags.prec ? "Yes" : "No",
		   printer->prec);fflush(stdout);
	printf("\nSize: %c\n", printer->size);fflush(stdout);
	printf("\nType: %c\n", printer->type);fflush(stdout);
#endif
	if ((f_ret = ft_write_conversion(printer)) > 0)
		printer->written += f_ret;
	else if (f_ret == ECONV)
		
	return ((f_ret >= 0) ? read_size : f_ret);
}