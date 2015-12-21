/*
* Parser
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

#include "readstd.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ_STD_BUFFER_SIZE 1024

char *readFromStdin(void)
{
	char buffer[READ_STD_BUFFER_SIZE];
	size_t contentSize = 1;

	char *content = malloc(sizeof(char) * READ_STD_BUFFER_SIZE);
	if(content == NULL)
	{
		fprintf(stderr, "FATAL ERROR: failed to allocate memory\n");
		exit(-1);
	}
	content[0] = '\0';
	while(fgets(buffer, READ_STD_BUFFER_SIZE, stdin))
	{
		char *old = content;
		contentSize += strlen(buffer);
		content = realloc(content, contentSize);
		if(content == NULL)
		{
			fprintf(stderr, "FATAL ERROR: failed to allocate memory\n");
			free(old);
			exit(-1);
		}
		strcat(content, buffer);
	}

	if(ferror(stdin))
	{
		free(content);
		fprintf(stderr, "Input error while reading from stdin\n");
		exit(-1);
	}
	return content;
}

