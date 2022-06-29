/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:40:28 by esmirnov          #+#    #+#             */
/*   Updated: 2022/06/26 22:38:48 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **av, char **envp, t_data *data)
{
	data->pid1 = fork();
	if (data->pid1 < 0)
		ft_msg_perror_free_close_exit("fork failed ", data);
	if (data->pid1 == 0)
		child_1(av, envp, data);
	data->pid2 = fork();
	if (data->pid2 < 0)
		ft_msg_perror_free_close_exit("fork failed ", data);
	if (data->pid2 == 0)
		child_2(av, envp, data);
	ft_close_pipe(data);
	ft_free_close(data);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
}

void	child_1(char **av, char **envp, t_data *data)
{
	if (dup2(data->pipefd[1], STDOUT_FILENO) < 0)
		ft_msg_perror_free_close_exit("dup2 failed ", data);
	ft_close_pipe(data);
	if (data->fd1 == -1)
	{
		ft_free_close(data);
		exit(EXIT_FAILURE);
	}
	if (dup2(data->fd1, STDIN_FILENO) < 0)
		ft_msg_perror_free_close_exit("dup2 failed ", data);
	ft_close_files(data);
	data->av_cmd = ft_split(av[2], ' ');
	data->cmd = command_path(data);
	execve(data->cmd, data->av_cmd, envp);
	ft_msg_perror_free_close_exit("execve failed ", data);
}

void	child_2(char **av, char **envp, t_data *data)
{
	if (dup2(data->pipefd[0], STDIN_FILENO) < 0)
		ft_msg_perror_free_close_exit("dup2 failed ", data);
	ft_close_pipe(data);
	if (data->fd2 == -1)
	{
		ft_free_close(data);
		exit(EXIT_FAILURE);
	}
	if (dup2(data->fd2, STDOUT_FILENO) < 0)
		ft_msg_perror_free_close_exit("dup2 failed ", data);
	ft_close_files(data);
	data->av_cmd = ft_split(av[3], ' ');
	data->cmd = command_path(data);
	execve(data->cmd, data->av_cmd, envp);
	ft_msg_perror_free_close_exit("execve failed ", data);
}
