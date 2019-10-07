#include <stddef.h>
#include "../ft_printf.h"
#include <stdio.h>

/*
int		putwc_repr(void *wc_repr)	// Debug only
{
	wchar_t	wc;

	wc = *(wchar_t*)wc_repr;
	return (ft_printf("%032b", wc));
}
*/
int		ft_wctomb(char *s, wchar_t wchar)
{
	int					i;
	wchar_t				lim;
	int					s_len;
	unsigned char		byte_head;

	if (s == NULL || wchar > 0xFFFF || wchar < 0)
		return (-1);
	s_len = 1;
	lim = 1 << 2;
	while(wchar > (lim = lim << 5))
		++s_len;
	if (s_len > 1)
	{
		i = 0;
		while (i < s_len)
		{
			byte_head = (i == 0) ? 0xF00 >> s_len : 0x80;
			s[i] = byte_head | (wchar >> (6 * (s_len - 1 - i)) & 0x3F);
			++i;
		}
	}
	else
		s[0] = (char)(unsigned char)wchar;
	return (s_len);
}

/*
int		ft_wctomb(char *s, wchar_t wchar)
{
	const wchar_t		limits[5] = {0x110000, 0x100000, 0x800, 0x80, 1};
	const int			masks[4] = {0xF0, 0xE0, 0xC0, 0};
	int					i;
	int					s_len;

	if (wchar >= limits[0])
		return (-1);
	s_len = 0;
	i = 0;
	while (i < 4)
	{
		if (wchar >= limits[i + 1])
			s[s_len++] = (wchar < limits[i] ? masks[i] : 0x80)
					| ((wchar % limits[i]) / limits[i + 1]);
		++i;
	}
	return (s_len);
}
*/
