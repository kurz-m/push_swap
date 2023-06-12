#include <stdio.h>
#include <strings.h>
#include <unistd.h>

int	main(void)
{
	char	buff[6];
	ssize_t	byte;

	
	byte = read(0, buff, sizeof(buff));
	if (strncmp(buff, "sa\n", byte) == 0)
		printf("correct input\n");
	return (0);
}
