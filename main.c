#include <stdio.h>
#include "get_next_line.h"

int main() {
	int fd;
	char **a;
	char buf[100];

	fd = open("/Users/igorkovalenko/CLionProjects/GNL/123.txt", O_RDONLY);
	get_next_line(fd, a);
	return 0;
}
