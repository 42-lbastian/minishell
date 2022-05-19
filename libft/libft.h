/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspriet <hspriet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:39:42 by hspriet           #+#    #+#             */
/*   Updated: 2022/03/05 19:38:30 by hspriet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

long int	ft_atol(const char *theString);
int			ft_atoi(const char *theString);
void		ft_bzero(void *s, size_t len);
void		*ft_calloc(size_t elementCount, size_t elementSize);
int			ft_isalnum(int c);
int			ft_isalpha(int str);
int			ft_isascii(int c);
int			ft_isdigit(int str);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp( const void *pointer1, const void *pointer2, size_t size);
void		*ft_memcpy( void *destination, const void *source, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset( void *b, int c, size_t len );
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strdup(const char *source);
int			ft_strlen(const char *str);
size_t		ft_strlcat(char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
char		*ft_strrchr(const char *s, int c);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strtrim(char const *s1, char const *set);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_putchar(char c, int *res);
void		ft_putstr(char *str, int *res);
void		type_of(va_list list, char c, int *res);
int			ft_printf(const char *s, ...);
void		ft_uputnbr(unsigned int n, int *res);
void		ft_putnbr(long int n, int *res);
void		ft_putnbr_base2(unsigned long int n, int *res);
void		ft_putnbr_base(unsigned long int n, int *res);
char		**ft_split(char const *str, char charset);
int			how_many_word(char const *str, char charset);
int			is_charset(char c, char charset);

#endif
