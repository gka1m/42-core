/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdio.h>
#include <stdlib.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;
	while (i < n && s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return s1;
}

int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return count;
}

char **make_arr(int wordcount)
{
	char **result = malloc((wordcount + 1) * sizeof(char *));
	if (!result)
		return NULL;
	return result;
}

void split_str(char *str, char **result, int wordcount)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (str[i])
	{
		// skip whitespace characters
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		// mark start of current word
		j = i;
		// iterate through current word
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		// if current word not empty, add to result array
		if (i > j)
		{
			result[k] = malloc((i - j + 1) * sizeof(char));
			ft_strncpy(result[k], &str[j], i - j);
			k++;
		}
	}
	result[k] = NULL;
}

char **ft_split(char *str)
{
	int wordcount = count_words(str);
	char **out = make_arr(wordcount);
	if (out == NULL)
		return NULL;
	split_str(str, out, wordcount);
	return out;
}

// int main(void) 
// {
//     char *str = "hello world   this   is   a   test";
//     char **words = ft_split(str);

//     if (words == NULL) {
//         printf("Error: ft_split returned NULL\n");
//         return 1;
//     }

//     int i = 0;
//     while (words[i] != NULL) {
//         printf("Word %d: %s\n", i, words[i]);
//         i++;
//     }

//     // Don't forget to free the allocated memory!
//     for (i = 0; words[i] != NULL; i++) {
//         free(words[i]);
//     }
//     free(words);

//     return 0;
// }