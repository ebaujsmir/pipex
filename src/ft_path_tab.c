/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:28:44 by esmirnov          #+#    #+#             */
/*   Updated: 2022/06/08 15:48:31 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_path(char **envp, t_data *data)
{
	if (*envp)
	{
		while (envp)
		{		
			if (ft_strncmp(*envp, "PATH=", 5) == 0)
				break ;
			envp++;
		}
		data->path = *envp + 5;
	}
}

void	ft_path_tab(char **envp, t_data *data)
{
	char	*path_tmp;
	char	**path_tab;
	int		i;

	ft_path(envp, data);
	path_tmp = data->path;
	if (data->path != NULL)
	{
		path_tab = ft_split_pipex((char const *)path_tmp, ':');
		i = 0;
		while (path_tab[i])
		{
			if (path_tab[i][0] != '\0')
			{
				path_tmp = ft_strjoin(path_tab[i], "/");
				free (path_tab[i]);
				path_tab[i] = path_tmp;
			}
			i++;
		}
		data->path_tab = path_tab;
	}
}
