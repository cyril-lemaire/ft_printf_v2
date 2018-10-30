#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "t_printer.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# define PRINTF_TYPES "%diuboxXcCsSpfgGaA{"
# define EALLOC -1
# define EWRITE -2
# define EFORMAT -3
#include <stdlib.h>	// debug only
#include <stdio.h>	// debug only
#include <unistd.h>	// debug only

int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_vprintf(const char *format, va_list args);
int			ft_vdprintf(int fd, const char *format, va_list args);
int			ft_print(const char *format, t_printer *printer);
int			ft_format(const char *format, t_printer *printer);
int			ft_write_format(t_printer *printer);
intmax_t	ft_imaxabs(intmax_t n);
int			ft_tools_atoi(const char *str, int *ans);
int			ft_write_uimax(t_printer *printer, uintmax_t n, int is_neg,
				const char *base_repr);
int			ft_write_signed(t_printer *printer, const char *base);
int			ft_write_unsigned(t_printer *printer, const char *base);
int			ft_write_pct(void *raw_printer);
int			ft_write_c(void *raw_printer);
int			ft_write_C(void *raw_printer);
int			ft_write_s(void *raw_printer);
int			ft_write_S(void *raw_printer);
int			ft_write_d(void *raw_printer);
int			ft_write_u(void *raw_printer);
int			ft_write_b(void *raw_printer);
int			ft_write_o(void *raw_printer);
int			ft_write_x(void *raw_printer);
int			ft_write_X(void *raw_printer);
int			ft_write_p(void *raw_printer);

#endif
