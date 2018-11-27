#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>

void signalFromChild(int pid);


void sendMessage(char message[], int pipe[]) {
    printf("Sending message: %s\n", message);
    close(pipe[0]);
    // Write concatenated string and close writing end
    write(pipe[1], message, strlen(message) + 1);
}

void receiveMessage(char *message, int pipe[]) {
    close(pipe[1]);
    read(pipe[0], message, 100);
    printf("Receiving message: %s\n", message);
}

int main() {
    int ppid = getpid();
    char input_str[100] = "forgeeks.org";

    int parentToChild[2];  // Used to store two ends of first pipe
    int childToParent[2];  // Used to store two ends of second pipe

    if (pipe(parentToChild) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }
    if (pipe(childToParent) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }


    int pid = fork();
    if (pid == 0) {
        //Child
//        signal(SIGQUIT, signalFromChild);
        while (true) {
            char messageFromParent[100] = "";

            receiveMessage(messageFromParent, parentToChild);
            sendMessage(messageFromParent, childToParent);
            kill(ppid, SIGUSR1);
            sleep(1);
        }

        //exit(0);

    } else {
        //Parent
        signal(SIGUSR1, signalFromChild);
        for (int i = 0; i < 4; ++i) {
            char messageFromChild[100];
            sendMessage(input_str, parentToChild);

            receiveMessage(messageFromChild, childToParent);

            printf("String: %s\n", messageFromChild);

        }

//        printf("Terminating child!\n");
//        kill(pid, SIGQUIT);
    }
    return 0;
}

void signalFromChild(int i) {
    signal(SIGUSR1, signalFromChild); /* reset signal */
    printf("Message from child!!!\n");
}