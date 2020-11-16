#include <stdio.h>
#include "get_next_line.h"

int main() {
	int fd;
	char **a;

	fd = open("/Users/burswyck/Desktop/GNL/123.txt", O_RDONLY);
	get_next_line(fd, a);
	return 0;
}
