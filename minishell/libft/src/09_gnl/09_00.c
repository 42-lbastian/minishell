/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:45:06 by krozis            #+#    #+#             */
/*   Updated: 2022/11/18 13:32:35 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_update_aloc(char **aloc, char *new_aloc)
{
	char	*temp;

	temp = *aloc;
	*aloc = new_aloc;
	free(temp);
}

static char	*_get_line(char **acc)
{
	size_t	c;
	char	*s;

	if (*acc == NULL)
		return (NULL);
	c = (size_t)(ft_strchr(*acc, '\n') - *acc) + 1;
	s = ft_substr(*acc, 0, c);
	_update_aloc(acc, ft_substr(*acc, c, ft_strlen(*acc)));
	if (*acc[0] == '\0')
		_update_aloc(acc, NULL);
	return (s);
}

static void	_read_line(int fd, char **acc, char *buffer, int *read_bytes)
{
	*read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (*read_bytes > 0)
	{
		if (*acc == NULL)
			_update_aloc(acc, ft_strdup(""));
		buffer[*read_bytes] = '\0';
		_update_aloc(acc, ft_strjoin(*acc, buffer));
		while (*read_bytes > 0 && ft_strchr(buffer, '\n') == NULL)
		{
			*read_bytes = read(fd, buffer, BUFFER_SIZE);
			buffer[*read_bytes] = '\0';
			_update_aloc(acc, ft_strjoin(*acc, buffer));
		}
	}
}

/*
 * @brief Returns a line ended by a carriage return read
 * in the given file descriptor fd.
 * Successive calls of gnl permit to read the full text in the fd.
*/
char	*get_next_line(int fd)
{
	static char	*acc = NULL;
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (fd < 0)
	{
		_update_aloc(&acc, NULL);
		return (NULL);
	}
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	_read_line(fd, &acc, buffer, &read_bytes);
	line = _get_line(&acc);
	free(buffer);
	return (line);
}
