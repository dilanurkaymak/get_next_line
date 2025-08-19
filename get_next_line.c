/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:09:35 by dkaymak           #+#    #+#             */
/*   Updated: 2025/08/19 03:33:03 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>



char *get_next_line(int fd)
{
    ssize_t reading;
    static char *stash;
    char *line;
    char *buffer;
    int i;
    char *temp;
    
    if(!stash)
        stash = ft_strdup("");
    if(!stash)
        return(NULL);
    buffer = malloc(BUFFER_SIZE + 1);

    
    while(!(ft_strchr(stash,'\n')))
    {
        reading = read(fd,buffer,BUFFER_SIZE);
        if(reading == 0)
        {
           break;
        }
        if(reading == -1)
        {
            free(buffer);
            return(NULL);
        }
        
        buffer[reading] = '\0';
        stash = ft_strjoin(stash, buffer);
        if(!stash)
        {
            free(buffer);
            return(NULL);
        }
    }
    //return(stash);
    
    i=0;
    while(stash[i] != '\n' && stash)
    {
        i++;   
    }
    
    
    line = ft_substr(stash,0,i+1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    stash = ft_substr(stash,i+1,ft_strlen(stash)-i+1);
    return(line);
}  
int main()
{
    int fd;
    fd = open("a.txt", O_RDONLY);
    
  
    printf("%s",get_next_line(fd));

}