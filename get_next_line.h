/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:49:34 by dkaymak           #+#    #+#             */
/*   Updated: 2025/08/19 03:07:57 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 13
# endif

char    *get_next_line(int fd);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char *ft_substr(const char *s, unsigned int start, size_t len);
#endif
