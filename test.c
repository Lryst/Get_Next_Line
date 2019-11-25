

void ft_increment(char **i)
{
    *i = "cul";
}

int main()
{
    char *i;

    i = "bonjour";
    ft_increment(&i);
    printf("%s\n", i);
}