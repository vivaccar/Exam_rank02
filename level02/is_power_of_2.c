/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:56:38 by vivaccar          #+#    #+#             */
/*   Updated: 2023/11/30 13:05:48 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	    is_power_of_2(unsigned int n)
{
	unsigned long int	i;

	i = 1;
	while (i <= n)
	{
		if (i == n)
			return (1);
		i *= 2;
	}
	return(0);
}
/* #include <stdio.h>

int	main(int argc, char *argv[])
{
	int r = is_power_of_2(1024);
	printf("%i", r);
} */