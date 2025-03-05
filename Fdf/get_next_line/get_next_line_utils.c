/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:41:24 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/05 17:48:56 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*ft_gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s[i]);
	return (NULL);
}

void	*ft_gnl_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	total_mem;
	size_t	i;
	size_t	max_size;

	i = 0;
	max_size = ~(size_t)0;
	total_mem = nmemb * size;
	if (size != 0 && nmemb > max_size / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < total_mem)
		str[i++] = '\0';
	return (str);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	new_string = malloc(i + j + 1);
	if (!new_string)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		new_string[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_string[j++] = s2[i++];
	new_string[j] = '\0';
	return (new_string);
}

int	ft_gnl_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
