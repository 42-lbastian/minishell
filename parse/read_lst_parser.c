/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lst_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:20:38 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 13:00:20 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*_malloc_strjoin_here_doc(char *str1, char *str2)
{
	char	*dest;

	if (!str1)
		dest = malloc(sizeof(char) * (ms_strlen(str2) + 2));
	else
		dest = malloc(sizeof(char) * (ms_strlen(str1) + ms_strlen(str2) + 2));
	if (!dest)
		return (NULL);
	return (dest);
}

char	*ms_strjoin_here_doc(char *str1, char *str2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = _malloc_strjoin_here_doc(str1, str2);
	if (!dest)
		return (NULL);
	while (str1 && str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
	{
		dest[i + j] = str2[j];
		j++;
	}
	dest[i + j] = '\n';
	dest[i + j + 1] = '\0';
	if (str1)
		free(str1);
	return (dest);
}

static int	ms_check_cmd_2(t_lst_parser **lst, t_env *st, int pip[2][2], int i)
{
	if ((*lst) && (*lst)->prev && (*lst)->type == CMD && ((*lst)->prev->type
			== ARG_FILE_OUT_OVER || (*lst)->prev->type == ARG_FILE_OUT_APP))
	{
		if (!(*lst)->next)
			i = ms_is_builtin_short((*lst)->value.cmd, st, pip,
					CMD_FILE_OUT_END);
		else
			i = ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_FILE_OUT);
		(*lst) = (*lst)->next;
	}
	if ((*lst) && (*lst)->prev && (*lst)->type == CMD && (*lst)->prev->type
		== LIMITOR)
	{
		if (!(*lst)->next)
			i = ms_is_builtin_short((*lst)->value.cmd, st, pip,
					CMD_HERE_DOC_END);
		else
			i = ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_HERE_DOC);
		(*lst) = (*lst)->next;
	}
	return (i);
}

static int	ms_check_cmd(t_lst_parser **lst, t_env *st, int pip[2][2])
{
	int	i;

	i = 0;
	if ((*lst) && (*lst)->type == CMD && pip[0][0] == -1)
	{
		i = ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_BEGIN);
		(*lst) = (*lst)->next;
	}
	if ((*lst) && (*lst)->prev && (*lst)->prev->type
		== ARG_FILE_IN && (*lst)->type == CMD)
	{
		if (!(*lst)->next)
			i = ms_is_builtin_short((*lst)->value.cmd, st, pip,
					CMD_FILE_IN_END);
		else
			i = ms_is_builtin_short((*lst)->value.cmd, st, pip, CMD_FILE_IN);
		(*lst) = (*lst)->next;
	}
	i = ms_check_cmd_2(lst, st, pip, i);
	return (i);
}

int	ms_read_lst_parser(t_lst_parser *lst, t_env *st, int pip[2][2])
{
	if (lst && lst->prev == NULL && lst->next == NULL && lst->type == CMD)
	{
		if (ms_is_builtin_short(lst->value.cmd, st, pip, CMD_ALONE) == -1)
			return (-1);
		return (EXIT_SUCCESS);
	}
	if (ms_check_cmd(&lst, st, pip) == -1)
		return (-1);
	if (lst && lst->next && lst->type == CMD)
		lst = lst->next;
	if (lst && lst->type == PIPE)
		return (ms_read_pipe(lst, st, pip));
	if (lst && lst->type == FILE_IN)
		return (ms_read_file_in(lst, st, pip));
	if (lst && (lst->type == FILE_OUT_OVER || lst->type == FILE_OUT_APP))
		return (ms_read_file_out(lst, st, pip));
	if (lst && lst->type == HERE_DOC)
		return (ms_here_doc(lst->next, st, pip));
	return (0);
}
