#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
    int fd;
	int ret;
	char *line;

	line = NULL;
	fd = open("./bonjour.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%d->%s\n", ret, line);
	}
	printf("ret final : %d\n", ret);
    return (0);   
}
