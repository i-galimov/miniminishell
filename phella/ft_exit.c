// #include "buildin.h"


// int	check_arg(char *arg)
// {
// 	int			i;
// 	long long	exit_code;
// 	int	g_ex_status = 0;
	
// 	g_ex_status = 0;
// 	i = 0;
// 	while (ft_isspace(arg[i]))
// 		i++;
// 	if (arg[i] && (arg[i] == '+' || arg[i] == '-'))
// 		i++;
// 	if (ft_isalldigit(arg + 1) == 0 || ft_isllong(arg) != 0)
// 	{
// 		ft_putendl_fd("minishell: exit : ", 2);
// 		ft_putendl_fd(arg, 2);
// 		ft_putendl_fd(": numeric argument required\n", 2);
// 		g_ex_status = 255;
// 		return (1);
// 	}
// 	exit_code = ft_atoll(arg);
// 	g_ex_status = exit_code % 256;
// 	if (g_ex_status < 0 || g_ex_status > 255)
// 		g_ex_status = 255;
// 	return (0);
// }

// void	ft_exit(char **arg)
// {
// 	int	i;

// 	i = 0;
// 	ft_putendl_fd("exit\n", 2);
// 	if (arg[0])
// 	{
// 		i = check_arg(arg[0]);
// 		if (arg[1] && i == 0)
// 		{
// 			ft_putendl_fd("minishell: exit: too many arguments\n", 2);
// 			g_ex_status = 1;
// 			return ;
// 		}
// 	}
// 	exit(g_ex_status);
// }

// int	ft_isllong(char *str)
// {
// 	if (str[0] == '-' && ft_strlen(str) >= 20
// 		&& ft_strcmp(&str[1], "9223372036854775808") > 0)
// 		return (1);
// 	else if (ft_strlen(str) >= 19
// 		&& ft_strcmp(str, "9223372036854775807") > 0)
// 		return (1);
// 	return (0);
// }

// long long	ft_atoll(const char *nptr)
// {
// 	long long	num;
// 	int			sign;
// 	int			i;

// 	i = 0;
// 	sign = 1;
// 	num = 0;
// 	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
// 		nptr++;
// 	if (nptr[i] == '-')
// 		sign = sign * -1;
// 	if (nptr[i] == '+' || nptr[i] == '-')
// 		nptr++;
// 	while (nptr[i] >= '0' && nptr[i] <= '9')
// 	{
// 		num = (num * 10) + nptr[i] - '0';
// 		nptr++;
// 	}
// 	return (num * sign);
// }
