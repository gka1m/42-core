/*
Assignment: get_next_line
Expected files: get_next_line.c, get_next_line.h
Allowed functions: read, malloc, free

Prototype: char	  *get_next_line(int fd);

Your function must return a line that has been read from the file descriptor passed as parameter.
What we call a "line that has been read" is a succesion of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).
The line should be returned including the '\n' in case there is one at the end of the line that has been read.

BUFFER
When you've reached the EOF, you must store the current buffer in a char * and return it.

NULL

If the buffer is empty you must return NULL.
In case of error return NULL.
In case of not returning NULL, the pointer should be free-able.

MEMORY
Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.
Your function must be memory leak free.
When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

FUNCTION
Calling your function get_next_line in a loop will therefore allow you to read the text avaiable on a file descriptor one line at a time until the end of the text, no matter the size or either the text or one of its lines.
Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...
No call to another function will be done on the file descriptor between 2 calls of get_next_line.

FILE
Finally we consider that get_next_line has an undefined behaviour when reading from a binary file.
*/

#include "get_next_line.h"

char *ft_strdup(char *str)
{
	char *result;
	int len = 0;
	int i = 0;

	if (str == NULL)
		return NULL;
	for (i = 0; str[i] != '\0'; i++)
		len++;
	i = 0;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return NULL;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return result;
}

 char *get_next_line(int fd)
 {
	static char buffer[BUFFER_SIZE];
	char line[100000];
	static int readed;
	static int posn;
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	
	while (1)
	{
		if (posn >= readed)
		{
			readed = read(fd, buffer, BUFFER_SIZE);
			posn = 0;
			if (readed <= 0)
				break;
		}
		if (line[i] == '\n')
			break;
		line[i] = buffer[posn++];
		i++;
	}
	line[i] = '\0';
	if (i == 0)
		return NULL;
	return (ft_strdup(line)); 
 }