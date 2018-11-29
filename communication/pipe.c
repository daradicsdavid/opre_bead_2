#include <zconf.h>
#include <stdio.h>
#include <string.h>

int setupPipes(int parentToChild[], int childToParent[]) {
    if (pipe(parentToChild) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 0;
    }
    if (pipe(childToParent) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 0;
    }
    return 1;
}

void sendMessage(char *message, int *pipe) {
    printf("Sending message: %s\n", message);
    close(pipe[0]);
    // Write concatenated string and close writing end
    write(pipe[1], message, strlen(message) + 1);
}

void receiveMessage(char *message, int *pipe) {
    close(pipe[1]);
    read(pipe[0], message, 100);
    printf("Receiving message: %s\n", message);
}
