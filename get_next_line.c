/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:09:35 by dkaymak           #+#    #+#             */
/*   Updated: 2025/08/17 17:28:54 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
// int main ()
// {
// int fd;
// fd = open("a.txt", O_RDONLY);

// char a[100];
// int okunan = read(fd,a,100);
// a[okunan] = '\0';

// printf("%s", a);
// }


char *get_next_line(int fd)
{
    static char *depo;
    char        *buffer;
    char        *satir;
    ssize_t         okunan;
    int i;
    
    satir = malloc(BUFFER_SIZE + 1);
    buffer = malloc(BUFFER_SIZE + 1); 
    okunan = read(fd, buffer, BUFFER_SIZE);
    buffer[okunan] = '\0';
    depo = buffer;
    i = 0;
    while (depo[i] != '\n')
    {
        satir[i] = depo[i];
        i++;
    }
    satir[i] = depo[i];
    satir[++i] = '\0';
    free(buffer);
    return (satir);
}

int main ()
{
    int fd;
    char *line;
    fd = open("a.txt", O_RDONLY);
    
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    close(fd);
}
