/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:07:52 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/16 20:07:54 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_is_alpha_numb(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_belong_cmd_start(char c)
{
	if (c != ' ' && c && c != '<' && c != '>' && c != '|')
		return (1);
	return (0);
}

int	ft_belong_cmd_end(char c)
{
	if (c != ' ' && c != '<' && c != '>' && c != '|')
		return (1);
	return (0);
}

int	ft_count_check(char c)
{
	if (c != '\'' && c != '"' && c != '$' && c != ' ')
		return (1);
	return (0);
}
