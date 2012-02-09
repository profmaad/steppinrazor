# include <stdio.h>
# include <errno.h>
# include <string.h>

# include "java_class.h"

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage: %s <.class file>\n", argv[0]);
		return 1;
	}

	const char *input_filename = argv[1];

	FILE *input = fopen(input_filename, "rb");
	if(!input)
	{
		fprintf(stderr, "Failed to open class file: %s\n", strerror(errno));
		return 1;
	}

	const java_class *class = load_class(input);
	if(!class)
	{
		fprintf(stderr, "Failed to load class\n");
		return 2;
	}
	
	return 0;
}
