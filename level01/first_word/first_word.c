/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:43:29 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/02 20:47:52 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i = 0;
	
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t') 
			i++;
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
		{
			write (1, &argv[1][i], 1);
				i++;
		}	
	}
	write (1, "\n", 1);
}