/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:45:06 by krozis            #+#    #+#             */
/*   Updated: 2022/11/15 15:38:59 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	update_aloc(char **aloc, char *new_aloc)
{
	char	*temp;

	temp = *aloc;
	*aloc = new_aloc;
	free(temp);
}

static char	*get_line(char **acc)
{
	size_t	c;
	char	*s;

	if (*acc == NULL)
		return (NULL);
	c = (size_t)(ft_strchr(*acc, '\n') - *acc) + 1;
	s = ft_substr(*acc, 0, c);
	update_aloc(acc, ft_substr(*acc, c, ft_strlen_libft(*acc)));
	if (*acc[0] == '\0')
		update_aloc(acc, NULL);
	return (s);
}

static void	read_line(int fd, char **acc, char *buffer, int *read_bytes)
{
	*read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (*read_bytes > 0)
	{
		if (*acc == NULL)
			update_aloc(acc, ft_strdup(""));
		buffer[*read_bytes] = '\0';
		update_aloc(acc, ft_strjoin(*acc, buffer));
		while (*read_bytes > 0 && ft_strchr(buffer, '\n') == NULL)
		{
			*read_bytes = read(fd, buffer, BUFFER_SIZE);
			buffer[*read_bytes] = '\0';
			update_aloc(acc, ft_strjoin(*acc, buffer));
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*acc = NULL;
	char		*buffer;
	char		*line;
	int			read_bytes;

	if (fd < 0)
	{
		update_aloc(&acc, NULL);
		return (NULL);
	}
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_line(fd, &acc, buffer, &read_bytes);
	line = get_line(&acc);
	free(buffer);
	return (line);
}
