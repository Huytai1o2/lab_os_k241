#include <stdio.h>
#include <string.h>

int snd(char *command);
int rcv();

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "snd") == 0)
    {
        char message[100];
        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);
        return snd(message);
    }
    else if (strcmp(argv[1], "rcv") == 0)
    {
        return rcv();
    }
    else
    {
        printf("Invalid command\n");
        return 1;
    }
    return 0;
}
