#include "get_next_line.h"

int main()
{
    int fd;

    fd = open("bonjour", O_RDONLY);
    ft_putnbr(fd);
    ft_putchar('\n');
    close(fd);
    return (0);
}