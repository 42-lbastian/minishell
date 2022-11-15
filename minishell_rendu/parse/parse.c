#include "../include/minishell.h"

int		ft_print_cmd(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf("%s ", str[i]);
		i++;
	}
	printf("\n");
	return (0);
}

/*
   int		ft_read_ast(t_env *st, t_node *node)
   {
   int	pip[2];
   int fd;

   pipe(pip);
   if (node->left)
   fd = ft_read_ast(st, node->left);
   if (node->right)
   fd = ft_read_ast(st, node->right);
   if (!node->right)
   {
   ft_is_builtin(node->value.cmd, st);
   return (pip[0]);
   }
   else
   printf("%s\n", node->value.oper);
   return (0);
   }
 */

int	ft_read_dumb(t_lst_parser *lst, t_env *st, int read, int write, int fd2)
{
	int	pip[2];
	int	fd;

	if (lst && lst->prev == NULL && lst->next == NULL && lst->type == CMD)
	{
		pipe(pip);
		ft_is_builtin_dumb(lst->value.cmd, st, read, write, pip[0], pip[1], CMD_END);
	}
	else if (lst && lst->type == CMD && read == 3)
	{
		ft_is_builtin_dumb(lst->value.cmd, st, 0, 1, read, write, CMD_BEGIN);
		lst = lst->next;
	}
	else if (lst && lst->prev && lst->prev->type == ARG_FILE_IN && lst->type == CMD)
	{
		if (!lst->next)
			ft_is_builtin_dumb(lst->value.cmd, st, fd2, 1, read, write, CMD_FILE_IN_END);
		else
			ft_is_builtin_dumb(lst->value.cmd, st, fd2, 1, read, write, CMD_FILE_IN);
		lst = lst->next;
	}
	else if (lst && lst->next && lst->type == CMD)
		lst = lst->next;
	if (lst && lst->type == PIPE)
	{
		if (lst->next && lst->prev)
		{
			pipe(pip);
			if (!lst->next->next && lst->next->type == CMD)
			{
				ft_is_builtin_dumb(lst->next->value.cmd, st, read, write, pip[0], pip[1], CMD_END);
				return (0);
			}
			else if (lst->next->type == CMD)
				ft_is_builtin_dumb(lst->next->value.cmd, st, read, write, pip[0], pip[1], CMD_MIDDLE);
			lst = lst->next;
			ft_read_dumb(lst->next, st, pip[0], pip[1], 0);
		}
		else
		{
			ft_putstr_fd("bash: syntax error near unexpected token `|'\n", STDERR_FILENO);
			return (1);
		}
	}
	if (lst && lst->type == FILE_IN)
	{
		//if (lst->next && lst->next->type == ARG_FILE_IN)
		//{

			pipe(pip);
			lst = lst->next;
			fd = open(lst->value.oper, O_RDONLY);
			close(read);
			close(write);
			if (fd == -1)
			{
				close(pip[0]);
				close(pip[1]);
				ft_putstr_fd("bash: No such file or directory\n", STDERR_FILENO);
				return (1);
			}
			ft_read_dumb(lst->next, st, pip[0], pip[1], fd);

		//}
		//else
		//{
		//	ft_putstr_fd("bash: syntax error near unexpected token HELLO\n", STDERR_FILENO);
		//	return (1);
		//}	
	}
	return (0);
}

int	ft_count_nb_cmd(t_list *lst)
{
	int i;

	i = 0;
	while (lst && lst->type == CMD)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_create_lst_parser_dumb(t_list *lst, t_lst_parser **lst_parser)
{
	char	**cmd;
	int		i;

	cmd = NULL;
	while (lst)
	{
		//if (lst && lst->type == CMD && (!(lst->next) || (lst->next && lst->next->type != FILE_IN)))
		if (lst && lst->type == CMD)
		{
			i = 0;
			cmd = malloc(sizeof(char *) * (ft_count_nb_cmd(lst) + 1));
			while(lst && lst->type == CMD)
			{
				cmd[i] = lst->content;
				i++;
				lst = lst->next;
			}
			cmd[i] = NULL;
			//ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(cmd, NULL, CMD));
			//free(cmd);
		}
		//if (lst && lst->type == CMD && lst->next && lst->next->type == FILE_IN)
		if (lst && lst->type == FILE_IN && cmd)
		{
			//cmd = malloc(sizeof(char *) * 2);
			//cmd[0] = lst->content;
			//cmd[1] = NULL;
			ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
			lst = lst->next;
			if (lst && lst->type == ARG_FILE_IN)
			{
				ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
				lst = lst->next;
				ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(cmd, NULL, CMD));
			}
			else
			{
				ft_putstr_fd("bash: syntax error near unexpected token HELLO\n", STDERR_FILENO);
				return (1);
			}
			free(cmd);
			cmd = NULL;
		}
		else if (lst && lst->type == PIPE && !cmd)
		{
			ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
			lst = lst->next;
		}
		else if (lst && lst->type == FILE_IN && !cmd)
		{

			ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
			lst = lst->next;
			if (lst && lst->type == ARG_FILE_IN)
			{
				ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
				lst = lst->next;
			}
			else
			{
				ft_putstr_fd("bash: syntax error near unexpected token'\n", STDERR_FILENO);
				return (1);
			}

		}
		if (cmd)
		{
			ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(cmd, NULL, CMD));
			free(cmd);
			cmd = NULL;
		}
	}
	return (0);
}

int		ft_parse(t_list *lst, t_env *st)
{
	int pip[2];
	t_lst_parser *lst_parser_dumb;

	/*t_node *node;
	  t_node *left;
	  t_node *right;

	  node = malloc(sizeof(t_node));
	  left = malloc(sizeof(t_node));
	  right = malloc(sizeof(t_node));
	  node->value.oper = "|";
	  node->left = left;
	  node->right = right;
	  node->left->left = NULL;
	  node->left->right = NULL;
	  node->left->value.cmd = ft_split("ls" ,' ');
	  node->right->left = NULL;
	  node->right->right = NULL;
	  node->right->value.cmd = ft_split("echo lbastian" ,' ');
	  ft_read_ast(st, node);
	 */

	lst_parser_dumb = NULL;
	if (ft_create_lst_parser_dumb(lst, &lst_parser_dumb))
		return (1);
	
	/*
	ft_lst_parse_add_back(&lst_parser, ft_lst_parse_new(ft_split("wc -l", ' '), NULL, CMD));
	ft_lst_parse_add_back(&lst_parser, ft_lst_parse_new(NULL, "|", PIPE));
	ft_lst_parse_add_back(&lst_parser, ft_lst_parse_new(ft_split("grep l", ' '), NULL, CMD));
	ft_lst_parse_add_back(&lst_parser, ft_lst_parse_new(NULL, "|", PIPE));
	ft_lst_parse_add_back(&lst_parser, ft_lst_parse_new(ft_split("ls", ' '), NULL, CMD));
	*/
	//	ft_print_lst_parse(lst_parser);
	//	printf("\n\n");
	//	ft_print_lst_parse_reverse(lst_parser);

	//ft_print_lst_parse(lst_parser_dumb);
	//printf("--------------\n");
	//ft_print_lst_parse(lst_parser2);
	pipe(pip);
	ft_read_dumb(lst_parser_dumb, st, pip[0], pip[1], 0);
	//ft_read_lst(lst_parser, st, pip[0], pip[1]);
	//ft_read_lst(lst_parser, st, NULL);
	return (0);
}
