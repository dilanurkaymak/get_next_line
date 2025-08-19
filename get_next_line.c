/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:09:35 by dkaymak           #+#    #+#             */
/*   Updated: 2025/08/19 12:08:36 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

static char	*join_and_free(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	reading;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	reading = 1;
	while (reading > 0 && !ft_strchr(stash, '\n'))
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading == -1)
			return (free(buffer), NULL);
		buffer[reading] = '\0';
		stash = join_and_free(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	int		i;

	if (!*stash || **stash == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = ft_substr(*stash, 0, i);
	new_stash = ft_substr(*stash, i, ft_strlen(*stash) - i);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, 1);
	if (!stash)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	return (extract_line(&stash));
}
