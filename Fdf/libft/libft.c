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
