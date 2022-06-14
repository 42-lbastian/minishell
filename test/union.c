#include <stdio.h>
#include <stdlib.h>

typedef struct s_node t_node;

typedef struct	s_node_pointer
{
	t_node	*left;
	t_node	*right;

}				t_node_pointer;

typedef union	u_node_value
{
	int	nb;
	char	oper;
}				t_union_node;

struct	s_node
{
	t_union_node value;
	t_node_pointer node_pointer;
};

int	ft_print_tree(t_node *tab_node, int i)
{
	if (tab_node[i].node_pointer.left)
		ft_print_tree(tab_node, i + 1);
	else
	{
		printf("%d\t", tab_node[i].value.nb);
		return (0);
	}
	printf("%c\t", tab_node[i].value.oper);
	return (0);
}

int	ft_find_left_node(char **str, int index)
{
	int i;

	i = index - 1;
	while (i > 1)
	{
		if (str[i][0] == '+' || str[i][0] == '*')
			break;
		i--;
	}
	return (i);
}

int	ft_find_right_node(char **str, int index, int size)
{
	int i;

	i = index + 1;
	while (i < size)
	{
		if (str[i][0] == '+' || str[i][0] == '*')
			break;
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	int i;
	t_node *tab_node;
	
	i = 0;
	tab_node = malloc(sizeof(t_node) * argc - 1);

	while (i < argc - 1)
	{
		tab_node[i].node_pointer.left = NULL;
		tab_node[i].node_pointer.right = NULL;
		if (argv[i + 1][0] == '*' || argv[i + 1][0] == '+')
		{
			printf("%d\t%d\t%d\n", i, ft_find_left_node(argv, i), ft_find_right_node(argv, i, argc - 1));
			tab_node[i].value.oper = argv[i + 1][0];
			tab_node[i].node_pointer.left = &tab_node[i - 1];
			tab_node[i].node_pointer.right = &tab_node[i + 1];
		}
		else
		{
			tab_node[i].value.nb = atoi(argv[i + 1]);
			tab_node[i].node_pointer.left = NULL;
			tab_node[i].node_pointer.right = NULL;	
		}
		i++;
	}

	/*
	tab_node[0].value.nb = atoi(argv[1]);
	tab_node[0].node_pointer.left = NULL;
	tab_node[0].node_pointer.right = NULL;

	tab_node[2].value.nb = atoi(argv[3]);
	tab_node[2].node_pointer.left = NULL;
	tab_node[2].node_pointer.right = NULL;

	tab_node[4].value.nb = atoi(argv[5]);
	tab_node[4].node_pointer.left = NULL;
	tab_node[4].node_pointer.right = NULL;

	tab_node[1].node_pointer.left = &tab_node[0];
	tab_node[1].node_pointer.right = &tab_node[2];
	tab_node[1].value.oper = argv[2][0];

	tab_node[3].node_pointer.left = &tab_node[1];
	tab_node[3].node_pointer.right = &tab_node[4];
	tab_node[3].value.oper = argv[4][0];

	
	ft_print_tree(tab_node, 0);
	printf("\n");
	*/

	/*
	printf("%d\t", tab_node[1].node_pointer.left->value.nb);
	printf("%c\t", tab_node[1].value.oper);
	printf("%d\t", tab_node[1].node_pointer.right->value.nb);
	printf("%c\t", tab_node[3].value.oper);
	printf("%d\n", tab_node[3].node_pointer.right->value.nb);
	*/

	printf("!%c!\n", tab_node[1].value.oper);
	printf("|%c|\n", tab_node[3].node_pointer.left->value.oper);
	printf("%p\n", tab_node[3].node_pointer.left);
	//printf("%d\n", tab_node[3].node_pointer.left->node_pointer.left->value.nb);

}
