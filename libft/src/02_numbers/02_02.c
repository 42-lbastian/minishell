/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:07:35 by krozis            #+#    #+#             */
/*   Updated: 2022/11/27 20:56:25 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_lltoa(long long int nb, char *s, int i)
{
	int	mod;

	mod = 0;
	while (i--)
	{
		if (nb)
		{
			mod = nb % 10;
			nb = nb / 10;
			s[i] = mod + '0';
		}
	}
}

char	*ft_lltoa(long long nb)
{
	char	*s;
	int		i;

	i = ft_nbrlen(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	if (nb < 0)
	{
		s[0] = '-';
		_ft_lltoa(-nb, s, i);
	}
	else
		_ft_lltoa(nb, s, i);
	return (s);
}
