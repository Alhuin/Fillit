/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <jjanin-r@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/17 20:01:21 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 15:29:44 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			ft_test(char *str, int i, int j, int k)
{
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] == '#' || str[i] == '.' || str[i] == '\n'))
			return (0);
		if (str[i] == '\n')
		{
			k++;
			if ((j != 4 && k != 5) || (k == 5 && j != 0))
				return (0);
			if (k == 5)
				k = 0;
			j = 0;
		}
		else
			j++;
		i++;
	}
	if (k != 4)
		return (0);
	return (1);
}

int			ft_change_firstc(char **tab, char l)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != '#')
			j++;
		if (tab[i][j] == '#')
		{
			tab[i][j] = l;
			if (j + 1 < 4 && tab[i][j + 1] == '#')
				tab[i][j + 1] = l;
			if (i + 1 < 4 && tab[i + 1][j] == '#')
				tab[i + 1][j] = l;
			return (0);
		}
		i++;
	}
	return (0);
}

int			ft_deepthought(char **tab, int i, int j, char c)
{
	if ((j < 3 && tab[i][j + 1] == c) ||
			(i < 3 && tab[i + 1][j] == c) ||
			(j > 0 && tab[i][j - 1] == c) ||
			(i > 0 && tab[i - 1][j] == c) ||
			(j < 2 && tab[i][j + 1] == '#' && tab[i][j + 2] == c) ||
			(i > 0 && j < 3 && tab[i][j + 1] == '#' && tab[i - 1][j + 1] == c))
		return (1);
	else
		return (0);
}

char		**ft_tetricheck1(char **tab, int i, int j, char c)
{
	int		k;

	while (tab[i])
	{
		c += 1;
		k = -1;
		ft_change_firstc(tab + i, c);
		while (++k < 4)
		{
			j = -1;
			while (tab[i][++j])
				if (tab[i][j] == '#')
				{
					if (ft_deepthought(tab, i, j, c))
						tab[i][j] = c;
					else
						return (NULL);
				}
			i++;
		}
	}
	return (tab);
}

char		**ft_tetricheck(char **tab, int i)
{
	int j;
	int k;
	int l;

	while (tab[i])
	{
		l = 0;
		k = 0;
		while (k < 4)
		{
			j = 0;
			while (tab[i][j])
			{
				if (tab[i][j] == '#')
					l++;
				j++;
			}
			i++;
			k++;
		}
		if (l != 4)
			return (0);
	}
	return (ft_tetricheck1(tab, 0, -1, 'A' - 1));
}
