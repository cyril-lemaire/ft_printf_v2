#include "ft_printf.h"
#include "libft.h"
#include "t_printer.h"
#include "t_vdprinter.h"
#include "t_vasprinter.h"
#include "t_vsnprinter.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

int		test_print(const char *format, ...)
{
	va_list		args;
	va_list		args2;
	va_list		args3;
	int			res;
	int			i;
	t_vdprinter *vdprinter;
	char 		*str;

	printf("Testing print(\"%s\"):\n", format);fflush(stdout);
	va_start(args, format);
	va_copy(args2, args);
	va_copy(args3, args);

	printf("Exp:\t|"); fflush(stdout);
	res = vdprintf(1, format, args);
	printf("| => %d\n", res);
	printf("You:\t|"); fflush(stdout);
	res = ft_vdprintf(1, format, args2);
	printf("| => %d\n\n", res); fflush(stdout);
	va_end(args);
	va_end(args2);
	va_end(args3);
	return (res);
}

int		putwc_repr(void *wc_repr, int wc_len)
{
	char	*wc;
	int		i;

	wc = (char*)wc_repr;
	for (i = 0; i < wc_len; ++i)
		printf("%X", wc[i]); fflush(stdout);
	return (1);
}

int		test_wctomb(wchar_t wc)
{
	char		cs[MB_CUR_MAX];
	char		c2s[MB_CUR_MAX];
	int			len;

	cs[MB_CUR_MAX - 1] = c2s[MB_CUR_MAX - 1] = -1;
	printf("Testing wctomb('%C'):\n", wc);fflush(stdout);
	printf("\nExp:\t|"); fflush(stdout);
	bzero(cs, MB_CUR_MAX);
	bzero(c2s, MB_CUR_MAX);
	len = wctomb(cs, wc);
	if (len > 0)
	{
		printf("%.*s\thex: %X", len, cs, *(wchar_t*)cs);
		fflush(stdout);
	}
	printf("| => %d\n", len);
	printf("\nYou:\t|"); fflush(stdout);
	len = ft_wctomb(c2s, wc);
	if (len > 0)
	{
		printf("%.*s\thex: %X", len, c2s, *(wchar_t*)c2s);
		fflush(stdout);
	}
	printf("| => %d\n\n", len); fflush(stdout);
	return (len);
}

/*
%-5.3s LYDI == |LYD  |
% 4.5i 42 == | 00042|
%04.5i 42 == |00042|
%04.3i 42 == | 042|
%04.2i 42 == |  42|
*/
int		main(int argc, char **argv)
{
	int			i;
	unsigned	u;
	char		s[BUFF_SIZE];
	wchar_t		wcs[BUFF_SIZE];
	wchar_t		c;
	wchar_t		c2;
	setlocale(LC_ALL, "en_GB.UTF-8");
	printf("locale: %s\n", setlocale(LC_ALL, NULL));

//	printf("Sizes: char %zd\tint %zd\twchar_t %zd\tlong long %zd\n", sizeof(char), sizeof(int), sizeof(wchar_t), sizeof(long long));

	printf("\n");
	for (i = 0; i < 10; ++i)
	{
		u = (unsigned)(unsigned char)(0xF00 >> i);
		ft_printf("%u\t%08b\n", u, u);
	}
	fflush(stdout);
	test_wctomb(L'L');
	test_wctomb(L'\x20AC');	// €
	test_wctomb(L'\x00C6');	// Æ
	test_wctomb(L'\x0270');	// ɰ
	test_wctomb(L'\x0460');	// Ѡ
	test_wctomb(L'\x18B0');	// ᢰ
	test_wctomb(L'\xFFE5');	// ￥
	test_print("Hello, World!");
	test_print("number: '%d'!", 3);
	test_print("char: '%c'!", 'c');
	test_print("overflow char: '%c'!", 'c' + 256);
	test_print("overflow char: '%d'!", (char)('c' + 256));
	test_print("string: '%s'", "Hello, World!");
	test_print("strings: '%s', '%s'", "Hello", "World!");
	test_print("size 4: '%4s'", "precision");
	test_print("size 15: '%15s'", "precision");
	test_print("precision 4: '%.4s'", "precision");
	test_print("precision 15: '%.15s'", "precision");
	test_print("unsigned: '%u', '%lu', '%u'", 3, 15, -1);
	test_print("pointer: '%p'", &c);
	test_print("wchar: '%C'", L'L');
	test_print("wchar: '%lc'", L'L');
	test_print("wchar string: '%S'", L"Large string");
	test_print("wchar string: '%ls'", L"Large string");
	test_print("%4i", 42);
	test_print("%.5i", 42);
	test_print("%04i", 42);
	test_print("%0.5i", 42);
	test_print("%+i", 42);
	test_print("%+.5i", 42);
	test_print("%+4i", 42);
	test_print("%-i", 42);
	test_print("%-.5i", 42);
	test_print("%-4i", 42);
	test_print("% 4.5i", 42);
	test_print("%04.5i", 42);
	test_print("%4.3i", 42);
	test_print("%04.3i", 42);
	test_print("%04.2i", 42);
	test_print("% Zoooo");
	test_print("{%S}", NULL);
	test_print("%-5.3s", "LYDI");
	test_print("%-5.3s", "LYDI");
/*
	i = 10;
	c = L'L';
	test_print("%");
	test_print("% Zooo");

	test_print("% %");
	test_print("%*d", 5, 42);
	test_print("%p", &i);
	test_print("%C", c);
	test_print(NULL);
*/
	return (0);
}
