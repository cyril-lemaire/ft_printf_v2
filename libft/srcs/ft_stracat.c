#include "libft.h"
#include <string.h>

char	*ft_stracat(char **dst, const char *src)
{
	const int		dst_len = ft_strlen(*dst);
	const int		src_len = ft_strlen(src);

	if ((*dst = (char*)ft_realloc(dst, dst_len,
						dst_len + src_len + 1)) != NULL)
		ft_memcpy((*dst) + dst_len, src, src_len + 1);
	return (*dst);
}
