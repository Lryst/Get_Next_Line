#include "get_next_line.h"


int main()
{
	int fd;
	char *line;

    fd = open("./bonjour.txt", O_RDONLY);
    printf("FD : %d\n", fd);
	printf("GET NEXT LINE : %d\n", get_next_line(fd, &line));
	printf("LINE : %s\n", line); 
    close(fd);
    return (0);
}