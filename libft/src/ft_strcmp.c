/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:58:02 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/04 19:58:28 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;
	
	i = 0;
	if(!s1 || !s2)
		return (0);
	while(s1[i] == s2[i])
	{
		if(s1[i] == 0 || s1[i] == 0)
			return (0);
		i++;
	}
	return (i);
}