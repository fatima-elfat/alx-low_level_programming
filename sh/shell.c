#include "shell.h"
/* void n_i_mode(char **argv, l_u *e){} */
/**
 * i_mode - ...
 * @e: ...
 */
void i_mode(l_u *e)
{
	char *line, **tk;
	ssize_t fd;
	int r, num_com = 0;

	while (1)
	{
		line = NULL;
		tk = NULL;
		fd = 0;
		num_com++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		signal(SIGINT, _handler_ctrlc);
		fd = _getline(&line, STDOUT_FILENO);
		if (fd == -1 || fd == 0)
		{
			pnewline(line);
			free(line);
			exit(fd);
		}
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		line = dnewline(line);
		tk = _strtok(line, " ");
		printf("here %s\n", tk[0]);
		r = isbuiltin(tk, e);
		if (r == 1)
			break;
		r = isexecute(tk, e);
	}
	free(line);
	_freetok(tk);
}
