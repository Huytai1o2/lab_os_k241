#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int snd(char *command);
int rcv();



int main(int argc, char *argv[], char *envp[])
{
    char *msg = malloc(100*sizeof(char));
    char *filepath = malloc(100*sizeof(char));
    int i = 0;
    int fd;

    



    while(i < argc){

    if (strcmp(argv[i], "-r")==0)
    {
        if (strcmp(filepath, "") == 0)
        {
            printf("Missing file_path");
            return -1;
        }
        fd = open(filepath, O_RDONLY);
        read(fd, msg, 100);
        printf("%s\n", msg);
    }

    else if (strcmp(argv[i], "-w") ==0)
    {
        i++;
        strcpy(msg, argv[i]);
        if (strcmp(filepath, "") == 0)
        {
            printf("Missing file_path");
            return -1;
        }
        fd = open(filepath, O_WRONLY);
        write(fd, msg, 100);
    }

    else if (strcmp(argv[i], "-filepath")==0)
    {
        i++;
        strcpy(filepath, argv[i]);
    }

    i++;
    }
}
