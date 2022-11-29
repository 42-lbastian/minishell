/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:03 by lbastian          #+#    #+#             */
/*   Updated: 2022/11/29 13:42:07 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Allocates then fills with zeros
*/
static t_struct	*ms_init_struct(void)
{
	t_struct	*main_s;

	main_s = NULL;
	main_s = malloc(sizeof(t_struct));
	if (main_s == NULL)
		return (NULL);
	ft_bzero(main_s, sizeof(t_struct));
	return (main_s);
}

static int	ms_lexer(char *str, t_struct *main_s)
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

int	ms_main_lexer(char *str, t_env *st)
{	
	int			ret;
	t_struct	*main_s;

	main_s = ms_init_struct();
	str = ms_check_quotes(str, main_s);
	str = ms_check_quotes(str, main_s);
	str = ms_remove_special(str, 0);
	ret = ms_lexer(str, main_s);
	if (ret == 0)
		ret = ms_set_type_cmd(&main_s->lst);
	if (ret == 0)
		ret = ms_remove_spaces(&main_s->lst);
	if (ret == 0)
		ret = ms_main_replace_env(&main_s->lst, st);
	if (ret == 0)
		ret = ms_main_remove_quotes(&main_s->lst);
	if (ret == EXIT_FAILURE)
	{
		ms_free_main_s(main_s);
		return (EXIT_FAILURE);
	}
	return (ms_parse(main_s, main_s->lst, st));
}
