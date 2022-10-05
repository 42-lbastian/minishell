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

int		ft_read_ast(t_List st, t_node *node)
{
	//int	pip[2];

	(void)node;
	(void)st;
	//pipe(pip);
	if (node->left)
		ft_read_ast(st, node->left);
	if (node->right)
		ft_read_ast(st, node->right);
	if (!node->right)
	{
		ft_main_exec(node->value.cmd, st);
		return (1);
	}
	else
		printf("%s\n", node->value.oper);
	return (0);
}

int		ft_parse(t_list **lst, t_List st)
{
	t_node *node;
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
	node->right->value.cmd = ft_split("echo toto" ,' ');
	ft_read_ast(st, node);
	(void)lst;
	(void)st;
	return (0);
}
