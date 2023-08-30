#include <unistd.h>
#include <stdlib.h>

char *extend_and_copy(char *old_buffer, int old_size, int new_size)
{
	char *new_buffer = (char *)malloc(new_size);
	if (new_buffer == NULL)
	{
		return NULL;
	}
	
	int i = 0;
	while (i < old_size)
	{
		new_buffer[i] = old_buffer[i];
		i++;
	}
	
	free(old_buffer);
	return new_buffer;
}

char *read_input(int fd, int buffer_size)
{
	int ret;
	int index = 0;
	char *input_buffer;
	char tmp;
	
	input_buffer = (char *)malloc(buffer_size);
	if (input_buffer == NULL)
		return NULL;
	while ((ret = read(STDIN_FILENO, &tmp, 1)) > 0)
	{
		if (tmp == '\n')
			break;
		input_buffer[index] = tmp;
		index++;
		if (index >= buffer_size)
		{
			buffer_size *= 2;
			input_buffer = extend_and_copy(input_buffer, index, buffer_size);
			if (input_buffer == NULL)
				return NULL;
		}
	}
	if (ret < 0)
	{
		free(input_buffer);
		return NULL;
	}
	input_buffer[index] = '\0';
	return input_buffer;
}