/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:55:31 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/23 23:21:01 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	print_error(int ac)
{
	if (ac < 5)
		write(2, "too few arguments\n", 18);
	else if (ac > 6)
		write(2, "too more arguments\n", 19);
}