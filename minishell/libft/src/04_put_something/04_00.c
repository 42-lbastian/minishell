/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:15:03 by stelie            #+#    #+#             */
/*   Updated: 2022/11/18 11:52:22 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Puts a given character in the given fd.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
 * @brief Puts a given string in the given fd.
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

/*
 * @brief Puts a given string adding a line return '\n' in the given fd.
*/
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
 * @brief Puts the given int number in the given fd.
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putstr_fd("214748364", fd);
		n = 8;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

/*
 * @brief Put a message on the chosen fd and return the value needed
 * @param msg: the message to put
 * @param fd: the file descriptor of the output
 * @param ret: the return value needed
 * @author stelie
*/
int	ft_putmsg_fd(char *msg, int fd, int ret)
{
	ft_putstr_fd(msg, fd);
	return (ret);
}
