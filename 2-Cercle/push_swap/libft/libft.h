/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 00:29:23 by armendes          #+#    #+#             */
/*   Updated: 2022/01/18 20:12:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *str, char *charset);
int		ft_isdigit(int c);
long	ft_atoi(const char *nptr);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_itoa_base(long long n, char *base);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
