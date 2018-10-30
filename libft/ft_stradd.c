#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_stradd(const char *s1, const char *s2)
{
	const int		s1_len = ft_strlen(s1);
	const int		s2_len = ft_strlen(s2);
	char			*dst;

	if ((dst = (char*)malloc(s1_len + s2_len + 1)) != NULL)
	{
		ft_memcpy(dst, s1, s1_len);
		ft_memcpy(dst + s1_len, s2, s2_len + 1);
	}
	return (dst);
}
