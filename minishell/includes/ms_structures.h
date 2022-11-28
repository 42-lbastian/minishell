/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:56:45 by stelie            #+#    #+#             */
/*   Updated: 2022/11/28 14:46:30 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCTURES_H
# define MS_STRUCTURES_H

/*
typedef struct s_lexer_token
{
	char	*tok;
	int		type;
}				t_lextok;
*/

typedef struct s_char_check
{
	int		last_simple_q;
	int		last_double_q;
	int		error;
}				t_char_check;

/*
typedef struct s_minishell_main
{
	int				i;
	int				is_arg;
	t_list			lst;
	t_char_check	char_check;
}				t_ms;
*/

//Value for AST/LST_CMD
typedef union s_value
{
	char	**cmd;
	char	*oper;
}				t_value;

//LEXER TOKEN
typedef struct s_mslist
{
	char			*content;
	struct s_mslist	*next;
	int				type;
}				t_mslist;

typedef struct s_struct
{
	int				i;
	int				is_arg;
	t_mslist		*lst;
	t_char_check	char_check;
}		t_struct;

#endif