/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:11:35 by lryst             #+#    #+#             */
/*   Updated: 2019/11/18 14:06:04 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_error(fd, **buf, **line)
{
    if (fd == -1 || line == NULL)
        return (-1);
    if (!*buf)
    {
        if (!(char*)malloc(sizeof(char*) BUFFER_SIZE + 1))
        {
            free(buf);
            return (-1);
        }
    }
    return (0);
}

int	get_next_line(int fd, char **line)
{
    static char buf{BUFFER_SIZE};


    if (ft_error(fd, &buf, line) < -1)
        return (-1);
    


	read(fd, buf, BUFFER_SIZE)
}

int main()
{
    fd = open("bonjour", O_RDONLY);
    ft_putnbr(fd);
    close(fd);
    return (0);
}