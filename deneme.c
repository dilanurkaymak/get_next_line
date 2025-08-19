/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:17:31 by dkaymak           #+#    #+#             */
/*   Updated: 2025/08/19 02:24:14 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char    *get_next_line(int fd)
{
    static char *buffer; 
    char    *temp;
    char    *line;
    ssize_t reading;
    int i;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    if(!buffer)
        return(NULL);
    line = malloc(BUFFER_SIZE + 1);
    buffer = malloc(BUFFER_SIZE + 1);
    reading = read(fd,buffer,BUFFER_SIZE);
    if(reading == -1)
    {
        free(buffer);
        return(NULL);
        
    }
    if(reading == 0)
    {
        free(buffer);
        return(NULL);
    }
    buffer[reading] = '\0';
    i=0;
    while (buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    line[++i] = '\0';
    return(line);
    
    
    
    
}