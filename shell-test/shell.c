#include "shell.h"

void i_mode(l_u *e){
	char *line, **tk;
	ssize_t fd;
	int r, num_com = 0;
	while(1) {
		line = NULL;
		tk = NULL;
		fd = 0;
		num_com++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		printf("shell.h line \n");
		signal(SIGINT, _handler_ctrlc);
		fd = _getline(line, STDOUT_FILENO);
		printf("shell.h command=%s\n", line);
		if (fd == -1 || fd == 0)
		{
			printf("shell.c print new line \n");
			pnewline(line);
			break;
		}
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		line = dnewline(line);
		tk = _strtok(line, ' ');
		r = isbuiltin(tk);
		if (r == 1)
			break;
		r = isexecute(tk, e);
	}
}
