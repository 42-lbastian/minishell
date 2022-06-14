#include <stdio.h>
#include <stdlib.h>

typedef struct s_node t_node;

typedef struct	s_node_pointer
{
	char oper;
	t_node	*left;
	t_node	*right;

}				t_node_pointer;

typedef union	u_node_value
{
	int	nb;
	t_node_pointer node_pointer;
}				t_union_node;

struct	s_node
{
	t_union_node value;
};


int main(int argc, char **argv)
{
	t_node *tab_node;
	
	tab_node = malloc(sizeof(t_node) * 5);

	tab_node[0].value.nb = atoi(argv[1]);
	tab_node[2].value.nb = atoi(argv[3]);
	tab_node[4].value.nb = atoi(argv[5]);

	tab_node[1].value.node_pointer.left = &tab_node[0];
	tab_node[1].value.node_pointer.right = &tab_node[2];
	tab_node[1].value.node_pointer.oper = argv[2][0];

	tab_node[3].value.node_pointer.left = &tab_node[1];
	tab_node[3].value.node_pointer.right = &tab_node[4];
	tab_node[3].value.node_pointer.oper = argv[4][0];

	printf("%d\t", tab_node[1].value.node_pointer.left->value.nb);
	printf("%c\t", tab_node[1].value.node_pointer.oper);
	printf("%d\t", tab_node[1].value.node_pointer.right->value.nb);
	printf("%c\t", tab_node[3].value.node_pointer.oper);
	printf("%d\n", tab_node[3].value.node_pointer.right->value.nb);

	printf("%d\n", tab_node[3].value.node_pointer.left->value.node_pointer.left->value.nb);
}
