/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solve.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 12:36:40 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 14:59:10 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freelst(t_lst *lst)
{
	t_lst *tmp;

	tmp = lst;
	while (lst)
	{
		lst = lst->nxt;
		free(tmp->co);
		free(tmp);
		tmp = lst;
	}
}

void	ft_ppct(t_lst *lst)
{
	int i;
	int j;

	j = 2;
	i = 0;
	while (lst)
	{
		lst = lst->nxt;
		i++;
	}
	while (j * j < i * 4)
		j++;
	g_len = j;
}

char	**ft_create_tab(void)
{
	int		j;
	int		k;
	char	**t;

	j = 0;
	if (!(t = (char **)malloc(sizeof(*t) * (g_len + 1))))
		return (NULL);
	t[g_len] = NULL;
	while (j < g_len)
	{
		k = 0;
		if (!(t[j] = (char *)malloc(sizeof(**t) * (g_len + 1))))
			return (NULL);
		t[j][g_len] = '\0';
		while (k < g_len)
			t[j][k++] = '.';
		j++;
	}
	return (t);
}

char	**ft_bt(char **r, t_lst *l, int i, int j)
{
	char **t;

	while (r[i])
	{
		if (!(t = ft_fe(r, l, i, j)))
			return (NULL);
		else if (l->nxt != NULL && !(t = ft_bt(r, l->nxt, 0, 0)))
		{
			r = ft_del(r, l->c);
			i = l->co[0];
			j = l->co[1] + 1;
		}
		else
			return (t);
	}
	free(r);
	return (NULL);
}

char	**ft_solve(t_lst *lst)
{
	char	**res;
	char	**tab;

	ft_ppct(lst);
	tab = ft_create_tab();
	while (g_len < 20 && !(res = ft_bt(tab, lst, 0, 0)))
	{
		ft_freestr2d(tab);
		g_len++;
		tab = ft_create_tab();
	}
	ft_freelst(lst);
	return (res);
}
