/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:56:58 by vivaccar          #+#    #+#             */
/*   Updated: 2023/11/27 13:13:54 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int	start;
		int end;
		int	i = 0;
		int	flag = 0;
		
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		start = i;
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
			i++;
		end = i;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			while ((argv[1][i] == ' ' && argv[1][i + 1] == ' ') || (argv[1][i] == '\t' && argv[1][i + 1] == '\t'))
				i++;
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flag = 1;
			if (!((argv[1][i] == ' ') && (argv[1][i + 1] == '\0')))
				write (1, &argv[1][i], 1);
			i++;
		}
		if (flag == 1)
			write (1, " ", 1);
		while (start < end)
		{
			write (1, &argv[1][start], 1);
			start++;
		}
	}
	write (1, "\n", 1);
}