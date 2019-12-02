/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:11:35 by lryst             #+#    #+#             */
/*   Updated: 2019/12/02 16:34:30 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char ***str)
{
	free(**str);
	**str = NULL;
}

int		ft_strspn(char *set, char u)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == u)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		u;

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

int		ft_intline(char **line, char **tmp)
{
	char	*str;
	int		i;

	if (!ft_strlen(*tmp))
	{
		*line = ft_newstring(0);
		ft_free(&tmp);
		return (0);
	}
	i = ft_strspn(*tmp, '\n');
	if (i != -1)
	{
		*line = ft_newstring(i + 1);
		ft_memcpy(*line, *tmp, i);
		(*line)[i] = '\0';
		str = ft_strdup(*tmp + i + 1);
		ft_free(&tmp);
		*tmp = str;
		return (1);
	}
	*line = ft_strdup(*tmp);
	ft_free(&tmp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char *tmp = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!tmp)
		tmp = ft_newstring(0);
	while (ft_strspn(tmp, '\n') == -1 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoinfree(tmp, buf)))
			return (-1);
	}
	return (ft_intline(line, &tmp));
}
