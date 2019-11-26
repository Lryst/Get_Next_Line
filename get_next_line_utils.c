/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:11:31 by lryst             #+#    #+#             */
/*   Updated: 2019/11/25 15:57:53 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (dest == 0)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;
	unsigned int	u;

	u = 0;
	dst = (unsigned char*)dest;
	sr = (unsigned char*)src;
	if (!n || sr == dst)
		return (dst);
	while (n--)
	{
		dst[u] = sr[u];
		u++;
	}
	return (dst);
}

char		*ft_newstring(size_t i)
{
	char *str;
	size_t zero;

	zero = 0;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (str && zero < i + 1)
	{
		str[zero] = '\0';
		zero++;
		
	}
	return (str);
}