#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int rcv(char)
{
    const char *fifo_path = "abc_fifo_name";
    char buffer[100];
    buffer[0] = '\0';

    // Open the FIFO for reading
    int fd = open(fifo_path, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Read from the FIFO
    int num_bytes = read(fd, buffer, sizeof(buffer) - 1);
    if (num_bytes == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[num_bytes] = '\0';
    printf("Received: %s\n", buffer);

    // Close the FIFO
    close(fd);
    return 0;
}