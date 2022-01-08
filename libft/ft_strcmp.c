#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (!(*s1) && !(*s2))
		return (0);
	else
		while (*us1 || *us2)
		{
			if (*us1 != *us2)
				return (*us1 - *us2);
			us1++;
			us2++;
		}
	return (0);
}
