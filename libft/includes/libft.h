/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:11:41 by nmei              #+#    #+#             */
/*   Updated: 2017/12/15 23:12:36 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** general utility
*/
int					ft_abs(int n);

/*
** char type checkers
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);

/*
** memory utilities
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memdup(void const *src, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);

/*
** string utilities
*/
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, int nb);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
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
size_t				ft_num_words(char const *str, char sep);
void				ft_splitdel(char ***split);

/*
** output functions
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char *str);

/*
** itoa, atoi, and putnbr variants
*/
int					ft_atoi(char *str);
char				*ft_itoa(int nbr);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putnbr(int n);

/*
** list utilities
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstrev(t_list **begin_list);
size_t				ft_lstlen(t_list *begin_list);
t_list				*ft_lstlast(t_list *begin_list);

/*
** get_next_line
*/
typedef	struct		s_file
{
	int				fd;
	int				tot_len;
	int				num_nls;
	int				nl_len;
	ssize_t			ret;
	char			*nl_ptr;
	char			*nl;
}					t_file;

int					ft_get_next_line(const int fd, char **line);

#endif
