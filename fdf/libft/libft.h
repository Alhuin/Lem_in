/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:13:20 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 16:26:34 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define BUFF_SIZE 4096

double				ft_abs(double nbr);
wchar_t				*ft_wstrdup(wchar_t *s1);
void				ft_putwstr(wchar_t *str);
wchar_t				*ft_wstrjoin(wchar_t *s1, wchar_t *s2, int k);
char				*ft_strnewchar(int size, char c);
wchar_t				*ft_wstrnewchar(int size, wchar_t c);
char				*ft_strndup(char *str, size_t j, size_t n);
wchar_t				*ft_wstrndup(wchar_t *str, size_t j, size_t n);
wchar_t				*ft_wstrnew(size_t size);
int					ft_pow(int x, unsigned int y);
int					ft_partlen(char *str, int i, char *comp);
size_t				ft_wstrlen(wchar_t *str);
int					ft_wcharlen(wchar_t c);
void				*ft_strrev(char *str);
size_t				ft_strlen(const char *s);
void				ft_putnbrbase(uintmax_t nbr, char *base, size_t baselen);
void				ft_putwchar(const wchar_t c);
char				*ft_itoabase(uintmax_t nbr, char *base, int baselen);
int					ft_itos_upper(int nbr, int base);
int					ft_itos_lower(int nbr, int base);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
									const char *needle, size_t len);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strjoin(char *s1, char *s2, int i);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strdup(char *s1);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_itoa(intmax_t nbr);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_countwords(char const *str, char c);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
void				ft_swap(size_t *a, size_t *b);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

t_btree				*ft_btree_create_node(void *item);
void				ft_btree_apply_prefix(t_btree *root,
						void (*applyf)(void *));
void				ft_btree_apply_infix(t_btree *root,
						void (*applyf)(void	*));
void				ft_btree_apply_suffix(t_btree *root,
						void (*applyf)(void *));

typedef struct		s_list2
{
	struct s_list	*next;
	void			*data;
}					t_list2;

t_list2				*ft_create_elem(void *data);

void				*ft_realloc(void *ptr, size_t prev_size, size_t new_size);

typedef struct		s_gnl
{
	char			*text;
	char			*line;
	char			*tmp;
	char			*buff;
	int				ret;
	int				result;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
