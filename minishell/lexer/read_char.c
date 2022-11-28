/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:44 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/28 13:32:01 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_set_type_oper(t_struct *main)
{
	if (ft_strcmp(ms_lst_last(main->lst)->content, "|") == 0)
		ms_lst_last(main->lst)->type = PIPE;
	else if (ft_strcmp(ms_lst_last(main->lst)->content, "<") == 0)
		ms_lst_last(main->lst)->type = FILE_IN;
	else if (ft_strcmp(ms_lst_last(main->lst)->content, ">") == 0)
		ms_lst_last(main->lst)->type = FILE_OUT_OVER;
	else if (ft_strcmp(ms_lst_last(main->lst)->content, ">>") == 0)
		ms_lst_last(main->lst)->type = FILE_OUT_APP;
	else if (ft_strcmp(ms_lst_last(main->lst)->content, "<<") == 0)
		ms_lst_last(main->lst)->type = HERE_DOC;
	else
		main->char_check.error = 1;
}

void	ms_read_special(char *str, t_struct *main)
{
	int	y;
	int	error;

	y = 0;
	main->is_arg = 0;
	while (str[main->i + y] && ft_incharset(str[main->i + y], SPECIAL_CHAR))
		y++;
	error = ms_lstadd_back(&(main->lst), ms_lst_new(ft_substr(str, main->i, y),
				DEFAULT));
	if (error || !(ms_lst_last(main->lst)->content))
		main->char_check.error = 1;
	else
		ms_set_type_oper(main);
	main->i += y;
}

int	ms_count_read_quotes(char *str, int start)
{
	int		size;
	char	c;

	c = str[start];
	size = 1;
	while (str[start + size] != c)
		size++;
	return (size);
}

void	ms_read_cmd(char *str, t_struct *main)
{
	int	y;
	int	error;

	y = 0;
	while (str[main->i + y])
	{
		if (str[main->i + y] == '"' || str[main->i + y] == '\'')
			y += ms_count_read_quotes(str, main->i + y);
		if (!(str[main->i + y]) || ft_incharset(str[main->i + y], CMD_CHAR))
			break ;
		y++;
	}
	if (str[main->i + y] == ' ')
		y--;
	error = ms_lstadd_back(&(main->lst), ms_lst_new(ft_substr(str, main->i, y
					+ 1), CMD));
	if (error || !(ms_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
	if (str[main->i])
		main->i++;
}
