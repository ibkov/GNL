#include <stdio.h>
#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>

int main() {
	int fd;
	char *a;

	fd = open("/Users/igorkovalenko/CLionProjects/GNL/123.txt", O_RDONLY);
	while (get_next_line(fd, &a)) {
		printf("%s\n", a);
	}
//	printf("%d", fd);
//	get_next_line(fd, &a);
//	printf("%s", a);
//	get_next_line(fd, &a);
//	printf("%s", a);
//	get_next_line(fd, &a);
//	printf("%s", a);
	return 0;
}
