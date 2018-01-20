/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:18:21 by nmei              #+#    #+#             */
/*   Updated: 2017/12/15 23:12:24 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#define BUFF_SIZE 1024

static t_file	*find_or_add_file(t_list **f_lst, int fd)
{
	t_file	new_file;
	t_file	*cast_file;
	t_list	*cur_file;

	if (f_lst)
	{
		cur_file = *f_lst;
		while (cur_file)
		{
			cast_file = (t_file *)cur_file->content;
			if (cast_file->fd == fd)
				return (cast_file);
			cur_file = cur_file->next;
		}
	}
	new_file.fd = fd;
	new_file.tot_len = 0;
	new_file.num_nls = 0;
	new_file.nl_len = 0;
	new_file.ret = 0;
	new_file.nl_ptr = NULL;
	new_file.nl = ft_strnew(0);
	ft_lstadd(f_lst, ft_lstnew(&new_file, sizeof(new_file)));
	return ((t_file *)((*f_lst)->content));
}

/*
**	cf is short for current_file
*/

static void		read_fd(t_file *cf)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	while (cf->nl_ptr == NULL && (cf->ret = read(cf->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[cf->ret] = '\0';
		if ((cf->nl_ptr = ft_strchr(buf, '\n')) != NULL)
		{
			cf->num_nls++;
			cf->nl_len += (cf->nl_ptr - buf);
		}
		else
			cf->nl_len += cf->ret;
		cf->tot_len += cf->ret;
		temp = ft_strjoin(cf->nl, buf);
		free(cf->nl);
		cf->nl = temp;
	}
	if (cf->nl_ptr)
		while (*cf->nl_ptr)
			if (*(++cf->nl_ptr) == '\n')
				cf->num_nls++;
}

static void		prep_next_line(t_file *cf)
{
	char *tmp;

	cf->num_nls = (cf->num_nls > 0) ? cf->num_nls - 1 : 0;
	if (cf->tot_len > cf->nl_len)
		cf->nl_len++;
	tmp = ft_strsub(cf->nl, cf->nl_len, cf->tot_len - cf->nl_len);
	cf->tot_len = cf->tot_len - cf->nl_len;
	free(cf->nl);
	cf->nl = tmp;
	while (*tmp)
	{
		if (*tmp == '\n')
			break ;
		tmp++;
	}
	cf->nl_len = tmp - cf->nl;
	cf->nl_ptr = NULL;
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*f_lst;
	t_file			*cf;

	if (fd < 0 || !line)
		return (-1);
	cf = find_or_add_file(&f_lst, fd);
	if (cf->num_nls == 0)
		read_fd(cf);
	if (cf->ret == -1)
		return (-1);
	if (cf->tot_len == 0)
		return (0);
	*line = ft_strsub(cf->nl, 0, cf->nl_len);
	prep_next_line(cf);
	return (1);
}
