#ifndef _SHELL_H_
#define _SHELL_H_

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUF_SIZE 1024


/**
 * struct list_u - linked list.
 * @s1: the first variable.
 * @s2: the second variabe.
 * @next: the next node.
 */
typedef struct list_u
{
	char *s1;
	char *s2;
	struct list_u *next;

} l_u;
/* global variables*/
/* extern l_u *a; */



/*-----------shell.c-----------*/
void i_mode(l_u *e);

/*-----------utils01.c-----------*/
void _handler_ctrlc(int n);
void pnewline(char *command);
char *dnewline(char *s);
ssize_t checkcounter(ssize_t c);

/*-----------utils02.c-----------*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
ssize_t _getline(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*-----------utils03.c-----------*/
int _putchar(char c);
void _puts(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/*-----------utils04.c-----------*/
int _atoi(char *s);
char *isinpath(char *s, l_u *e);
l_u *add_node(l_u **head, char *s1, char *s2);

/*-----------token.c-----------*/
char **_strtok(char *s, char d);
int _getsizetok(char *s, char d, int *t);
void _freetok(char **tk);

/*-----------command.c-----------*/
int isbuiltin(char **token);
int isexecute(char **tk, l_u *e);

/*-----------environment.c-----------*/
l_u *_getenv(char **env);
char *_getenvval(char *s, l_u *e);

/*-----------builtin01.c-----------*/
int _bi_exit(char **tk);

#endif


