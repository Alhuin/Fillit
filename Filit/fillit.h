/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 12:35:17 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 23:55:32 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../Libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

int						g_len;

typedef struct			s_fill_lst
{
	char				c;
	int					*co;
	struct s_fill_lst	*nxt;
}						t_lst;

int						ft_test(char *str, int i, int j, int k);
char					*ft_read(char *av);
char					**ft_solve(t_lst *lst);
char					**ft_tetricheck(char **tab, int i);
t_lst					*ft_get_coord(char *t, int i);
char					**ft_solve(t_lst *lst);
char					**ft_del(char **str, char c);
char					**ft_fe(char **s, t_lst *l, int i, int j);
char					**ft_create_tab(void);
void					ft_ppct(t_lst *lst);
char					**ft_bt(char **r, t_lst *l, int i, int j);
int						*ft_cd(char **p, int i, int j, int k);
t_lst					*ft_new(int *s, char c);
void					ft_freeelst(t_lst *lst);
int						ft_change_firstc(char **tab, char l);
int						ft_deepthought(char **tab, int i, int j, char c);
char					**ft_tetricheck1(char **tab, int i, int j, char c);
char					**ft_put(char **str, t_lst *l, int i, int j);
#endif
