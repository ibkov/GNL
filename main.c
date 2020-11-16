#include <stdio.h>
#include "get_next_line.h"

int main() {
	int fd;
	char **a;
	char buf[100];

	fd = open("/Users/igorkovalenko/CLionProjects/GNL/123.txt", O_RDONLY);

	printf("%d\n", fd);
//	printf("%d\n", read(fd, buf, 13));
//	printf("%s\n",  buf);
	get_next_line(fd, a);
	printf("%s", a[0]);
	return 0;
}
