/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:40:28 by ojebbari          #+#    #+#             */
/*   Updated: 2023/01/24 19:02:36 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		*str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_trimlast(str[fd], '\n');
	str[fd] = ft_new_str(str[fd]);
	return (line);
}
