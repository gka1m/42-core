#include <unistd.h>

char alpha_mirror(char c)
{
	if (c >= 'A' && c <= 'Z')
		return ('Z' - (c - 'A'));
	if (c >= 'a' && c <= 'z')
		return ('z' - (c - 'a'));
	return c;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}

	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		char mirrored = alpha_mirror(argv[1][i]);
		write(1, &mirrored, 1);
	}
	write(1, "\n", 1);
	return 0;
}