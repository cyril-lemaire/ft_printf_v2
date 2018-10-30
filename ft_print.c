#include "ft_printf.h"
#include "libft/libft.h"

int		ft_print(t_printer *printer)
{
	char	*next_format;
	int		f_ret;

	if (format == NULL)
		return (EFORMAT);
	while ((next_format = ft_strchr(format, '%')) != NULL)
	{
		if ((f_ret = printer->write(printer, format, next_format - format)) < 0)
		{
			printf("\nFormat failed! (string between formats: %s), returned %d\n", format, f_ret);fflush(stdout);
			return (f_ret);
		}
		printer->written += f_ret;
		format = next_format;
		if ((f_ret = ft_format(format, printer)) < 0)
		{
			printf("\nFormat failed! {%c%c}\n", printer->size,
				   printer->type);fflush(stdout);
			return (f_ret);
		}
		printf("\nFormat was %d long\n", f_ret);fflush(stdout);
		format += f_ret;
	}
	if ((f_ret = printer->write(printer, format, ft_strlen(format))) < 0)
	{
		printf("\nFormat failed! (string after formats: \"%s\"), returned %d\n", format, f_ret);fflush(stdout);
		return (f_ret);
	}
	printer->written += f_ret;
	if ((f_ret = printer->flush(printer)) < 0)
	{
		write(2, "\nFlush failed!\n", sizeof("\nFlush failed!\n") - 1);
		return (f_ret);
	}
	return (printer->written);
}