/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_mgmt.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:50:45 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 10:27:27 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_MGMT_H
# define STRING_MGMT_H

# ifndef STDDEF_H
#  include <stddef.h>
# endif

void	ft_strclr(char *s);
void	ft_strdel(char **as);
char	*ft_strrev(char *str);
char	*ft_strnew(size_t size);
char	*ft_strgetnp(char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strtrim(const char *str);
int		is_in(char i, char const *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strcat(char *s1, const char *s2);
void	ft_striter(char *s, void (*f)(char *));
char	*ft_strndup(const char *str, size_t n);
char	**ft_strsplit(const char *str, char c);
char	*ft_strtok(char *str, const char *sep);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strequ(const char *s1, const char *s2);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strcspn(const char *str, const char *rej);
char	*ft_strmap(const char *str, char (*f)(char));
char	*ft_strpbrk(const char *str, const char *lst);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strjoinfree(char *s1, char *s2, char **addr);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strsub(const char *str, unsigned int start, size_t n);
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));

#endif
