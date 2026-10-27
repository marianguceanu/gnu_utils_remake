#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc == 1)
	{
		printf("Usage: cat [path]...\n");
	}

	FILE* fileStream = (FILE*)malloc(sizeof(FILE));

	for (int i = 1; i < argc ; ++i) 
	{
		fileStream = fopen(argv[i], "r");

		if(fileStream == NULL)
		{
			fprintf(stderr, "Could not read file %s", argv[i]);
			free(fileStream);
			return -1;
		}
		char line[50];
		while (fgets(line, 50, fileStream) != NULL)
		{
			printf("%s", line);
		}

		fclose(fileStream);
	}

	return 0;
}
