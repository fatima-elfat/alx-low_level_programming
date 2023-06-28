#include "shell.h"
/**
 * _inpath - finds in path the command.
 * @ar: the struct of arg of the shell.
 */
void _inpath(l_ar *ar)
{
	int i, j;
	char *path = NULL;

	ar->path = ar->argv[0];
	if (ar->iflag == 1)
	{
		ar->iline++;
		ar->iflag = 0;
	}
	for (i = 0, j = 0; ar->arg[i]; i++)
		if (!_indlm(ar->arg[i], " \t\n"))
			j++;
	if (!j)
		return;
	path = _getinpath(ar, _getenv(ar, "PATH="), ar->argv[0]);
	if (path)
	{
		ar->path = path;
		_forkc(ar);
	}
	else
	{
		if ((_i_mode(ar) || _getenv(ar, "PATH=")
			|| ar->argv[0][0] == '/') && _isexsec(ar, ar->argv[0]))
			_forkc(ar);
		else if (*(ar->arg) != '\n')
		{
			ar->st = E_VAL;
			_printe(ar, "not found\n");
		}
	}
}
/**
 * _forkc - forks to run command
 * @ar: the struct of arg of the shell.
 */
void _forkc(l_ar *ar)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Error:");
		return;
	}
	if (child != 0)
	{
		wait(&(ar->st));
		if (WIFEXITED(ar->st))
		{
			ar->st = WEXITSTATUS(ar->st);
			if (ar->st == (E_VAL - 1))
				_printe(ar, "Permission denied\n");
		}
	}
	else
	{
		if (execve(ar->path, ar->argv, get_envr(ar)) == -1)
		{
			_freearg(ar, 1);
			if (errno == EACCES)
				exit((E_VAL - 1));
			exit(1);
		}
	}
}
/**
 * _isexsec - determines if a file in path is an exec function.
 * @ar:  the struct of arg of the shell.
 * @s: the value of path.
 * Return: 1 if true, else 0.
 */
int _isexsec(l_ar *ar, char *s)
{
	struct stat st;

	(void)ar;
	if (!s || stat(s, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * _getline - gets the line without \n.
 * @ar: the struct of arg of the shell.
 * Return: ...
 */
ssize_t _getline(l_ar *ar)
{
	static size_t i, j, len;
	ssize_t r = 0;
	char **ptr = &(ar->arg), *s;
	static char *buffer;

	j = i;
	r = _ins(ar, &buffer, &len);
	_putchar(BUFFER_FLSH);
	if (r == -1)
		return (-1);
	if (len)
	{
		s = buffer + i;
		_cch(ar, buffer, &j, i, len);
		while (j < len)
		{
			if (_cisch(ar, buffer, &j))
				break;
			j++;
		}
		j++;
		i = j;
		if (i >= len)
		{
			ar->tcmd = NRM_C;
			i = 0;
			len = 0;
		}
		*ptr = s; 
		return (_strlen(s));
	}
	*ptr = buffer;
	return (r);
}
/**
 * _getnextline - gets the next line.
 * @ar: the struct of args of shell
 * @s: the already allocated buffer
 * in getline and used in _ins(adress)
 * @len: length.
 * Return: ...
 */
int _getnextline(l_ar *ar, char **s, size_t *len)
{
	static size_t l, i;
	size_t j;
	ssize_t r = 0, t = 0;
	char *str, *ptr = NULL, *nptr = NULL;
	static char buffer[BUFFER_SIZE_R];

	ptr = *s;
	if (ptr && len)
		t = *len;
	if (i == l)
	{
		i = 0;
		l = 0;
	}
	r = _strr(ar, buffer, &l);
	if ((r == 0 && l == 0) || r == -1)
		return (-1);
	str = _strchr(buffer + i, '\n');
	if (str)
		j = (unsigned int)(str - buffer) + 1;
	else
		j = l;
	nptr = _realloc(ptr, t, t ? t + j : j + 1);
	if (!nptr)
		return (ptr ? free(ptr), -1 : -1);
	if (!t)
		_strncpy(nptr, buffer + i, j - i + 1);
	else
		_strncat(nptr, buffer + i, j - i);
	t += j - i;
	i = j;
	ptr = nptr;
	if (len)
		*len = t;
	*s = ptr;
	return (t);
}

