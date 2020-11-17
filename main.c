#include <stdio.h>
#include "get_next_line.h"

int main() {
	int fd;
	char *a;

	fd = open("/Users/igorkovalenko/CLionProjects/GNL/123.txt", O_RDONLY);
	printf("%d\n", fd);
	get_next_line(fd, &a);
	printf("%s", a);
	return 0;
}
