/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:54:47 by ekeller-          #+#    #+#             */
/*   Updated: 2025/03/06 18:41:26 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
int	    ft_atoi(char *ptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif