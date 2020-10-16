/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:29:35 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/15 20:31:14 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline char			get_file_entry_type(int mode)
{
	if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

static char					extented_attributes_handler(char *file_path)
{
	char			res;
	acl_t			acl;
	acl_entry_t		entry;

	res = ' ';
	if (listxattr(file_path, NULL, 0, XATTR_NOFOLLOW) == -1)
	{
		if (errno == EPERM || errno == EACCES || errno == EFAULT)
			return (' ');
	}
	else if (listxattr(file_path, NULL, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	acl = acl_get_link_np(file_path, ACL_TYPE_EXTENDED);
	if (!acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &entry) == -1)
	{
		acl_free((void *)acl);
		acl = NULL;
	}
	if (acl)
	{
		res = '+';
		acl_free((void *)acl);
	}
	return (res);
}

static inline char			get_correct_character(int mode,
		int is_exec, int is_sticky)
{
	if (mode & is_exec)
	{
		if (mode & is_sticky)
			return ('s');
		else
			return ('x');
	}
	else
	{
		if (mode & is_sticky)
			return ('S');
		else
			return ('-');
	}
}

static inline char			p_handling(int mode, int user_type)
{
	if (user_type == ISUSR)
		return (get_correct_character(mode, S_IXUSR, S_ISUID));
	else if (user_type == ISGRP)
		return (get_correct_character(mode, S_IXGRP, S_ISGID));
	else
	{
		if (mode & S_IXOTH)
		{
			if (mode & S_ISTXT)
				return ('t');
			else
				return ('x');
		}
		else
		{
			if (mode & S_ISTXT)
				return ('T');
			else
				return ('-');
		}
	}
}

void						file_permission_handler(t_files **curr_file,
		char *file_path, struct stat f)
{
	(*curr_file)->modes[0] = get_file_entry_type(f.st_mode);
	(*curr_file)->modes[1] = (f.st_mode & S_IRUSR) ? 'r' : '-';
	(*curr_file)->modes[2] = (f.st_mode & S_IWUSR) ? 'w' : '-';
	(*curr_file)->modes[3] = p_handling(f.st_mode, ISUSR);
	(*curr_file)->modes[4] = (f.st_mode & S_IRGRP) ? 'r' : '-';
	(*curr_file)->modes[5] = (f.st_mode & S_IWGRP) ? 'w' : '-';
	(*curr_file)->modes[6] = p_handling(f.st_mode, ISGRP);
	(*curr_file)->modes[7] = (f.st_mode & S_IROTH) ? 'r' : '-';
	(*curr_file)->modes[8] = (f.st_mode & S_IWOTH) ? 'w' : '-';
	(*curr_file)->modes[9] = p_handling(f.st_mode, ISOTH);
	if ((*curr_file)->modes[1] != '-')
		(*curr_file)->modes[10] = extented_attributes_handler(file_path);
	else
		(*curr_file)->modes[10] = ' ';
}
