#include <stddef.h>

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