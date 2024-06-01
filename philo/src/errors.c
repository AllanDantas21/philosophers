/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:55:31 by aldantas          #+#    #+#             */
/*   Updated: 2024/06/01 19:28:54 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	print_error(int ac)
{
	if (ac < 5)
		write(2, RED"too few arguments\n"RESET, 30);
	else if (ac > 6)
		write(2, RED"too more arguments\n"RESET, 30);
}
