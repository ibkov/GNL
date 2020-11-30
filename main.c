#include <stdio.h>
#include "get_next_line.h"
#include <string.h>

int main() {
	int fd;
	char *a;

	fd = open("/Users/igorkovalenko/CLionProjects/GNL/123.txt", O_RDONLY);
	fd = 1;
    get_next_line(fd, &a);
	printf("%s\n", a);
	printf("%d", strcmp(a, "dfgdfgdfg"));
//	get_next_line(fd, &a);
//	printf("%s\n", a);
//	get_next_line(fd, &a);
//	printf("%s", a);
//	get_next_line(fd, &a);
//	printf("%s", a);
//	get_next_line(fd, &a);
//	printf("%s", a);
	return 0;
}
