/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:58:12 by stelie            #+#    #+#             */
/*   Updated: 2022/12/08 15:54:42 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
 * @brief Prints the error for the wrong export arguments, 
 * according to original bash behavior.
*/
static bool	_print_export_error(char *arg)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(ERR_EXPORT, STDERR_FILENO);
	return (false);
}

/*
 * @brief Verifies if an arg is conform to export.
 * @return Returns true if arg can be used, false if not.
*/
static bool	_check_export_arg(char	*arg)
{
	int	i;

	if (ft_strlen(arg) == 0)
		return (_print_export_error(NULL));
	i = 1;
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (_print_export_error(arg));
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (_print_export_error(arg));
		i++;
	}
	return (true);
}

/*
 * @brief Exports one element.
*/
static int	_export_one(char *arg, t_env *env, char *var)
{
	char	*value;
	//int		i;
	int		exit_code;

	value = NULL;
	exit_code = EXIT_SUCCESS;
	if (ft_incharset('=', arg) == false)
		return (exit_code);
	//i = 0;
	var = ft_str_cut_before(arg, '=');
	if (var == NULL)
		exit_code = EXIT_FAILURE;
	else
	{
		value = ft_str_cut_after(arg, '=');
		exit_code = ms_env_update(env, var, value);
	}
	return (exit_code);
}

/*
 * @brief the export builtin mandatory in the project
 * @param args: a string array where the first str is "export"
 * @return Returns the err_code.
*/
int	export_builtin(char **args)
{
	t_env	*env;
	int		i;
	int		exit_code;
	char	*var;

	exit_code = EXIT_SUCCESS;
	i = 1;
	var = NULL;
	env = get_env();
	if (args[i] == NULL)
		return (_export_no_args(env));
	while (args[i] && exit_code == EXIT_SUCCESS)
	{
		if (_check_export_arg(args[i]) == true)
			exit_code = _export_one(args[i], env, var);
		i++;
	}
	return (EXIT_SUCCESS);
}
