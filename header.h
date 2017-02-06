/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:31:43 by eleclet           #+#    #+#             */
/*   Updated: 2017/02/02 15:35:38 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft/libft.h"
# include "signal.h"
# include <stdbool.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <stdio.h>
# include <sys/wait.h>
# include <dirent.h>

# define IS_CHAR s[0] >= 32 && s[0] <= 126 && s[1] == 0
# define KEY_LE s[0] == 27 && s[1] == 91 && s[2] == 68
# define KEY_RI s[0] == 27 && s[1] == 91 && s[2] == 67
# define KEY_DO s[0] == 27 && s[1] == 91 && s[2] == 66
# define KEY_UPP s[0] == 27 && s[1] == 91 && s[2] == 65
# define BACKSPACE s[0] == 127 && s[1] == 0
# define DEL s[0] == 27 && s[1] == 91 && s[2] == 51
# define CTRL_D s[0] == 4
# define HOME s[0] == 27 && s[1] == 91 && s[2] == 53
# define END s[0] == 27 && s[1] == 91 && s[2] == 54
# define CTRL_RIGHT s[2] == 49 && s[4] == 53 && s[5] == 67
# define CTRL_LEFT s[2] == 49 && s[4] == 53 && s[5] == 68
# define CTRL_DO s[2] == 49 && s[4] == 53 && s[5] == 66
# define CTRL_UP s[2] == 49 && s[4] == 53 && s[5] == 65
# define ALT_C s[0] == 27 && s[1] == 99 && s[2] == 0
# define ALT_V s[0] == 27 && s[1] == 118 && s[2] == 0
# define ENTER s[0] == 10 && s[1] == 0
# define HLEN 30


typedef struct		s_hist
{
	char 		**tab;
	char		*current;
	int	 	index;
	int		pos;
	bool		art;
}			t_hist;

typedef struct		s_env
{
	char		**t;
	struct termios	term;
	t_hist		*hist;

}			t_env;

typedef struct		s_line
{
	char		*str;
	char		*prompt;
	char		*buffer_copy;
	int		plen;
	int 		pos;
	int		len;
	t_hist		*h;
}			t_line;

typedef struct		s_data
{
	t_line 		*l;
	t_env		*e;
}			t_data;

int			col(void);
int			row(void);

struct termios		*def_term(void);
bool			clean_exit(t_line *line);
bool			restore_term(struct termios *term_restore);
struct termios		get_env(struct termios term);
bool			init_error(void);
bool			error(void);

char			*s_add(char *s, char c, int pos);
char			*s_del(char *s, int pos);

char			*readLine(char *prompt, t_hist *hist);
	
char			key_pressed(char *s, t_line *line);

char			*readLineMaster(void);
t_line			*struct_init(char *prompt, t_hist *h);

int			outc(int c);
int			letter(t_line *line, char c);
int			key_del(t_line *line);
bool			key_le(t_line *line);
bool			key_ri(t_line *line);
bool			key_upp(t_line *line);
bool			key_suppr(t_line *line);
bool			key_do(t_line *line);
bool			key_ho(t_line *line);
bool			key_en(t_line *line);
bool			key_next_word(t_line *line);
bool			key_prev_word(t_line *line);
	
bool    		check_eol(t_line *line, int p);
bool    		check_bol(t_line *line, int p);
void    		print_end(t_line line);
int     		posx(t_line line);
int     		posy(t_line line);
int     		leny(t_line line);

void    		restore_curs(t_line line);
void			move_curs(int x, t_line line);
int			cursrow(int fd);
int			curscol(int fd);
int     		debug(t_line *line, int a, int b, int c);


bool			copy(t_line *line);
void			copy_read(t_line *line);
void			paste(t_line *line);

t_hist			*hist_init(void);
void			hist_add(t_hist *h, char *s);
void			hist_read_up(t_line *l);
void			hist_read_do(t_line *l);

char			*clean_line(t_line *line);
void			s_add_s(t_line *l);

void			ft_signal(void);
void			ft_sigint(int i);
t_data			*get_data(t_data *d);

t_env			*env_init(void);
bool			display_env(char **line, t_env *env);
bool			set_env(char **line, t_env *env);
bool			buildin(char **line, t_env *env);
char			**parser(char *str, t_env *env);
bool			unset_env(char **line, t_env *env);

int			disp_err(int code);

char			**split_path(char **env);
int			is_exec(char **param);
char			*get_home_dir(char **env);
int			basic_exec(char **param, char **env);
int			exec_bin(char **env, char **param, char **path);


# endif
