/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unwanted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:10:17 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 11:39:14 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	_count_quotes(int i, int quotes, t_struct *main, int fact)
{
	if (fact == SIMPLE)
		main->char_check.last_simple_q = i;
	else if (fact == DOUBLE)
		main->char_check.last_double_q = i;
	if (quotes == 0)
		quotes++;
	else if (quotes == 1)
		quotes--;
	return (quotes);
}

static int	_count_quotes_unwanted(int quotes)
{
	if (quotes == 0)
		quotes++;
	else if (quotes == 1)
		quotes--;
	return (quotes);
}

char	*ms_remove_special(char *str, int i)
{
	int	simple_quotes;
	int	double_quotes;

	simple_quotes = 0;
	double_quotes = 0;
	while (str && str[i])
	{
		if (str[i] == '"')
			double_quotes = _count_quotes_unwanted(double_quotes);
		if (str[i] == '\'')
			simple_quotes = _count_quotes_unwanted(simple_quotes);
		if (!ft_isalnum(str[i]) && !ft_incharset(str[i], VALID_CHAR))
		{
			if (double_quotes == 0 && simple_quotes == 0)
				str = ft_str_rm_char(str, i);
			else if (str[i] == '\\' && (str[i + 1] == '"'
					|| str[i + 1] == '\'' || str[i + 1] == '\\'))
				str = ft_str_rm_char(str, i);
			else
				i++;
			i--;
		}
		i++;
	}
	return (str);
}

char	*ms_check_quotes(char *str, t_struct *main)
{
	int	i;
	int	simple_quotes;
	int	double_quotes;

	double_quotes = 0;
	simple_quotes = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' && simple_quotes == 0)
			double_quotes = _count_quotes(i, double_quotes, main, DOUBLE);
		if (str[i] == '\'' && double_quotes == 0)
			simple_quotes = _count_quotes(i, simple_quotes, main, SIMPLE);
		i++;
	}
	if (simple_quotes == 1)
	{
		str = ft_str_rm_char(str, main->char_check.last_simple_q);
		if (main->char_check.last_double_q > main->char_check.last_simple_q)
			main->char_check.last_double_q--;
	}
	if (double_quotes == 1)
		str = ft_str_rm_char(str, main->char_check.last_double_q);
	return (str);
}
