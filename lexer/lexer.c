/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:03 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 11:36:28 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	_set_type_cmd(t_mslist **lst)
{
	t_mslist	*temp;

	temp = (*lst);
	while (lst && (*lst))
	{
		if ((*lst)->next && (*lst)->next->type == CMD
			&& (*lst)->type == FILE_IN)
			(*lst)->next->type = ARG_FILE_IN;
		else if ((*lst)->next && (*lst)->next->type == CMD
			&& (*lst)->type == FILE_OUT_OVER)
			(*lst)->next->type = ARG_FILE_OUT_OVER;
		else if ((*lst)->next && (*lst)->next->type == CMD
			&& (*lst)->type == FILE_OUT_APP)
			(*lst)->next->type = ARG_FILE_OUT_APP;
		else if ((*lst)->next && (*lst)->next->type == CMD
			&& (*lst)->type == HERE_DOC)
			(*lst)->next->type = LIMITOR;
		(*lst) = (*lst)->next;
	}
	(*lst) = temp;
	return (0);
}

/*
 * @brief Allocates then fills with zeros
*/
static t_struct	*_init_struct(void)
{
	t_struct	*main_s;

	main_s = NULL;
	main_s = malloc(sizeof(t_struct));
	if (main_s == NULL)
		return (NULL);
	ft_bzero(main_s, sizeof(t_struct));
	return (main_s);
}

static int	_lexer(char *str, t_struct *main_s)
{
	main_s->i = 0;
	main_s->is_arg = 0;
	while (str[main_s->i])
	{
		if (str[main_s->i] && !ft_incharset(str[main_s->i], CMD_CHAR))
			ms_read_cmd(str, main_s);
		if (str[main_s->i] && ft_incharset(str[main_s->i], SPECIAL_CHAR))
			ms_read_special(str, main_s);
		while (str[main_s->i] && str[main_s->i] == ' ')
			main_s->i++;
		if (main_s->char_check.error != 0)
			return (main_s->char_check.error);
	}
	return (0);
}

int	ms_lexer(char *str, t_env *st)
{	
	int			ret;
	t_struct	*main_s;

	main_s = _init_struct();
	str = ms_check_quotes(str, main_s);
	str = ms_check_quotes(str, main_s);
	str = ms_remove_special(str, 0);
	ret = _lexer(str, main_s);
	if (ret == 0)
		ret = _set_type_cmd(&main_s->lst);
	if (ret == 0)
		ret = ms_remove_spaces(&main_s->lst);
	if (ret == 0)
		ret = ms_main_replace_env(&main_s->lst, st);
	if (ret == 0)
		ret = ms_remove_quotes(&main_s->lst);
	if (ret == EXIT_FAILURE)
	{
		ms_free_main_s(main_s);
		return (EXIT_FAILURE);
	}
	ft_free(str);
	return (ms_parse(main_s, main_s->lst, st));
}
