#include <stdio.h>
#include "get_next_line.h"

int main() {
	int fd;

	fd = open("/Users/burswyck/Desktop/GNL/123.txt", O_WRONLY);
	ft_putstr_fd("123", fd);
	return 0;
}
