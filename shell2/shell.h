#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>


#define C_LC 1
#define C_US 2
#define E_VAL 127
#define A_VAL 10
#define B_VAL 50
#define BUFFER_SIZE_R 1024
#define BUFFER_SIZE_W 1024
#define BUFFER_FLSH -1
#define CUSTOM_GETLINE 1
#define CUSTOM_STRTOK 1
#define OR_C 1
#define AND_C 2
#define CHN_C 3
#define NRM_C 0
#define H_MAX 4096
#define H_FILE ".hist_spl_shell"
#define ININIT {NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL,\
NULL, NULL, NULL, 0, 0, NULL, 0, 0, 0}
extern char **envr;

/**
* struct list_s - linked list.
* @n: ...
* @s: ...
* @next: the next node.
*/
typedef struct list_s
{
int n;
char *s;
struct list_s *next;
} l_s;


/**
 * struct list_args - linked list of args of shell.
 * @arg: ...
 * @argc: ...
 * @argv: ...
 * @path: ...
 * @iflag: ...
 * @nerr: ...
 * @iline: ...
 * @env: ...
 * @dif_env: ...
 * @fd: ...
 * @fname: ...
 * @tcmd: ...
 * @bcmd: ...
 * @st: ...
 * @hist: ...
 * @ihist: ...
 * @alias: ...
 */
typedef struct list_args
{
char *arg;
int argc;
char **argv;
char *path;
int iflag;
int nerr;
unsigned int iline;
l_s *env;
char **envr;
int dif_env;
int fd;
char *fname;
int tcmd;
char **bcmd;
int st;
l_s *hist;
int ihist;
l_s *alias;

} l_ar;

/**
 * struct list_bltin - list for builtin functions.
 * @s: the builtsin command.
 * @f: the  associated function to execute.
 */
typedef struct list_bltin
{
	char *s;
	int (*f)(l_ar *);
} list_b;

/* utils01.c*/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
int _putinfd(char c, int fd);

/* utils02.c*/
void _puts(char *s);
int _putsinfd(char *s, int fd);
char *_strcat(char *s1, char *s2);
char *_strncat(char *s1, char *s2, int n);
int _printa(l_s *l);

/* utils03.c*/
char *_strcpy(char *s1, char *s2);
char *_strncpy(char *s1, char *s2, int n);
char *_strdup(const char *s);
char *_strchr(char *s, char c);

/* utils04.c*/
char **_strtows(char *s, char *a);
char *_strbg(const char *a, const char *b);
int _strrplce(char **s1, char *s2);

/* utils05.c*/
l_s *add_node_end(l_s **head, const char *s, int i);
ssize_t get_node_index(l_s *l, l_s *n);
l_s *get_node_with(l_s *l, char *s, char c);

/* utils06.c*/
int delete_node_at_index(l_s **l, unsigned int i);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _strfree(char **s);
void freel(l_s **head);

/* utils07.c*/
int freep(void **s);
size_t _printlall(const l_s *l);
size_t _printl(const l_s *l);
size_t _getlenl(const l_s *l);
int _unseta(l_ar *ar, char *s);

/* utils08.c */
char **_getl(l_s *head);
int _vrplce(l_ar *ar);
int _cisch(l_ar *ar, char *s, size_t *n);
void _cch(l_ar *ar, char *s, size_t *n, size_t i, size_t len);

/* utils09.c */
int _indlm(char c, char *s);
char *duppath(char *s, int a, int b);
char *_getinpath(l_ar *ar, char *p, char *s);
void _setarg(l_ar *ar, char **argv);
int _seta(l_ar *ar, char *s);

/* utils10.c */
void _clarg(l_ar *ar);
int _arplce(l_ar *ar);
void _freearg(l_ar *ar, int n);
char *_memset(char *s, char a, unsigned int n);
ssize_t _strr(l_ar *ar, char *s, size_t *i);

/* utils11.c */
int _printd(int a, int fd);
char *_itoa(long int n, int b, int f);
ssize_t _ins(l_ar *ar, char **s, size_t *len);

/* main.c*/
int prompt(l_ar *ar, char **argv);
int _builtin(l_ar *ar);
int _i_mode(l_ar *ar);
void _handlesig(int n);

/* command.c*/
void _inpath(l_ar *ar);
void _forkc(l_ar *ar);
int _isexsec(l_ar *ar, char *s);
ssize_t _getline(l_ar *ar);
int _getnextline(l_ar *ar, char **s, size_t *len);

/* builtin01.c */
int _biexit(l_ar *ar);
int _bienv(l_ar *ar);
int _bisetenv(l_ar *ar);
int _biunsetenv(l_ar *ar);
/* builtin02.c */
int _bicd(l_ar *ar);
int _bihelp(l_ar *ar);
int _bihist(l_ar *ar);
int _bialias(l_ar *ar);
void _delcom(char *s);

/* environment.c */
char *_getenv(l_ar *ar, const char *s);
char **get_envr(l_ar *ar);
int _setenv(l_ar *ar, char *s1, char *s2);
int _unsetenv(l_ar *ar, char *s);
int _envdup(l_ar *ar);

/* history.c */
char *_gethistf(l_ar *ar);
int _rhist(l_ar *ar);
int _addhist(l_ar *ar, char *s, int n);
int _updhist(l_ar *ar);
int _whist(l_ar *ar);

/* error.c */
int _putechar(char c);
void _putse(char *s);
void _printe(l_ar *ar, char *s);
int _atoie(char *s);


#endif