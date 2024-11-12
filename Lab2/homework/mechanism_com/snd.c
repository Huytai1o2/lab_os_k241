#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int snd(char *command, char *fifo_path)
{
    const char *fifo_path = "abc_fifo_name";
    char message[100];

    // make sure the message is null-terminated
    message[0] = '\0';
    strcpy(message, command);

    size_t len = strlen(message);
    while (len > 0 && message[len - 1] == '\n')
    {
        message[len - 1] = '\0';
        len--;
    }

    // printf("Enter your message: ");
    // fgets(message, sizeof(message), stdin);

    // Open the FIFO for writing
    int fd = open(fifo_path, O_WRONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Write to the FIFO
    int num_bytes = write(fd, message, sizeof(message));
    if (num_bytes == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    printf ("Sent: %s\n", message);

    close(fd);
    return 0;
}