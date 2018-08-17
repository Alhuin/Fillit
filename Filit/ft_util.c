/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_util.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 13:02:52 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 23:38:34 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_del(char **str, char c)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (str);
}

char	**ft_put(char **str, t_lst *l, int i, int j)
{
	str[i][j] = l->c;
	str[i + l->co[2]][j + l->co[3]] = l->c;
	str[i + l->co[4]][j + l->co[5]] = l->c;
	str[i + l->co[6]][j + l->co[7]] = l->c;
	return (str);
}

char	**ft_fe(char **s, t_lst *l, int i, int j)
{
	while (s[i])
	{
		while (s[i][j])
		{
			if (i + l->co[2] < g_len && j + l->co[3] < g_len && i + l->co[4] <
					g_len && j + l->co[5] < g_len && i + l->co[6] < g_len &&
					j + l->co[7] < g_len && s[i][j] == '.' &&
					s[i + l->co[2]][j + l->co[3]] == '.' &&
					s[i + l->co[4]][j + l->co[5]] == '.' &&
					s[i + l->co[6]][j + l->co[7]] == '.')
			{
				l->co[0] = i;
				l->co[1] = j;
				return (ft_put(s, l, i, j));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
