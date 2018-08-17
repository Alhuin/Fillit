/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <jjanin-r@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/17 22:01:38 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 23:26:16 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(char *av)
{
	char	*buf;
	int		fd;
	int		ret;

	ret = 0;
	if (!(buf = (char *)malloc(sizeof(*buf) * 546)))
		return (NULL);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	else
	{
		if ((ret = read(fd, buf, 550)) == -1)
			return (NULL);
		buf[ret] = '\0';
	}
	if (close(fd) == -1)
		return (NULL);
	return (buf);
}
