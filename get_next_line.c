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
        if (read(fd, *buf, 0) == -1))
            return (-1);
    }
    return (0);
}

int	get_next_line(int fd, char **line)
{
    if (ft_error(fd, &buf, line) < -1)
        return (-1);
    read(fd, buf, BUFFER_SIZE)
}

gerer les erreurs de bases
lire une ligne 
retourner l'interger en focntion de ce qui est lu on non