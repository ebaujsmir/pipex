/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:31:16 by esmirnov          #+#    #+#             */
/*   Updated: 2022/06/08 16:16:26 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
	{
		ft_msg_error("ft_arg_check : invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	ft_init_data(ac, av, &data);
	ft_path_tab(envp, &data);
	if (pipe(data.pipefd) == -1)
		ft_msg_perror_free_close_exit("pipe failed ", &data);
	pipex(av, envp, &data);
	return (0);
}
