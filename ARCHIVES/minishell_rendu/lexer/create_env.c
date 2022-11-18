#include "../include/minishell.h"

t_env	*ft_lst_new_env(char *var, char *value)
{
	t_env *env;

	env = malloc(sizeof(t_env));
	if (!env || (!var && !value))
		return (NULL);
	if (!var && value)
	{
		free(value);
		return (NULL);
	}
	if (!value && var)
	{
		free (var);
		return (NULL);
	}
	env->var = var;
	env->value = value;
	env->next = NULL;
	return (env);
}

t_env	*ft_lst_last_env(t_env *st)
{
	while (st && st->next)
		st = st->next;
	return (st);
}

int	ft_lst_add_back_env(t_env **st, t_env *new)
{
	if (!new)
		return (1);
	if (st && (*st))
		ft_lst_last_env((*st))->next = new;
	else
		(*st) = new;
	return (0);
}

int	ft_str_trim_env(char *str, t_env **st)
{
	int i;

	i = 0;
	while (str[i] != '=')
		i++;
	if (ft_lst_add_back_env(st, ft_lst_new_env(ft_substr(str, 0, i), ft_substr(str, i + 1, ft_strlen(str) - i))))
		return (1);
	return (0);

}

void	ft_clear_env(t_env **st)
{
	t_env *temp;
	while ((*st))
	{
		temp = (*st)->next;
		free((*st)->value);
		free((*st)->var);
		(*st) = (*st)->next;
		free((*st));
		(*st) = temp;
	}
}

int		ft_create_env(char **envp, t_env **st)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_str_trim_env(envp[i], st))
		{
			ft_clear_env(st);
			return (1);
		}
		i++;
	}
	return (0);
}
