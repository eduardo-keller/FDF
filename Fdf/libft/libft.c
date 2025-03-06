#include <stdio.h>

int	ft_atoi(char *ptr)
{
	int	out;
	int	sign;

	sign = 1;
	out = 0;
	while((*ptr >= 9 && *ptr <= 13) || *ptr == 32)
		ptr++;
	if(*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	else if(*ptr == '+')
		ptr++;
	while(*ptr >= '0' && *ptr <= '9')
	{
		out = (out * 10) + (*ptr - '0');
		ptr++;
	}
	return(out * sign);	
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocd_mem;

	allocd_mem = (void *) malloc (nmemb * size);
	if (allocd_mem == NULL)
		return (NULL);
	ft_bzero(allocd_mem, nmemb * size);
	return (allocd_mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	length_s;
	size_t	i;

	length_s = ft_strlen(s);
	if (start >= length_s)
		return (ft_strdup(""));
	if (length_s - start < len)
		len = length_s - start;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = -1;
	while (s[++i + start] && (i < len))
		substring[i] = s[start + i];
	substring[len] = '\0';
	return (substring);
}