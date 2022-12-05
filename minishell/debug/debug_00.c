/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:09:30 by lbastian          #+#    #+#             */
/*   Updated: 2022/12/05 16:45:05 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @name: _basic_check()
 * @brief sert a verifier les constantes, defines etc.. (A supprimer plus tard)
 * @return Retourne EXIT_SUCCESS ou EXIT_FAILURE.
*/
int	_basic_checks(void)
{
	if (ms_strlen(VALID_CHAR) != NB_CHAR_VALID)
		return (ft_putmsg_fd(ERR_NB_CHAR, STDERR_FILENO, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

/*
 * @brief Prints the mslist
*/
void	_ms_print_lst(t_mslist *lst)
{
	while (lst)
	{
		if (lst->type == PIPE)
			printf("{%s}\t[|]\n", lst->content);
		if (lst->type == FILE_IN)
			printf("{%s}\t[<]\n", lst->content);
		if (lst->type == FILE_OUT_OVER)
			printf("{%s}\t[>]\n", lst->content);
		if (lst->type == FILE_OUT_APP)
			printf("{%s}\t[>>]\n", lst->content);
		if (lst->type == HERE_DOC)
			printf("{%s}\t[<<]\n", lst->content);
		if (lst->type == CMD)
			printf("{%s}\t[CMD]\n", lst->content);
		if (lst->type == ARG_FILE_IN)
			printf("{%s}\t[ARG_FILE_IN]\n", lst->content);
		if (lst->type == ARG_FILE_OUT_OVER)
			printf("{%s}\t[ARG_FILE_OUT_OVER]\n", lst->content);
		if (lst->type == ARG_FILE_OUT_APP)
			printf("{%s}\t[ARG_FILE_OUT_APP]\n", lst->content);
		if (lst->type == LIMITOR)
			printf("{%s}\t[LIMITOR]\n", lst->content);
		lst = lst->next;
	}
}

/*
 * @brief [DEPRECATED] clear and free the given t_env.
 * Kept for "in case of" reasons only.
 * @todo: delete when finished.
*/
void	ms_clear_env(t_env **st)
{
	t_env	*temp;

	while ((*st))
	{
		temp = (*st)->next;
		free((*st)->value);
		free((*st)->var);
		free((*st));
		(*st) = NULL;
		(*st) = temp;
	}
}

/*
 * @brief Show all t_env pointers address
 */
void	_display_env_pointers(void)
{
	t_env	*env;

	env = NULL;
	env = get_env();
	while (env)
	{
		printf("ENV %s - var=%p - value=%p\n", env->var, env->var,env->value);
		env = env->next;
	}
}
