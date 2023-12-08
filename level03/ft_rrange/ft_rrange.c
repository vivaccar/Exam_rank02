/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:43:03 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/05 20:51:33 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	*range;
	int	i = 0;
	int	signal = 1;
	int	size = end - start;

	if (size < 0)
		size = -size;
	size++;
	range = (int *)malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	if (start < end)
		signal = -1;
	while (i < size)
	{
		range[i] = end;
		end = end + signal;
		i++;
	}
	return (range);
}