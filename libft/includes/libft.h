/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:45:08 by stelie            #+#    #+#             */
/*   Updated: 2022/12/14 12:46:06 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define ERROR -1
# define TYPESET "csiduxXp"
# define FLAGSET "#+- 0"
# define HEXA_UP "0123456789ABCDEF"
# define HEXA_LOW "0123456789abcdef"
# define DECIMAL "0123456789"
# define OCTAL "01234567"
# define BINARY "01"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef enum e_flags
{
	ZERO,
	SHARP,
	MINUS,
	PLUS,
	SPAC,
	M_WIDTH,
	PREC,
	FID_ERROR
}				t_flags;

typedef struct s_fid
{
	int		flag[8];
	char	conv;
	int		fid_len;
	bool	def_pre;
}				t_fid;

/*
00_is_something
*/

bool			ft_incharset(char c, const char *charset);
bool			ft_isalnum(int c);
bool			ft_isalpha(int c);
bool			ft_isascii(int c);
bool			ft_isbinary(char *str);
bool			ft_isdigit(int c);
bool			ft_ishexa(char *nbr);
bool			ft_islower(int c);
bool			ft_isoctal(char *str);
bool			ft_isprint(int c);
bool			ft_isspace(int c);
bool			ft_isupper(int c);

/*
01_get_len
*/

size_t			ft_hexalen(size_t nb);
size_t			ft_intlen(int nb);
size_t			ft_nbrlen(long long nb);
size_t			ft_strlen(const char *s);
size_t			ft_arrlen(char **array);

/*
02_numbers
*/

int				ft_atoi(const char *str);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_power(int power, int nbr);
char			*ft_itoa(int n);
char			*ft_lltoa(long long int nb);
long long		ft_atoll(const char *str);

/*
03_bases
*/

int				ft_base_to_int_dec(char *base, char *bnbr);
int				ft_bin_to_int_dec(char *bin);
int				ft_hex_to_int_dec(char *hex);
int				ft_oct_to_int_dec(char *bin);

/*
04_put_something
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_putmsg_fd(char *msg, int fd, int ret);
void			ft_putarr_fd(char **array, int fd);
void			ft_putlnbr_fd(long long nbr, int fd);

/*
05_strings
*/

char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char	*str);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_ctoupper(int c);
int				ft_ctolower(int c);
char			*ft_str_cut_before(char *src, char c);
char			*ft_str_cut_after(char *src, char c);
size_t			ft_str_arr_len(char **arr);
char			**ft_str_arr_dup(char **arr);
char			**ft_str_arr_ndup(char **array, int n);
void			ft_str_arr_free(char **array);
char			*ft_str_rm_char(char *src, int index);
char			*ft_str_rm_fst_occ(char *src, char c);
char			*ft_str_rm_last_occ(char *src, char c);

/*
06_memory
*/

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_free(void *p);
int				ft_free_and_return(void *p, int return_value);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);

/*
07_chained_lists
*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
08_ft_printf
*/

int				ft_printf(const char *format, ...);
void			ft_pf_putnbr(int n);
int				use_fid(va_list list, t_fid *fid);
int				pf_string(char *str, t_fid *fid);
int				pf_int(int nb, t_fid *fid);
int				pf_uint(unsigned int nb, t_fid *fid);
int				pf_hexa(unsigned int nb, t_fid *fid);
int				pf_ptr(uintptr_t addr, t_fid *fid);

/*
09_gnl
*/

char			*get_next_line(int fd);

#endif
