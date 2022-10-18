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

int	ft_read_lst(t_lst_cmd *lst, t_List st, int fd)
{
	int pip[2];

	printf("%d\n", fd);
	while (lst)
	{
		if (lst->type == PIPE)
		{
			if (lst->next)
			{
				pipe(pip);
				lst = lst->next;
				ft_read_lst(lst, st, pip[1]);

			}
			else
				printf("bash: syntax error near unexpected token `|'\n");
		}
		else
			lst = lst->next;
	}
	return (1);
}

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
	t_lst_cmd *lst2;
	t_lst_cmd *lst3;

	lst1 = malloc(sizeof(t_lst_cmd));
	lst2 = malloc(sizeof(t_lst_cmd));
	lst3 = malloc(sizeof(t_lst_cmd));

	lst1->next = lst2;
	lst2->next = lst3;
	lst3->next =  NULL;

	lst1->value.oper = "|";
	lst1->type = PIPE;

	lst2->value.cmd = ft_split("ls", ' ');
	lst2->type = CMD;

	lst3->value.cmd = ft_split("echo lbastian", ' ');
	lst3->type = CMD;
	ft_read_lst(lst1, st, 1);

	(void)lst;
	return (0);
}
