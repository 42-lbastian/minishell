/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:44 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/16 20:09:46 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_set_type_oper(t_struct *main)
{
	if (ft_strcmp_2(ft_lst_last(main->lst)->content, "|") == 0)
		ft_lst_last(main->lst)->type = PIPE;
	else if (ft_strcmp_2(ft_lst_last(main->lst)->content, "<") == 0)
		ft_lst_last(main->lst)->type = FILE_IN;
	else if (ft_strcmp_2(ft_lst_last(main->lst)->content, ">") == 0)
		ft_lst_last(main->lst)->type = FILE_OUT_OVER;
	else if (ft_strcmp_2(ft_lst_last(main->lst)->content, ">>") == 0)
		ft_lst_last(main->lst)->type = FILE_OUT_APP;
	else if (ft_strcmp_2(ft_lst_last(main->lst)->content, "<<") == 0)
		ft_lst_last(main->lst)->type = HERE_DOC;
	else
		main->char_check.error = 1;
}

void	ft_read_special(char *str, t_struct *main)
{
	int	y;
	int	error;

	y = 0;
	main->is_arg = 0;
	while (str[main->i + y] && ft_special_char(str[main->i + y]))
		y++;
	error = ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y),
				DEFAULT));
	if (error || !(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	else
		ft_set_type_oper(main);
	main->i += y;
}

int	ft_count_read_quotes(char *str, int start)
{
	int		size;
	char	c;

	c = str[start];
	size = 1;
	while (str[start + size] != c)
		size++;
	return (size);
}

void	ft_read_cmd(char *str, t_struct *main)
{
	int	y;
	int	error;

	y = 0;
	while (str[main->i + y])
	{
		if (str[main->i + y] == '"' || str[main->i + y] == '\'')
			y += ft_count_read_quotes(str, main->i + y);
		if (!(str[main->i + y]) || ft_belong_cmd_end(str[main->i + y]) == 0)
			break ;
		y++;
	}
	if (str[main->i + y] == ' ')
		y--;
	error = ft_lstadd_back(&(main->lst), ft_lst_new(ft_substr(str, main->i, y
					+ 1), CMD));
	if (error || !(ft_lst_last(main->lst)->content))
		main->char_check.error = 1;
	main->i += y;
	if (str[main->i])
		main->i++;
}
