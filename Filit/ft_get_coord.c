/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_coord.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <jjanin-r@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:44:21 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 23:44:39 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_cd(char **p, int i, int j, int k)
{
	int		*s;

	if (!(s = (int *)malloc(sizeof(*s) * 9)))
		return (NULL);
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (k == 0 && p[i][j] == '#')
			{
				s[k++] = i;
				s[1] = j;
			}
			else if (p[i][j] == '#')
			{
				s[k * 2] = i - s[0];
				s[k * 2 + 1] = j - s[1];
				k++;
			}
			j++;
		}
		i++;
	}
	return (s);
}

t_lst	*ft_new(int *s, char c)
{
	t_lst *ele;
	t_lst *ptr;

	if (!(ele = (t_lst *)malloc(sizeof(*ele))))
		return (NULL);
	ele->co = s;
	ele->c = c;
	ele->nxt = NULL;
	ptr = ele;
	return (ptr);
}

t_lst	*ft_get_coord(char *t, int i)
{
	t_lst	*lst;
	t_lst	*tmp;
	char	c;

	lst = ft_new(NULL, 0);
	tmp = lst;
	c = 'A';
	while (t[i])
	{
		tmp->nxt =
			ft_new(ft_cd(ft_strsplit(ft_strsub(t, i, 20), '\n'), 0, 0, 0), c);
		tmp = tmp->nxt;
		if (t[i + 20])
			i += 21;
		else
			i += 20;
		c++;
	}
	tmp->nxt = NULL;
	return (lst->nxt);
}
