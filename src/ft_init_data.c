/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:14:47 by esmirnov          #+#    #+#             */
/*   Updated: 2022/06/08 15:27:34 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_data(int ac, char **av, t_data *data)
{
	data->fd1 = open(av[1], O_RDONLY);
	if (data->fd1 == -1)
		ft_msg_perror(av[1]);
	data->fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd2 == -1)
	{
		ft_msg_perror(av[ac - 1]);
	}
	data->pid1 = -1;
	data->pid2 = -1;
	data->path = NULL;
	data->path_tab = NULL;
	data->av_cmd = NULL;
	data->cmd = NULL;
}
