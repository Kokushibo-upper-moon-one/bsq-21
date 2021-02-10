#include "BSQ.h"

int         check_chars(char *argv)//проверка символов
{
    int i;
    int r;
    int fd;
    int sf;
    char *buf;
    char v;
    char o;
    char p;

    i = 0;
    r = 0;
    v = ft_get_char_void(argv);
    o = ft_get_char_obst(argv);
    p = ft_get_char_full(argv);
    sf = ft_size_file(argv);
    fd = open(argv, O_RDONLY);
    ft_get_second_line(fd);
    if ((buf = malloc(sf * sizeof(char))) == NULL)
            return (0);
    while ((r = read(fd, buf, sf)))
            buf[ret] = '\0';
    while (buf[i])
        {
            if (buf[i] != v && buf[i] != o && buf[i] != '\n')
                return (1);
            i++;
        }
    close(fd);
    free(buf);
    return (0);
}

int             get_next_columns(char *argv, int fd)//получение след столбцов
{
    char *buf;
    int j;
    int sf;

    j = 0;
    sf = ft_size_file(argv);
    if ((buf = malloc(sf * sizeof(char))) == NULL)
        return (0);
    while (read(fd, &buf[j], 1))
    {
        if (buf[j] == '\n')
             break;
        j++;
    }
   free (buf);
   return (j + 1);
}

int         check_columns(char *argv)//проверка столбцов
{
    int i;
    int fd;
    int j;
    int c;
    int l;

    i = 0;
    j = 0;
    c = ft_get_number_columns(argv);
    l = ft_get_number_lines(argv);
    fd = open(argv, O_RDONLY);
    ft_get_second_line(fd);
    while (i < l)
    {
        j = ft_get_next_columns(argv, fd);
        if (j != c)
            return (1);
        i++;
    }
    close(fd);
    return (0);
}

int         check_returns(char *argv)//проверка возврата
{
    char *buf;
    int i;
    int fd;
    int sf;
    int r;
    int c;

    i = 0;
    r = 0;
    c = ft_get_number_columns(argv);
    sf = ft_size_file(argv);
    fd = open(argv, O_RDONLY);
    ft_get_second_line(fd);
    if ((buf = malloc(sf * sizeof(char))) == NULL)
        return (0);
    while ((r = read(fd, buf, c)))
    {
        if (buf[r - 1] != '\n')
            return (1);
    }
    free(buf);
    close(fd);
    return (0);
}
int        check_map(char *argv)
{
    if (ft_get_number_columns(argv) < 1 || ft_get_number_lines(argv) < 1)
    {
            ft_putstr("map error\n");
            return (1);
    }
    if (ft_verif_chars(argv) == 1 || ft_verif_returns(argv) == 1)
    {
            ft_putstr("map error\n");
            return (1);
    }
    if (ft_verif_columns(argv) == 1)
    {
            ft_putstr("map error\n");
            return (1);
    }
    return (0);
}
