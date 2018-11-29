#include <signal.h>
#include <stdio.h>
#include "../communication/pipe.h"

void signalFromChild(int i) {
    signal(SIGUSR1, signalFromChild); /* reset signal */
    printf("Message from child!!!\n");
}

void startServer(int childPid, int childToParent[2], int parentToChild[2]) {

    char input_str[] = "Test lorem";
    signal(SIGUSR1, signalFromChild);
    for (int i = 0; i < 4; ++i) {
        char messageFromChild[100];
        sendMessage(input_str, parentToChild);

        receiveMessage(messageFromChild, childToParent);

        printf("String: %s\n", messageFromChild);

    }
}

