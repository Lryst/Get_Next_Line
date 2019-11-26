#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
    int fd;
	static char *line = NULL;

	fd = open("./bonjour.txt", O_RDONLY);
		printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;
		printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;
		printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;
		printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;
		printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;printf("resultat : \n|%D|   ", get_next_line(fd, &line));
		printf("LINE : %s\n", line);
		free(line);
		line = NULL;
    return (0);   
}
