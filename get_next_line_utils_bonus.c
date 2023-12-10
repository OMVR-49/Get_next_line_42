/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:40:33 by ojebbari          #+#    #+#             */
/*   Updated: 2023/01/24 19:04:08 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		else
			i++;
	}
	return (0);
}

static char	*ft_strjoin(char *str, char *add)
{
	char		*ret;
	size_t		i;
	size_t		j;

	if (!str)
	{
		str = malloc(1 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	i = -1;
	j = 0;
	ret = malloc((ft_strlen(str) + ft_strlen(add) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (str)
		while (str[++i] != '\0')
			ret[i] = str[i];
	while (add[j] != '\0')
		ret[i++] = add[j++];
	ret[i] = '\0';
	free(str);
	return (ret);
}

static void	passage_par_adresse(int *a, int *b, int *c)
{
	*a = 0;
	*b = -1;
	*c = 1;
}

char	*ft_read(int fd, char *str)
{
	char		*buffer;
	int			s;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	s = 1;
	while (s != 0)
	{
		s = read(fd, buffer, BUFFER_SIZE);
		if (s == -1)
		{
			free(str);
			return (free(buffer), NULL);
		}
		buffer[s] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*ft_trimlast(char *str, char c)
{
	char	*trimed;
	int		i;
	int		j;
	int		a;

	passage_par_adresse(&i, &j, &a);
	if (!str[i])
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			break ;
			i++;
	}
	if (ft_strchr(str, '\n'))
		a = 2;
	trimed = malloc(sizeof(char) * (i + a));
	if (!trimed)
		return (NULL);
	while (str[++j] != '\0' && j != (i + 1))
		trimed[j] = str[j];
	return (trimed[j] = '\0', trimed);
}
