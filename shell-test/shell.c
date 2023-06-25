#include "shell.h"

void i_mode(){
	char *line, **tk;
	ssize_t fd;
	int r, num_com = 0;
	do {
		line = NULL;
		tk = NULL;
		fd = 0;
		num_com++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		signal(SIGINT, _handler_ctrlc);
		fd = _getline(&line);
		if (fd == -1 || fd == 0)
		{
			pnewline(line);
			break;
		}
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		line = dnewline(line);
		tk = _strtok(line, " ");
		r = isbuiltin(tk);
		if (r == 1)
			break;
		r = isexecute(tk);
	} while (1); 
	return(r);
}