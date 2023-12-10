/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:23:00 by ojebbari          #+#    #+#             */
/*   Updated: 2023/01/23 11:01:22 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_new_str(char *str)
{
	char	*po;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	po = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!po)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	i++;
	while (str[i])
		po[j++] = str[i++];
	po[j] = '\0';
	return (free(str), po);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_trimlast(str, '\n');
	str = ft_new_str(str);
	return (line);
}
