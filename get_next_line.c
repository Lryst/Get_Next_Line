/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:11:35 by lryst             #+#    #+#             */
/*   Updated: 2019/11/25 17:25:42 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strspn(char *set, char u)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == u)
			return (1);
		i++;
	}
	return (0);
}


char	*ft_strjoinfree(char *s1, char *s2)
{
	char		*tab;
	int	i;
	int	u;

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
	free(s1);
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

static int		ft_intline(char **line, char *tmp)
{
	char	*str;
	int		i;

	if (!ft_strlen(tmp))
		return (0);
	i = ft_strfind(tmp);
	if (i != -1)
	{
		str = ft_newstring(i);
		ft_memcpy(str, tmp, i);
		str[i] = '\0';
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		str = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		printf("tmp1 : %s\n", tmp);
		tmp = ft_strdup(str + i + 1);
		free(str);
		printf("tmp2 : %s\n", tmp);
		str = NULL;
		return (1);
	}
	*line = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int ret;
	static char *tmp;
	
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	*line = NULL;
	printf("tmp4 : %s\n", tmp);
	tmp = ft_newstring(0);
	while((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		printf("buf :%s\n", buf);
		printf("tmp avant strjoinfree : %s\n", tmp);
		if (!(tmp = ft_strjoinfree(tmp, buf)))
			return (-1);
		printf("tmp apres strjoinfree : %s\n", tmp);
        if (ft_strspn(tmp, '\n'))
			break;
	}
	return(ft_intline(line, tmp));
}
