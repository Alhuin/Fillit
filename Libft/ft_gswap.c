/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gswap.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 23:19:18 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 23:19:18 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_gswap(void *p1, void *p2, size_t size)
{
	void *temp;

	if (!(temp = malloc(size)))
		return ;
	if (temp == NULL)
		return ;
	ft_memcpy(temp, p1, size);
	ft_memcpy(p1, p2, size);
	ft_memcpy(p2, temp, size);
	free(temp);
}
