/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:27:09 by esmirnov          #+#    #+#             */
/*   Updated: 2022/06/08 12:50:50 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(t_data *data)
{
	ft_free_tab(data->path_tab);
	ft_free_tab(data->av_cmd);
	if (data->cmd != NULL)
		free (data->cmd);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			free (tab[i]);
			i++;
		}
		free (tab);
	}
}

void	ft_close_files(t_data *data)
{
	close(data->fd1);
	close(data->fd2);
}

void	ft_close_pipe(t_data *data)
{
	close (data->pipefd[0]);
	close (data->pipefd[1]);
}

void	ft_free_close(t_data *data)
{
	ft_free(data);
	ft_close_files(data);
}
