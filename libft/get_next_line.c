/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:41:44 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/13 15:31:17 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	ft_next_line(const int fd, char **line, char **str)
{
	char	*temp;
	int		i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		temp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int	ft_return(const int fd, char **line, char **str, int x)
{
	if (x < 0)
		return (-1);
	else if (x == 0 && str[fd] == NULL)
		return (0);
	else
		return (ft_next_line(fd, line, str));
}

int	get_next_line(const int fd, char **line)
{
	int			x;
	char		current[BUFF_SIZE + 1];
	char		*temp;
	static char	*str[10240];

	if ((fd < 0 || fd > 10240) || !line)
		return (-1);
	while ((x = read(fd, current, BUFF_SIZE)) > 0)
	{
		current[x] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(current);
		else
		{
			temp = ft_strjoin(str[fd], current);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(current, '\n'))
			break ;
	}
	return (ft_return(fd, line, str, x));
}
