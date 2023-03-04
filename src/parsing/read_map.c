#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

char **read_map(int fd)
{
	int len;
	char **map;
	char *line;
	map = NULL;
	line = NULL;
	len = 0;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		len++;
		free(line);
	}
	map = malloc(sizeof(char *) * len);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		*map = line;
		(*map)++;
	}
	return map;
}
