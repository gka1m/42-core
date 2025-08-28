/*allowed functions: malloc, calloc, realloc, free, printf, isdigit, write

program needs to print the result of a math expression.
handles * and + and parenthesis.
does not handle whitespace.
values are between 0 and 9.
if unexpected symbol OR unexpected '(' ')' -> print error and exit(1)
if symbol is at the end of input print error
if syscall failure exit(1)

./vbc '1'
1
./vbc '3*4+5'
17
./vbc '(3+4)*5'
35
./vbc '(((((((1)))))))'
1
./vbc '(((((2+2)*2+2)*2+2)*2+2)*2+2)*2'
188
./vbc '1+2+3+4+5'
15
./vbc '((1+3)*12+(3*(2+6)))'
unexpected token '2'*/

#include "vbc.h"

node	*new_node(node n)
{
	node *ret = calloc(1, sizeof(node));
	if (!ret)
		return NULL;
	*ret = n;
	return ret;
}

void	unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
}

int	accept(char **s, char c)
{
	if (**s == c)
	{
		(*s)++;
		return 1;
	}
	return 0;
}

int	expect(char **s, char c)
{
	if (accept(s, c))
		return 1;
	unexpected(**s);
		return 0;
}

int	eval_tree(node *tree)
{
	switch (tree->type)
	{
		case ADD:
			return (eval_tree(tree->l) + eval_tree(tree->r));
		case MULTI:
			return (eval_tree(tree->l) * eval_tree(tree->r));
		case VAL:
			return tree->val;
	}
	return 0;
}

void destroy_tree(node* tree)
{
    if (tree) {
        if (tree->type != VAL) {
            destroy_tree(tree->l);
            destroy_tree(tree->r);
        }
        free(tree);
    }
}
//end of given functions (remember to edit main)

node	*parse_expr(char **s)
{
	node *left = parse_term(s);
	while(accept(s, '+'))
	{
		node *right = parse_term(s);
		if(!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		node n = {ADD, 0, left, right};
		left = new_node(n);
	}
	return (left);
}


node	*parse_term(char **s)
{
	node *left = parse_factor(s);
	while(accept(s, '*'))
	{
		node *right = parse_factor(s);
		if(!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		node n = {MULTI, 0, left, right};
		left = new_node(n);
	}
	return (left);
}

node	*parse_factor(char **s)
{
	if(accept(s, '('))
	{
		node *n = parse_expr(s);
		if(!expect(s, ')'))
		{
			destroy_tree(n);
			return (NULL);
		}
		return (n);
	}
	if(isdigit(**s))
	{
		node n = {VAL, **s - '0', NULL, NULL};
		(*s)++;
		return (new_node(n));
	}
	unexpected(**s);
	return (NULL);
}
			
int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	char *input = av[1];
	node *tree = parse_expr(&input);
	if (!tree)
		return 1;
	else if(*input)
	{
		unexpected(*input);
		destroy_tree(tree);
		return (1);
	}
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
	return (0);	
}