/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:34:08 by esmirnov          #+#    #+#             */
/*   Updated: 2022/06/08 12:25:51 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_msg_perror(char *str)
{
	ft_putstr_fd("Error: ", 2);
	perror(str);
}

void	ft_msg_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
}

void	ft_msg_perror_free_close_exit(char *str, t_data *data)
{
	ft_free_close(data);
	ft_msg_perror(str);
	exit(EXIT_FAILURE);
}
