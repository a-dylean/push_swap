#include "push_swap.h"

void ft_errors_check(int argc, char **argv)
{
    if (argc == 1)
        exit(0);
    ft_char_check(argc, argv);
    ft_intsize_check(argc, argv);
}

void ft_char_check(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == '\0')
            print_error_and_exit();
        while (j < ft_strlen(argv[i]))
        {
            if (!ft_isdigit(argv[i][j]))
            {
                if (j == 0 && ft_strlen(argv[i]) != 1 && \
					(argv[i][j] == '-' || argv[i][j] == '+'))
				{
					j++;
					continue ;
				}
                print_error_and_exit();
            }
            j++;
        }
        i++;
    }
}
void	ft_intsize_check(int argc, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (i < argc)
	{
        //check if atoi works with long, maybe changes might be required
		num = ft_atoi(argv[i]);
		if (num > INTMAX || num < INTMIN)
			print_error_and_exit();
		i++;
	}
}

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
