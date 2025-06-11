#ifndef VBC_H
#define VBC_H

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    enum
    {
        ADD,
        MULTIPLY,
        VALUE
    } type;

    int val;
    struct node *left;
    struct node *right;
}   node;

node *new(node n);
void unexpected_err(char c);
int valid_input(char **s, char c);
int expected(char **s, char c);
int evaluation_tree(node *tree);
void free_tree(node *tree);
node *parse_add(char **s);
node *parse_mult(char **s);
node *parse_paren(char **s);

#endif
