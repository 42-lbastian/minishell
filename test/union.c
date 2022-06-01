#include <stdio.h>

typedef struct s_node t_node;

typedef struct	s_node_pointer
{
	t_node	*left;
	t_node	*right;

}				t_node_pointer;

typedef union	u_node_value
{
	char	c;
	t_node_pointer node_pointer;
}				t_union_node;

struct	s_node
{
	t_union_node value;
};


int main()
{
	t_node node_a;
	t_node node_b;
	t_node node_p;
	
	node_a.value.c = 'a';
	node_b.value.c = 'b';

	node_p.value.node_pointer.left = &node_a;
	node_p.value.node_pointer.right = &node_b;

	printf("%c\n", node_p.value.node_pointer.left)
}
