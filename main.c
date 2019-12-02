#include "get_next_line.h"

int		main()
{
    int fd;
	static char *line = NULL;
	int res;

	fd = open("/Users/lulu/Lryst/Get_Next_Line/42TESTERS-GNL/results/result2.txt", O_RDONLY);
    while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("resultat : |%d| -> %s \n", res, line);
		free(line);
		line = NULL;
	}
	printf("resultat : |%d| -> %s \n", res, line);

   // system("leaks a.out");

    return (0);
}