/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:43 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/14 12:48:59 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ms_split_expand(char *temp, t_mslist **lst, char **split)
{
	int	i;

	i = 1;
	free(temp);
	if (!split)
		return (1);
	(*lst)->content = ms_strjoin_2(((*lst)->content), split[0]);
	while (split[i])
	{
		if (ms_lstadd(lst, ms_lst_new_join(split[i], CMD)))
			return (1);
		(*lst) = (*lst)->next;
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

static int	ms_set_quotes(char *str, int i, int quotes)
{
	if (str[i] == '\'' && quotes == 0)
		quotes = 1;
	else if (str[i] == '"' && quotes == 0)
		quotes = 2;
	else if ((str[i] == '\'' && quotes == 1)
		|| (str[i] == '"' && quotes == 2))
		quotes = 0;
	return (quotes);
}

static int	ms_replace_loop(t_mslist **lst, t_env *st, char *str, int **count)
{
	int		j;
	char	*temp;

	(*count)[0]++;
	if (str[(*count)[0]] && str[(*count)[0]] != '\'' && str[(*count)[0]]
			!= '"' && str[(*count)[0]] != '$'
		&& str[(*count)[0]] != ' ')
	{
		j = (*count)[0];
		while (str[(*count)[0]] && str[(*count)[0]] != '\''
			&& str[(*count)[0]] != '"' && str[(*count)[0]] != '$'
			&& str[(*count)[0]] != ' ')
			(*count)[0]++;
		temp = ms_find_var((ft_substr(str, j, (*count)[0] - j)), st);
		if (!temp)
			return (ft_free_and_return(str, EXIT_FAILURE));
		if ((*count)[1] == 2 || ms_strlen(temp) == 0)
			(*lst)->content = ms_strjoin_2((*lst)->content, temp);
		else
			if (ms_split_expand(temp, lst, ft_split(temp, ' ')))
				return (ft_free_and_return(str, EXIT_FAILURE));
	}
	else
		(*lst)->content = ms_strjoin_c((*lst)->content, '$');
	return (0);
}

static int	ms_replace(t_mslist **lst, t_env *st, int *count)
{
	char	*str;

	str = ms_strcpy((*lst)->content);
	if (!str)
		return (1);
	free((*lst)->content);
	(*lst)->content = NULL;
	while (str[count[0]])
	{
		count[1] = ms_set_quotes(str, count[0], count[1]);
		if (str[count[0]] == '$' && count[1] != 1)
		{
			if (ms_replace_loop(lst, st, str, &count))
				return (1);
		}
		else
		{
			(*lst)->content = ms_strjoin_c((*lst)->content, str[count[0]]);
			count[0]++;
		}
		if (!(*lst)->content)
			return (ft_free_and_return(str, EXIT_FAILURE));
	}
	free(str);
	return (0);
}

int	ms_main_replace_env(t_mslist **lst, t_env *st)
{
	t_mslist	*temp;
	int			*count;

	count = malloc(sizeof(int) * 2);
	if (!count)
		return (1);
	temp = (*lst);
	while (lst && (*lst))
	{
		count[0] = 0;
		count[1] = 0;
		if ((*lst)->type != LIMITOR)
		{
			if (ms_replace(lst, st, count) || !(*lst)->content)
			{
				free(count);
				return (1);
			}
		}
		(*lst) = (*lst)->next;
	}
	free(count);
	(*lst) = temp;
	return (0);
}
