/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:05:25 by lryst             #+#    #+#             */
/*   Updated: 2019/11/25 15:57:26 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
int		ft_strspn(char *set, char u);
char	*ft_strjoinfree(char *s1, char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char    *ft_newstring(size_t i);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif