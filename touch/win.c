// TODO - check for the needed libs on windows as well
#include <cstdlib>
#include <stdio.h>

int main(int argc, char** argv)
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
		/* Here I should include the code that checks if the file has been opened succesfully*/

		fclose(stream[i - 1]);
	}

	free(stream);
	return 0;
}
