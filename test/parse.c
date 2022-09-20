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
	char	*cmd;
	char	oper;
}				t_union_node;

struct	s_node
{
	t_union_node value;
	t_node_pointer node_pointer;
};

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;

t_list	*ft_lst_init(char *str)
{
	t_list *lst;

	lst = malloc(sizeof(t_list));
	lst->content = str;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lst_last(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lst_add_back(t_list **lst, t_list *lst_new)
{
	if (lst && (*lst))
		ft_lst_last((*lst))->next = lst_new;
	else
		(*lst) = lst_new;
}

int		ft_lst_size(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s\t", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

/*
int	ft_print_tree(t_node *node)
{
	int value;
	int value2;

	value = 0;
	value2 = 0;
	if (node->node_pointer.left)
		value = ft_print_tree(node->node_pointer.left);
	if (node->node_pointer.right)
		value2 = ft_print_tree(node->node_pointer.right);
	if (node->node_pointer.right)
	{
		if (node->value.oper == '*')
			return (value * value2);
		if (node->value.oper == '+')
			return (value + value2);
	}
	else
		return (node->value.nb);
}*/

int	ft_find_left_node_add(char **str, int index)
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

int	ft_find_left_node_mult(char **str, int index)
{
	int i;

	i = index - 1;
	while (i > 0)
	{
		if (str[i][0] == '+')
			return (index - 1);
		else if (str[i][0] == '*')
			break;
		i--;
	}
	return (i);
}

int	ft_find_right_node(char **str, int index)
{
	int i;

	i = index + 1;
	while (str[i])
	{
		if (str[i][0] == '*')
			return (i);
		if (str[i][0] == '+')
			return (index + 1);
		i++;
	}
	return (i - 1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (i < ft_strlen(str1) || i < ft_strlen(str2))
		return (1);
	return (0);
}

t_node	*ft_create_tree(char **token, t_node *tab_node)
{
	int i;

	i = 0;
	while (token[i])
	{
		if (ft_strcmp(token[i], "|") == 0)
		{}
		else if (ft_strcmp(token[i], "<") == 0)
		{}
		else if (ft_strcmp(token[i], ">") == 0)
		{}
		else if (ft_strcmp(token[i], ">>") == 0)
		{}
		else if (ft_strcmp(token[i], "<<") == 0)
		{}
		else
		{
			tab_node[i].node_pointer.right = NULL;
			tab_node[i].node_pointer.left = NULL;
			tab_node[i].value.cmd = token[i];
		}
		i++;
	}
	return (tab_node);
}

int ft_find_root(char **token)
{
	int	i;
	int	last_node;
	int	found_add;

	i = 0;
	last_node = 0;
	found_add = 0;
	while (token[i])
	{
		if (token[i][0] == '*')
		{
			if (found_add == 0)
				if (last_node == 0)
					last_node = i;
		}
		if (token[i][0] == '+')
		{
			if (found_add == 0)
			{
				found_add = 1;
				last_node = i;
			}
		}
		i++;
	}
	return (last_node);
}

int main(int argc, char **argv)
{
	int i;
	t_node *tab_node;
	t_list	*lst;
	char	**token;
	int size;

	lst = NULL;
	i = 1;
	tab_node = malloc(sizeof(t_node) * argc - 1);

	while (i < argc)
	{
		ft_lst_add_back(&lst, ft_lst_init(argv[i]));
		i++;
	}
	ft_print_lst(lst);
	size = ft_lst_size(lst);
	i = 0;
	token = malloc(sizeof(char *) * (size + 1));
	token[size] = NULL;
	while (i < size)
	{
		token[i] = lst->content;
		lst = lst->next;
		i++;
	}

//	tab_node = ft_create_tree(token, tab_node);

//	printf("%d-%d\n", tab_node[1].node_pointer.right->node_pointer.right->value.nb, tab_node[1].node_pointer.right->node_pointer.left->value.nb);

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

	*/

//	printf("%d-%p\n", tab_node[4].value.nb, tab_node[4].node_pointer.right);
//	printf("|%c|\n", tab_node[3].node_pointer.left->value.oper);
//	printf("%d-%d\n", tab_node[3].node_pointer.left->value.nb, tab_node[3].node_pointer.right->value.nb);
//	printf("%p-%p\n", tab_node[3].node_pointer.left->node_pointer.left, tab_node[3].node_pointer.right->node_pointer.right);
	
//	printf("Root? %d\n", ft_find_root(token));
//	printf("%d\n", ft_print_tree(&tab_node[ft_find_root(token)]));
//	printf("%d\n", ft_print_tree(&tab_node[1]));


	//printf("%p\t%p\n", tab_node[1].node_pointer.left, tab_node[1].node_pointer.right);

	//printf("|%d|\n", tab_node[2].value.nb);
//	printf("%d\n", tab_node[1].node_pointer.left->value.nb);
//	printf("%c-%d-%d\n", tab_node[3].node_pointer.left->value.oper, tab_node[3].node_pointer.left->node_pointer.left->value.nb, tab_node[3].node_pointer.left->node_pointer.right->value.nb);

//	printf("%d\t", tab_node[1].node_pointer.left->value.nb);

	/*
	printf("%d\t", tab_node[1].node_pointer.left->value.nb);
	printf("%c\t", tab_node[1].value.oper);
	printf("%d\t", tab_node[1].node_pointer.right->value.nb);
	printf("%c\t", tab_node[3].value.oper);
	printf("%d\n", tab_node[3].node_pointer.right->value.nb);
	*/

	//printf("!%c!\n", tab_node[1].value.oper);
//	printf("|%c|\n", tab_node[3].node_pointer.left->value.oper);
//	printf("%p\n", tab_node[3].node_pointer.left);
//	printf("%d\n", tab_node[3].node_pointer.left->node_pointer.left->value.nb);

}

	
		
			
				
					
						
							
								
