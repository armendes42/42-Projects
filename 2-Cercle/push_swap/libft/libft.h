/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 00:29:23 by armendes          #+#    #+#             */
/*   Updated: 2022/01/10 19:13:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
t_list	*ft_lstnew(int	content);
int		ft_lstsize(t_list *lst);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *str, char *charset);
int		ft_isdigit(int c);
long	ft_atoi(const char *nptr);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
