#include <fctrl.h>

void	ft_word_count(char *str, char *charset)
{
	char *filename;
	int fd;
	size_t size = 1024;

	fd = open(filename,O_RDONLY);
	if (fd == -1)
		return ;
	read(fd, buff, size)
}


int (*f)(int, int);

O_RDONLY, O_WRONLY, O_RDWR, O_CREAT, O_TRUNC