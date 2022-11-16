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

int	ft_read_lst(t_lst_parser *lst, t_env *st, int read, int write)
{
	int pip[2];
	int fd;

	//printf("CMD %s\tRead %d - Write %d\n", lst->value.cmd[0], read, write);
	if (lst && lst->next && lst->type == CMD)
		lst = lst->next;
	if (lst && lst->type == PIPE)
	{
		if (lst->next)
		{
			if (pipe(pip) == -1)
			{
				printf("Pipe Fail\n");
				return (1);
			}
			if (ft_read_lst(lst->next, st, pip[0], pip[1]))
				return (1);
			if (lst->next->next == NULL || write == -1)
				ft_is_builtin(lst->next->value.cmd, st, read, write, pip[0], pip[1], CMD_BEGIN);
			else if (lst->prev)
				ft_is_builtin(lst->next->value.cmd, st, pip[0], pip[1], read, write, CMD_MIDDLE);
			/*
			if (strcmp(lst->next->value.cmd[0], "grep") == 0)
				ft_is_builtin(lst->next->value.cmd, st, pip[0], pip[1], read, write, CMD_MIDDLE);
			else if (strcmp(lst->next->value.cmd[0], "ls") == 0)
				ft_is_builtin(lst->next->value.cmd, st, read, write, pip[0], pip[1], CMD_BEGIN);
			*/
			//else
			//	ft_is_builtin(lst->next->value.cmd, st, pip, pip2, CMD_MIDDLE);
			//printf("CMD %s-%s\n", lst->value.oper, lst->next->value.cmd[0]);
			//printf("OPER %s-%s-%s\n", lst->next->value.cmd[0], lst->value.oper, lst->prev->value.cmd[0]);
		
		}
		else
			printf("bash: syntax error near unexpected token `|'\n");
	}
	if (lst && lst->type == FILE_IN)
	{
		dprintf(STDERR_FILENO, "YOUHOU\n");
		lst = lst->next;
		fd = open(lst->value.oper, O_RDONLY);
		if (lst->next)
			ft_read_lst(lst->next, st, fd, -1);
		else
			read = fd;
	}
	if (lst && lst->prev == NULL && lst->next == NULL)
		ft_is_builtin(lst->value.cmd, st, read, write, pip[0], pip[1], CMD_END);
	else if (lst && read == 3)
		ft_is_builtin(lst->prev->value.cmd, st, read, write, pip[0], pip[1], CMD_END);
	return (0);
}


int	ft_read_dumb(t_lst_parser *lst, t_env *st, int read, int write, int fd2)
{
	int	pip[2];
	int	fd;

	if (lst && lst->prev == NULL && lst->next == NULL && lst->type == CMD)
	{
		pipe(pip);
		ft_is_builtin_dumb(lst->value.cmd, st, read, write, pip[0], pip[1], CMD_END);
	}
	else if (lst && lst->type == CMD && fd2 == 0)
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
	else if (lst && lst->prev && lst->type == CMD && (lst->prev->type == ARG_FILE_OUT_OVER || lst->prev->type == ARG_FILE_OUT_APP))
	{
		if (!lst->next)
			ft_is_builtin_dumb(lst->value.cmd, st, read, 1, write, fd2, CMD_FILE_OUT_END);
		else
			ft_is_builtin_dumb(lst->value.cmd, st, read, 1, write, fd2, CMD_FILE_OUT);
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
			ft_read_dumb(lst->next, st, pip[0], pip[1], 1);
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
	if (lst && (lst->type == FILE_OUT_OVER || lst->type == FILE_OUT_APP))
	{
		lst = lst->next;
		if (lst->type == ARG_FILE_OUT_OVER)
			fd = open(lst->value.oper, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else
			fd = open(lst->value.oper, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (fd == -1)
		{
			close(read);
			close(write);
			ft_putstr_fd("bash: No such file or directory\n", STDERR_FILENO);
			return (1);
		}
		ft_read_dumb(lst->next, st, read, write, fd);
	}
//	if (lst && !lst->next && lst->type ==  CMD)
//		ft_is_builtin_dumb(lst->value.cmd, st, read, write, pip[0], pip[1], CMD_END);
	return (0);
}


/*
int	ft_read_lst(t_lst_cmd *lst, t_env *st, int pip2[2])
{
	int pip[2];

	if (pip2)
		printf("BULLE %d-%d\n", pip2[0], pip2[1]);
	if (lst && lst->next && lst->type == CMD)
		lst = lst->next;
	if (lst && lst->type == PIPE)
	{
		if (lst->next)
		{
			if (pipe(pip) == -1)
			{
				printf("Pipe Fail\n");
				return (1);
			}
			//ft_is_builtin(lst->next->value.cmd, st, pip, CMD_BEGIN);
			//ft_is_builtin(lst->prev->value.cmd, st, pip, CMD_END);
			printf("PREPIPE %s\t%d-%d\n", lst->next->value.cmd[0], pip[0], pip[1]);
			
			if (ft_read_lst(lst->next, st, pip))
				return (1);
			if (strcmp(lst->next->value.cmd[0], "ls") == 0)
				ft_is_builtin(lst->next->value.cmd, st, pip, pip2, CMD_MIDDLE);
			else if (strcmp(lst->next->value.cmd[0], "cat") == 0)
				ft_is_builtin(lst->next->value.cmd, st, pip2, pip, CMD_BEGIN);
			//else
			//	ft_is_builtin(lst->next->value.cmd, st, pip, pip2, CMD_MIDDLE);
		
		}
		else
			printf("bash: syntax error near unexpected token `|'\n");
	}
	if (lst && !pip2)
	{
		printf("END %s\n", lst->prev->value.cmd[0]);
		ft_is_builtin(lst->prev->value.cmd, st, pip, NULL, CMD_END);
	}
	return (0);
}*/

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

int	ft_file_in(t_list **lst, t_lst_parser **lst_parser, char **cmd)
{
	ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(NULL, (*lst)->content, (*lst)->type));
	(*lst) = (*lst)->next;
	if ((*lst) && (*lst)->type < PIPE)
	{
		ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(NULL, (*lst)->content, (*lst)->type));
		(*lst) = (*lst)->next;
		if (cmd)
		{
			ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(cmd, NULL, CMD));
			return (1);
		}
		return (0);
	}
	else
	{
		ft_putstr_fd("bash: syntax error near unexpected token'\n", STDERR_FILENO);
		return (2);
	}

}

int	ft_create_lst_parser_dumb(t_list *lst, t_lst_parser **lst_parser)
{
	char	**cmd;
	int		i;
	int		ret;

	cmd = NULL;
	while (lst)
	{
		//if (lst && lst->type == CMD && (!(lst->next) || (lst->next && lst->next->type != FILE_IN)))
		if (lst && lst->type == CMD)
		{
			i = 0;
			cmd = malloc(sizeof(char *) * (ft_count_nb_cmd(lst) + 1));
			if (!cmd)
				return (1);
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
		//if (lst && lst->type == FILE_IN && cmd)
		if (lst && (lst->type == FILE_IN || lst->type == FILE_OUT_OVER || lst->type == FILE_OUT_APP))
		{
			/*
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
			*/
			ret = ft_file_in(&lst, lst_parser, cmd);
			if (ret == 2)
			{
				free(cmd);
				return (1);
			}
			else if (ret == 1)
			{
				free(cmd);
				cmd = NULL;
			}
			
		}
		else if (lst && lst->type == PIPE && !cmd)
		{
			ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
			lst = lst->next;
		}
		/*else if (lst && lst->type == FILE_IN && !cmd)
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

		}*/
		//else if (lst && (lst->type == FILE_OUT_OVER || lst->type == FILE_OUT_APP))
		//{
		//}
		if (cmd)
		{
			ft_lst_parse_add_back(lst_parser, ft_lst_parse_new(cmd, NULL, CMD));
			free(cmd);
			cmd = NULL;
		}
	}
	return (0);
}


int	ft_create_lst_parser(t_list *lst, t_lst_parser **lst_parser)
{
	char	**cmd;
	int		i;

	while (lst)
	{
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
			ft_lst_parse_add_front(lst_parser, ft_lst_parse_new(cmd, NULL, CMD));
			free(cmd);
		}
		if (lst && lst->type == PIPE)
		{
			ft_lst_parse_add_front(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
			lst = lst->next;
		}
		if (lst && lst->type == FILE_IN)
		{
			if (lst->next && lst->next->type == ARG_FILE_IN)
			{
				ft_lst_parse_add_front(lst_parser, ft_lst_parse_new(NULL, lst->next->content, lst->next->type));
				ft_lst_parse_add_front(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
				lst = lst->next->next;
			}
			else
			{
				ft_putstr_fd("bash: syntax error near unexpected token WUT?\n", STDERR_FILENO);
				return (1);			
			}
	//		ft_lst_parse_add_front(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
	//		lst = lst->next;
	//		if (!lst)
	//		{
	//			ft_putstr_fd("bash: syntax error near unexpected token `newline'\n", STDERR_FILENO);
	//			return (1);
	//		}
	//		if (lst->type != ARG_FILE_IN)
	//		{
	//			ft_putstr_fd("bash: syntax error near unexpected token\n", STDERR_FILENO);
	//			return (1);
	//		}
	//		ft_lst_parse_add_front(lst_parser, ft_lst_parse_new(NULL, lst->content, lst->type));
	//		lst = lst->next;
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
	//if (ft_create_lst_parser(lst, &lst_parser))
	//	return (1);
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
