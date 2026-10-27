#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Usage: touch [path]...\n");
		return 0;
	}

	FILE* file = (FILE*)malloc(sizeof(FILE));

	for (int i = 1; i < argc ; ++i) 
	{
		file = fopen(argv[i], "w");

		if(file == NULL)
		{
			fprintf(stderr, "Could not create file");
			free(file);
			return -1;
		}

		fclose(file);
	}

	return 0;
}
