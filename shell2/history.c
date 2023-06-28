#include "shell.h"

/**
 * _gethistf - gets the history file.
 * @ar: the struct l_ar of arguments of shell.
 * Return: the history file.
 */

char *_gethistf(l_ar *ar)
{
	char *buffer, *dir;

	dir = _getenv(ar, "HOME=");
	if (dir == NULL)
		return (NULL);
	buffer = malloc((_strlen(dir) + _strlen(H_FILE) + 2));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, dir);
	_strcat(buffer, "/");
	_strcat(buffer, H_FILE);
	return (buffer);
}

/**
 * _rhist - reads history from file
 * @ar: the struct l_ar of arguments of shell.
 * Return: count on success, or 0.
 */
int _rhist(ar_t *ar)
{
	struct stat st;
	int count = 0, end = 0, i;
	ssize_t fs = 0, fd, rdlen;
	char *buffer = NULL, *fname;

	fname = _gethistf(ar)
	if (!fname)
		return (0);
	fd = open(fname, O_RDONLY);
	free(fname);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fs = st.st_size;
	if (fs < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fs + 1));
	if (buffer == NULL)
		return (0);
	rdlen = read(fd, buffer, fs);
	buffer[fs] = 0;
	if (rdlen <= 0)
		return (free(buffer), 0);
	close(fd);
	for (i = 0; i < fs; i++)
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			_addhist(ar, buffer + end, count++);
			end = i + 1;
		}
	if (end != i)
		_addhist(ar, buffer + end, count++);
	free(buffer);
	ar->ihist = count;
	while (ar->ihist-- >= H_MAX)
		delete_node_at_index(&(ar->hist), 0);
	_updhist(ar);
	return (ar->ihist);
}

/**
 * _addhist - adds entry to a history linked list
 * @ar: the struct l_ar of arguments of shell.
 * @s: the sting bufferfer.
 * @n: the count in history.
 * Return: 0.
 */
int _addhist(l_ar *ar, char *s, int n)
{
	l_s *lin = NULL;

	if (ar->hist)
		lin = ar->hist;

	add_node_end(&lin, s, n);
	if (!ar->hist)
		ar->hist = lin;
	return (0);
}
/**
 * _updhist - changes the count in linked list for history.
 * @ar:  the struct l_ar of arguments of shell.
 * Return: the  value of ar->ihist
 */
int _updhist(l_ar *ar)
{
	int i = 0;
	l_s *l;

	l = ar->hist;
	while (l)
	{
		l->n = i++;
		l = l->next;
	}
	return (ar->ihist = i);
}
/**
 * _whist - creates or appends (to) a history file.
 * @ar:  the struct l_ar of arguments of shell.
 * Return: 1 on success, or -1.
 */
int _whist(l_ar *ar)
{
	ssize_t fd;
	l_s *l = NULL;
	char *fname;

	fname = _gethistf(ar);
	if (fname == NULL)
		return (-1);

	fd = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (fd == -1)
		return (-1);
	for (l = ar->hist; l; l = l->next)
	{
		_putsinfd(l->s, fd);
		_putinfd('\n', fd);
	}
	_putinfd(BUFFER_FLSH, fd);
	close(fd);
	return (1);
}
