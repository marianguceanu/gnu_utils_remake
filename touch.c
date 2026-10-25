#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	if (argc == 1)
	{
		printf("Usage: touch [path]...\n");
		return 0;
	}

	FILE** stream = malloc((argc - 1) * sizeof(FILE));

	for (int i = 1; i < argc ; ++i) 
	{
		const char* path = argv[i];
		errno_t fp = fopen_s(&stream[i - 1], path, "w");
		fclose(stream[i - 1]);
	}

	free(stream);

	return 0;
}
