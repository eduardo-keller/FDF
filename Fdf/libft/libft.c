/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:46:49 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/19 17:22:29 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	ft_atoi(char *ptr)
{
	int	out;
	int	sign;

	sign = 1;
	out = 0;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == 32)
		ptr++;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		out = (out * 10) + (*ptr - '0');
		ptr++;
	}
	return (out * sign);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	len_s;

	len_s = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[len_s])
		len_s++;
	if (start >= len_s)
		return (ft_calloc(1, sizeof(char)));
	if (len > len_s - start)
		len = len_s - start;
	sub_s = malloc(len + 1);
	if (!sub_s)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
