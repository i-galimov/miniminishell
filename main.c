/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtire <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:47:12 by rtire             #+#    #+#             */
/*   Updated: 2022/05/20 18:47:20 by rtire            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//char	*command_buf;

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char	*command_buf;
//	printf("%d\n", )
	while (1)
	{
		command_buf = readline(BLUE"minishell> ");

		if (ft_strlen(command_buf) > 0)
			add_history(command_buf);
		if (!strcmp(command_buf, "ls"))
			system("ls");
		else if (!ft_strncmp(command_buf, "pwd", ft_strlen("pwd")))
			system("pwd");
		else if (!ft_strncmp(command_buf, "exit", ft_strlen("exit")))
			break ;
	}
	free(command_buf);
}
