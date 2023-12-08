/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:49:21 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/02 21:25:34 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_repeat(char *argv1, char c, int j)
{
	int	i = 0;
	int	count = 0;
	
	while (argv1[i] && i <= j)
	{
		if (argv1[i] == c)
			count++;
		if (count == 2)
			return (0);
		i++;
	}
	return (1);
}

int	check_digit(char *argv2, char c)
{
	int	i = 0;

	while (argv2[i])
	{
		if (argv2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int i = 0;
	
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (check_digit(argv[2], argv[1][i]))
			{
				if (check_repeat(argv[1], argv[1][i], i))
					write (1, &argv[1][i], 1);
			}
		i++;
		}
	}
	write (1, "\n", 1);
}