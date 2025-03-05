/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:08:36 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/05 17:50:29 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
void	*ft_gnl_calloc(size_t nmemb, size_t size);
char	*ft_gnl_strchr(char *s, int c);
int		ft_gnl_strlen(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);

#endif