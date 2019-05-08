#include <stddef.h>

int		ft_wctomb(char *s, wchar_t wchar)
{
	/*
	const wchar_t		limits[5] = {0x110000, 0x100000, 0x800, 0x80, 1};
	const int			masks[4] = {0xF0, 0xE0, 0xC0, 0};
	*/
	int					i;
	wchar_t				lim;
	int					s_len;

	if (s == NULL || wchar > 0xFFFF)
		return (-1);
	s_len = 1;
	lim = 1 << 2;
	while(wchar > (lim = lim << 5))
		++s_len;
	if (s_len == 1)
		s[0] = (char)wchar;
	else
		s[0] = (char)((0xF << (4 - s_len) ) & (wchar >> (1 << (6 * s_len))));
	i = 1;
	while (i < s_len)
	{
		s[i] = (char)(0x80 & (wchar >> (1 << (6 * (s_len - i)))));
		++i;
	}
	/*
	if (wchar < 0x80)
	{
		s[0] = (char)wchar;
		s_len = 1;
	}
	else if (wchar < 0x800)
	{
		s[0] = (char)((0xF << (4 - s_len) ) & (wchar >> (1 << (6 x s_len))));
		s_len = 2;
	}
	else if (wchar < 0x10000)
	{
		s[0] = (char)(0xE0 & (wchar >> (1 << (6 x 2))));
		s_len = 3;
	}
	else if (wchar < 0x110000)
	{
		s[0] = (char)(0xF0 & (wchar >> (1 << (6 x 3))));
		s_len = 4;
	}
	*/
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