/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:36:33 by esmirnov          #+#    #+#             */
/*   Updated: 2022/06/08 18:30:45 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_data
{
	int			fd1;
	int			fd2;
	int			pipefd[2];
	pid_t		pid1;
	pid_t		pid2;
	char		*path;
	char		**path_tab;
	char		**av_cmd;
	char		*cmd;
}				t_data;

void	ft_init_data(int ac, char **av, t_data *data);
void	pipex(char **av, char **envp, t_data *data);
void	child_1(char **av, char **envp, t_data *data);
void	child_2(char **av, char **envp, t_data *data);
void	ft_path_tab(char **envp, t_data *data);
void	ft_path(char **envp, t_data *data);
void	ft_msg_perror(char *str);
void	ft_msg_error(char *str);
void	ft_msg_perror_free_close_exit(char *str, t_data *data);
void	ft_free(t_data *data);
void	ft_free_tab(char **tab);
void	ft_close_files(t_data *data);
void	ft_close_pipe(t_data *data);
void	ft_free_close(t_data *data);
char	**ft_split_pipex(char const *s, char c);
char	*command_path(t_data *data);
void	ft_av_cmd_error_msg_check(t_data *data);

#endif
