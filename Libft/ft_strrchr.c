/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 23:19:31 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 23:19:31 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p;

	p = NULL;
	while (s[0])
	{
		if (s[0] == c)
			p = s;
		s++;
	}
	if (c == '\0')
		p = s;
	return ((char *)p);
}