/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:34:57 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/19 01:02:38 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include "ft_printf.h"
# include <errno.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef enum				e_flags
{
	LONG_LISTING_FLAG = 1 << 0,
	RECURSIVE_FLAG = 1 << 1,
	ALL_FLAG = 1 << 2,
	MODIFICATION_DATE_SORT = 1 << 3,
	DISPLAY_UID_AND_GID = 1 << 4,
	SUPRESS_OWNER = 1 << 5,
	ONE_ENTRY_PER_LINE = 1 << 6,
	COLUMN_DISPLAY = 1 << 7,
	CREATION_DATE_SORT = 1 << 8,
	LAST_ACCESS_DATE_SORT = 1 << 9,
	LAST_STATUS_CHANGE_SORT = 1 << 10,
	HIDE_CURR_AND_PREV_DIRS = 1 << 11,
	REVERSE_FLAG = 1 << 12
}							t_fg;

typedef struct				s_files
{
	char			*name;
	char			*owner;
	char			*group;
	char			*modes;
	char			*display_name;
	char			*linked_to;
	time_t			tdate;
	struct timespec	cmptime;
	int				is_dir_info;
	int				is_chr_or_blk;
	int				status;
	int				is_link;
	int				has_nonprintable_chars;
	t_fg			*g_fg;
	struct stat		f;
	struct s_files	*next;
	struct s_files	*prev;
}							t_files;

typedef struct				s_lol
{
	t_fg		*g_fg;
	int			status;
}							t_lol;

typedef struct				s_format
{
	int				link;
	int				owner;
	int				group;
	int				file_size;
	int				user_id;
	int				group_id;
	int				major;
	int				minor;
}							t_format;

typedef struct				s_dirs
{
	char			*path;
	char			*display_name;
	int				count;
	int				status;
	int				is_default;
	int				is_unreadable;
	int				total_blocks;
	int				is_subdir;
	int				file_count;
	int				has_valid_files;
	int				has_chr_or_blk;
	t_fg			*g_fg;
	t_files			*files;
	t_files			*self;
	time_t			tdate;
	struct timespec	cmptime;
	t_format		format;
	struct s_dirs	*sub_dirs;
	struct s_dirs	*next;
	struct s_dirs	*prev;
}							t_dirs;

# define FORMAT_ERR	"ls: illegal option -- %c\n"
# define USAGE_ERR "Usage: ./ft_ls [-ACRUacglrt1] [file ...]\n"
# define DIR_STRERR "No such file or directory"

# define FLAG_ERR 1
# define FILE_ACCESS_ERR 1
# define DIR_ACCESS_ERR 2
# define NONEXISTENT_ERR 4

# define INIT_FORMAT 1
# define UPDATE_FORMAT 2
# define IDLE_FORMAT 4

# define DIRS_MEM 1
# define ERROR_MEM 2

# define ISUSR 1
# define ISGRP 2
# define ISOTH 4

# define IS_NONEXISTENT 1
# define IS_NOTDIR 2
# define IS_DIR 4
# define IS_LINK 8
# define IS_UNREADABLE 16

int							flag_handler(char **argv, t_fg *g_fg);
t_dirs						*dir_handler(char **av, t_fg *g_fg);
t_files						*file_handler(t_dirs *dirs, t_fg *g_fg);
void						format_handler(t_format *format, t_files *file,
		int format_opt);
void						display_handler(t_dirs *head, t_dirs *dirs,
		int target, t_fg *g_fg);
int							ft_strstart(char *s, char *oc);
char						*ft_cpath(char *path);
char						*cut_n(char *name, int len);
int							has_nonprintable_chars(char *s, int len);
int							has_dirs(t_dirs *dirs);
int							is_last_nondir(t_dirs *dirs);
void						file_permission_handler(t_files **curr_file,
		char *file_path, struct stat f);
void						get_link_file(t_files **curr_file, char *file_path);
void						handle_format(char *str, char *spb,
		char *spa, int end);
void						error_handling(char *option);
void						err_h(int err, char *msg);
void						dir_access_err(t_dirs *dirs);
void						set_dir(char *path, t_dirs **dirs,
		char *subdir_name, t_fg *g_fg);
void						read_dir(t_dirs *dir);
struct timespec				get_date(struct stat *f, t_fg *g_fg);
void						print_handling(t_dirs *dir, t_fg *g_fg);
void						nondir_display(t_dirs *dirs,
		int should_separate, t_fg *g_fg);
void						dir_display(t_dirs *head, t_dirs *dirs, t_fg *g_fg);
void						dir_p(t_dirs *dirs, t_fg *g_fg);
void						long_listing_display(t_format format, t_files *file,
		int has_chr_or_blk, t_fg *g_fg);
void						display_date(time_t date);
void						ls_lm_time(t_files *file, t_fg *g_fg);
t_dirs						*subdir_handler(t_dirs *next,
		t_dirs **sub_dirs, t_fg *g_fg);
void						add_file(t_files **curr_file, t_dirs **dirs,
		int format_opt, t_fg *g_fg);
void						ft_display(t_dirs *dirs);
void						free_files_bis(t_files **files);
void						free_dirs_bis(t_dirs *dirs);
void						memory_handler(void *mem_target,
		int target, t_fg *g_fg);
void						insert_sort(t_files **head, t_fg *g_fg);
void						reverse_files(t_files **files);
void						reverse_dirs(t_dirs **dirs);
t_dirs						*dirs_sort(t_dirs *dirs, t_fg *g_fg);
int							sort_time(char *a, char *b,
		struct timespec *aa, struct timespec *bb);
t_format					get_nondir_format(t_dirs **dirs, t_fg *g_fg);

#endif
