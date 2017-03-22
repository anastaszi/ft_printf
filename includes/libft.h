/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:11:40 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 12:10:35 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <float.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strstr(const char *big, const char *little);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
char				*ft_strncat(char *dst, const char *src, size_t len);
void				*ft_memalloc(size_t size);
void				ft_putchar(int c);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_memdel(void **ap);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
t_list				*ft_lstnew(void	const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstlen(t_list *lst);
void				ft_lstprint(t_list *lst);
void				ft_lstpush_head(t_list **alst, void const *content,
		size_t content_size);
void				ft_lstpush_back(t_list **alst, void const *contetn,
		size_t content_size);
void				*ft_lstindex(t_list *lst, int index);
void				*ft_lstlastelem(t_list *lst);
t_list				*ft_lstevenelem(t_list **lst);
void				ft_lsttotaldel(t_list **lst);
char				*ft_lst_tostring(t_list **lst);
size_t				ft_chararraylen(const char **array);
void				ft_del(void *data, size_t size);
void				ft_lstdelelemfromlst(t_list **big, t_list *elem);
char				*ft_stradd(char **str, char *add);
char				*ft_strnadd(char **str, const char *add, size_t len);
char				*ft_straddfirst(char **str, char *add);
char				*ft_strnewset(size_t len, char c);
int					ft_topower(int i, int power);
int					ft_abc(int num);
char				*ft_straddchar(char **str, char add);
double				ft_topowerdouble(double num, int i);
void				ft_strreverse(char **str);
void				ft_strdelpart(char **str, size_t start);
#endif
