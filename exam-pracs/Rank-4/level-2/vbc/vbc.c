#include "vbc.h"

node *new(node n)
{
    node *r = calloc(1, sizeof(node));
    if (!r)
        return NULL;
    *r = n;
    return r;
}

void unexpected_err(char c)
{
    if (c)
        printf("Unexpected token %c\n", c);
    else
        printf("Unexpected EOF encountered\n");
}

int valid_input(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return 1;
    }
    return 0;
}

int expected(char **s, char c)
{
    if (valid_input(s, c))
        return 1;
    unexpected_err(**s);
    return 0;
}

int evaluation_tree(node *tree)
{
    switch(tree->type)
    {
        case ADD:
            return (evaluation_tree(tree->left) + evaluation_tree(tree->right));
        case MULTIPLY:
            return (evaluation_tree(tree->left) * evaluation_tree(tree->right));
        case VALUE:
            return tree->val;
    }
    return 0;
}

void free_tree(node *tree)
{
    if (tree)
    {
        if (tree->type != VALUE)
        {
            free_tree(tree->left);
            free_tree(tree->right);
        }
        free(tree);
    }
}

node *parse_add(char **s)
{
    node *left = parse_mult(s);
    while (valid_input(s, '+'))
    {
        node *right = parse_mult(s);
        if (!right)
        {
            free_tree(left);
            return NULL;
        }
        node n = {ADD, 0, left, right};
        left = new(n);
    }
    return left;
}

node *parse_mult(char **s)
{
    node *left = parse_paren(s);
    while (valid_input(s, '*'))
    {
        node *right = parse_paren(s);
        if (!right)
        {
            free_tree(left);
            return NULL;
        }
        node n = {MULTIPLY, 0, left, right};
        left = new(n);
    }
    return left;
}

node *parse_paren(char **s)
{
    if (valid_input(s, '('))
    {
        node *n = parse_add(s);
        if (!expected(s, ')'))
        {
            free_tree(n);
            return NULL;
        }
        return n;
    }
    if (isdigit(**s))
    {
        node n = {VALUE, **s - '0', NULL, NULL};
        (*s)++;
        return (new(n));
    }
    unexpected_err(**s);
    return NULL;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    char *input = av[1];
    node *tree = parse_add(&input);
    if (!tree)
        return 1;
    else if (*input)
    {
        unexpected_err(*input);
        free_tree(tree);
        return 1;
    }
    printf("%d\n", evaluation_tree(tree));
    free_tree(tree);
    return 0;
}