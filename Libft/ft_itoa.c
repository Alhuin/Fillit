/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 23:19:20 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 23:19:20 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*ret;
	int				size;
	unsigned int	i;

	size = ft_intlen(n);
	if (!(ret = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ret[size] = '\0';
	if (n < 0)
	{
		i = -n;
		ret[0] = '-';
	}
	else
		i = n;
	if (i == 0)
		ret[0] = '0';
	while (i)
	{
		ret[size - 1] = i % 10 + 48;
		i = i / 10;
		size--;
	}
	return (ret);
}
