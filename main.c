#include <stdio.h>
#include "get_next_line.h"

int main() {
	int fd;
	char *a;

	fd = open("/Users/burswyck/Desktop/GNL/123.txt", O_RDONLY);
	printf("%d\n", fd);
	get_next_line(fd, &a);
	free(a);
	printf("%s\n\n", a);
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
