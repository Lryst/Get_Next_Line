/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:11:35 by lryst             #+#    #+#             */
/*   Updated: 2019/11/25 15:58:28 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	char *s;

	s = (char*)str;
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char		*tab;
	long int	i;
	long int	u;

	i = 0;
	u = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tab = (char*)malloc(sizeof(char) * (ft_strlen((char *)s1) +
				ft_strlen((char *)s2)) + 1);
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[u])
		tab[i++] = s2[u++];
	tab[i] = '\0';
	free((void*)s1);
	s1 = NULL;
	return (tab);
}

static int		ft_strfind(char *str)
{
	int i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static int		ft_intline(char **line, char *str)
{
	char	*tmp;
	int		i;

	if (!ft_strlen(str))
		return (0);
	i = ft_strfind(str);
	if (i != -1)
	{
		tmp = ft_newstring(i);
		ft_memcpy(tmp, str, i);
		tmp[i] = '\0';
		*line = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strdup(str);
		free(str);
		str = ft_strdup(tmp + i + 1);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	*line = ft_strdup(str);
	free(str);
	str = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE + 1];
	int ret;
	static char *tmp;
	

	printf("FDD : %d\n", fd);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	while((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		printf("BUFF : %s\n", buf);
		if (!(tmp = ft_strjoinfree(tmp, buf)))
			return (-1);
        if (ft_strchr(*line, '\n'))
			break;
	}
	return(ft_intline(line, tmp));
}

