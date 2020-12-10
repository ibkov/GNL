#include <stdio.h>
#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>

int main() {
	int fd;
	char *a;

	fd = open("/Users/burswyck/Desktop/GNL/user_output_buff_16_one_big_fat_line.txt", O_RDONLY);
	while (get_next_line(fd, &a)) {
		printf("%s\n", a);
		free(a);
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
