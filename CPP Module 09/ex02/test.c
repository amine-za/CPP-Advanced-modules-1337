#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char buf[100];

    while (1)
    {
        fcntl(0, F_SETFL, O_NONBLOCK);
        read(socket_fd, buf, 100);
        
        if (buf[0])
        {
            printf("%s\n", buf);
            return (0);
        }
        printf("Hello\n");
    }
    return (0);
}