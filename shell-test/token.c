#include "shell.h"

char **_strtok(char *s, char d)
{
    int t, len1 = 0, len2 = 0,i = 0, j = 0, k, begin = 0;
	char **tokens;

	while (*s == d)
		s++;
	len1 = _getsizetok(s, d, &t);
	tokens = malloc(sizeof(char *) * (len1 + 1));
	if (tokens == NULL)
		return (NULL);
	while(i < t)
	{
		if (s[i] != d)
		{
			len2++;
			tokens[j] = malloc(sizeof(char) * (len2 + 1));
			if (tokens[j] == NULL)
				return (NULL);
			for(k = begin; k <= i; k++)
				tokens[j][k] = s[k];
			tokens[j][k] = '\0';
			}
		else if ((s[i + 1] != d) && (s[i + 1] != '\0'))
		{
			len2 = 0;
			begin = i;
			j++;
		}
		i++;
	}
	tokens[j + 1] = NULL;
	return (tokens);
}
int _getsizetok(char *s, char d, int *t)
{
	int i = 1, r = 0;
	if (s[1] != '\0')
		return(1);
	while (s[i] != '\0')
	{
		if ((s[i] == d) && (s[i + 1] == '\0'))
		{
			r--;
			*t = i + 1;
		}
		if ((s[i - 1] == d) && (s[i] != d))
			r++;
		i++;
	}
	return (r);
}
void _freetok(char **tk)
{
	int i = 0;

	while (tk[i] != NULL)
	{
		free(tk[i]);
		i++;
	}
	free(tk);
}
