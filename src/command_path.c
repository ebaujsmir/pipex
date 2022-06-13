/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:59:35 by esmirnov          #+#    #+#             */
/*   Updated: 2022/06/08 18:30:26 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*command_path(t_data *data)
{
	char	*cmd_path;
	int		i;

	if (data->path_tab != NULL)
	{
		i = 0;
		while (data->path_tab[i])
		{
			cmd_path = ft_strjoin(data->path_tab[i], data->av_cmd[0]);
			if (access(cmd_path, F_OK) == 0 && ft_strchr(cmd_path, '/') != NULL)
				return (cmd_path);
			free(cmd_path);
			i++;
		}
	}
	if (access(data->av_cmd[0], X_OK) == 0
		&& ft_strchr(data->av_cmd[0], '/') != NULL)
		return (data->av_cmd[0]);
	ft_av_cmd_error_msg_check(data);
	ft_free_close(data);
	exit(EXIT_FAILURE);
	return (NULL);
}

void	ft_av_cmd_error_msg_check(t_data *data)
{
	if (ft_strchr(data->av_cmd[0], '/') != NULL)
		ft_msg_perror(data->av_cmd[0]);
	else
	{
		ft_msg_error(data->av_cmd[0]);
		ft_putstr_fd(": command not found\n", 2);
	}
}
