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
   int		ft_read_ast(t_List st, t_node *node)
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
   ft_main_exec(node->value.cmd, st);
   return (pip[0]);
   }
   else
   printf("%s\n", node->value.oper);
   return (0);
   }
 */

int	ft_read_lst(t_lst_cmd *lst, t_List st, int read, int write)
{
	int pip[2];

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
			//ft_main_exec(lst->next->value.cmd, st, pip, CMD_BEGIN);
			//ft_main_exec(lst->prev->value.cmd, st, pip, CMD_END);
			if (ft_read_lst(lst->next, st, pip[0], pip[1]))
				return (1);
			//printf("CMD %s\tRead %d|Write %d\tReadB %d|WriteB %d\n", lst->next->value.cmd[0], read, write, pip[0], pip[1]);
			if (strcmp(lst->next->value.cmd[0], "grep") == 0)
				ft_main_exec(lst->next->value.cmd, st, pip[0], pip[1], read, write, CMD_MIDDLE);
			else if (strcmp(lst->next->value.cmd[0], "ls") == 0)
				ft_main_exec(lst->next->value.cmd, st, read, write, pip[0], pip[1], CMD_BEGIN);
			//else
			//	ft_main_exec(lst->next->value.cmd, st, pip, pip2, CMD_MIDDLE);
			//printf("CMD %s-%s\n", lst->value.oper, lst->next->value.cmd[0]);
			//printf("OPER %s-%s-%s\n", lst->next->value.cmd[0], lst->value.oper, lst->prev->value.cmd[0]);
		
		}
		else
			printf("bash: syntax error near unexpected token `|'\n");
	}
	if (lst && read == 3)
		ft_main_exec(lst->prev->value.cmd, st, read, write, pip[0], pip[1], CMD_END);
	return (0);
}

/*
int	ft_read_lst(t_lst_cmd *lst, t_List st, int pip2[2])
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
			//ft_main_exec(lst->next->value.cmd, st, pip, CMD_BEGIN);
			//ft_main_exec(lst->prev->value.cmd, st, pip, CMD_END);
			printf("PREPIPE %s\t%d-%d\n", lst->next->value.cmd[0], pip[0], pip[1]);
			
			if (ft_read_lst(lst->next, st, pip))
				return (1);
			if (strcmp(lst->next->value.cmd[0], "ls") == 0)
				ft_main_exec(lst->next->value.cmd, st, pip, pip2, CMD_MIDDLE);
			else if (strcmp(lst->next->value.cmd[0], "cat") == 0)
				ft_main_exec(lst->next->value.cmd, st, pip2, pip, CMD_BEGIN);
			//else
			//	ft_main_exec(lst->next->value.cmd, st, pip, pip2, CMD_MIDDLE);
		
		}
		else
			printf("bash: syntax error near unexpected token `|'\n");
	}
	if (lst && !pip2)
	{
		printf("END %s\n", lst->prev->value.cmd[0]);
		ft_main_exec(lst->prev->value.cmd, st, pip, NULL, CMD_END);
	}
	return (0);
}*/

int		ft_parse(t_list **lst, t_List st)
{
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

	t_lst_cmd *lst1;

	lst1 = NULL;
	ft_lst_parse_add_back(&lst1, ft_lst_parse_new(ft_split("wc -l", ' '), NULL, CMD));
	ft_lst_parse_add_back(&lst1, ft_lst_parse_new(NULL, "|", PIPE));
	ft_lst_parse_add_back(&lst1, ft_lst_parse_new(ft_split("grep l", ' '), NULL, CMD));
	ft_lst_parse_add_back(&lst1, ft_lst_parse_new(NULL, "|", PIPE));
	ft_lst_parse_add_back(&lst1, ft_lst_parse_new(ft_split("ls", ' '), NULL, CMD));

	//	ft_print_lst_parse(lst1);
	//	printf("\n\n");
	//	ft_print_lst_parse_reverse(lst1);
	int bubule[2];

	pipe(bubule);
	ft_read_lst(lst1, st, bubule[0], bubule[1]);
	//ft_read_lst(lst1, st, NULL);

	(void)lst;
	return (0);
}
