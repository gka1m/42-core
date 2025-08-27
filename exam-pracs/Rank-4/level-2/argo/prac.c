/* Assignment name: argo
Expected files: argo.c
Allowed functions: getc, ungetc, printf, malloc, calloc, realloc, free, isdigit, fscanf, write
-----------------
Write a function argo that will parse a json file in the structure declared in argo.h:

int	argo(json *dst, FILE *stream);

	dst	- is the pointer to the AST that you will create
	stream	- is the file to parse (man FILE)

Your function will return 1 for success and -1 for failure.
If an unexpected token is found you will print the following message in stdout: "Unexpected token '%c'\n"
or if the token is EOF: "Unexpected end of input\n"
Handle escaping in string only for backslashes and quotation marks.
You don't have to handle spaces in the input (so they should be considered as invalid tokens).

In case of doubt how to parse json, read rfc8259. But you won't need it as the format is simple. Tested with the main, the output should be exactly the same as the input (except for errors).
There are some functions in argo.c that might help you.

Examples that should work:

echo -n input | ./argo /dev/stdin | cat -e		output
------------------------------------------		--------------------------------------------
'1'							1$
'"bonjour"'						"bonjour"$
'"escape!\""'						"escape!\""$
'{"tomatoes":42,"potatoes":234}'		    	{"tomatoes":42,"potatoes":234}$
'{"recursion":{"recursion":{"recursion":"recursion"}}}'	{"recursion":{"recursion":{"recursion":"recursion"}}}$
'"unfinished string'					Unexpected end of input$
'"unfinished string 2\"'				Unexpected end of input$
'{"no value?":}'					Unexpected token '}'$
'{:12}'							Unexpected token ':'$ */

// note : argo.h and main.c are given in the exam to help with testing 

#include "argo.h"

// note : following functions are given in the exam
int	peek(FILE *stream)
{
	int	c = getc(stream);
	ungetc(c, stream);
	return c;
}

void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}
// end of given functions 

int int_parser(json *dst, FILE *stream)
{
    int n;
    if (fscanf(stream, "%d", &n) != 1)
    {
        unexpected(stream);
        return -1;
    }
    dst->type = INTEGER;
    dst->integer = n;
    return 1;
}

char *getstr(FILE *stream)
{
    if (!expect(stream, '"'))
        return NULL;
    
    char *res = calloc(4096, sizeof(char));
    if (!res)
        return NULL;
    int i = 0;
    while (1)
    {
        int c = getc(stream);
        if (c == EOF)
        {
            unexpected(stream);
            free(res);
            return -1;
        }
        if (c == '"')
            break;
        if (c == '\\')
        {
            c = getc(stream);
            if (c == EOF)
            {
                unexpected(stream);
                free(res);
                return -1;
            }
        }
        res[i++] = c;
    }
    res[i] = '\0';
    return res;
}

int map_parser(json *dst, FILE *stream)
{
    if (!expect(stream, '{'))
    {
        unexpected(stream);
        return -1;
    }
    dst->type = MAP;
    dst->map.size = 0;
    dst->map.data = NULL;

    if (accept(stream, '}'))
        return 1;

    while (1)
    {
        if (peek(stream) != '"')
        {
            unexpected(stream);
            return -1;
        }
        dst->map.data = realloc(dst->map.data, (dst->map.size + 1) * sizeof(pair));
        if (!dst->map.data)
            return -1;

        pair *current = &dst->map.data[dst->map.size];
        current->key = getstr(stream);
        if (!current->key)
            return -1;
        if (!expect(stream, ':'))
            return -1;
        if (argo(&current->value, stream) == -1)
            return -1;

        dst->map.size++;
        if (accept(stream, '}'))
            break;
        if (!except(stream, ','))
            return -1;
    }
    return 1;
}

int parser(json *dst, FILE *stream)
{
    int c = peek(stream);
    if (c == EOF)
    {
        unexpected(stream);
        return -1;
    }
    if (isdigit(c))
        return int_parser(dst, stream);
    else if (c == '"')
    {
        dst->type = STRING;
        dst->string = getstr(stream);
        if (!dst->string)
            return -1;
        return 1;
    }
    else if (c == '{')
        return map_parser(dst, stream);
    else
    {
        unexpected(stream);
        return -1;
    }
    return 1;
}

int argo(json *dst, FILE *stream)
{
    if (parser(dst, stream) == -1)
        return -1;
    return 1;
}