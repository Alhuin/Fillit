/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 18:28:51 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 16:51:40 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char *str;
	char **tab;

	tab = NULL;
	str = NULL;
	if (ac != 2)
		write(2,
		"usage:\t./fillit input_file\n\tinput_file: your fillit sample\n", 60);
	else if (ft_test((str = ft_read(av[1])), 0, 0, 0))
	{
		if ((tab = ft_tetricheck(ft_strsplit(str, '\n'), 0)))
		{
			ft_putstr2d(tab = ft_solve(ft_get_coord(str, 0)));
			ft_freestr2d(tab);
		}
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "error\n", 6);
	free(str);
	return (0);
}
