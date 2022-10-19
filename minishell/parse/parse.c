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
				ft_read_lst(lst, st, pip[0]);

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

	lst1 = ft_lst_parse_new(NULL, "|", PIPE);

	ft_lst_parse_add_back(&lst1, ft_lst_parse_new(ft_split("ls", ' '), NULL, CMD));
	ft_lst_parse_add_back(&lst1, ft_lst_parse_new(ft_split("echo toto", ' '), NULL, CMD));

	ft_print_lst_parse(lst1);
	printf("\n\n");
	ft_print_lst_parse_reverse(lst1);

	ft_read_lst(lst1, st, 1);

	(void)lst;
	return (0);
}
