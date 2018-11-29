#include <signal.h>
#include <zconf.h>
#include "../communication/pipe.h"

void startClient(int parentProcessId, int childToParent[2], int parentToChild[2]) {
    while (1) {
        char messageFromParent[100] = "";

        receiveMessage(messageFromParent, parentToChild);
        sendMessage(messageFromParent, childToParent);
        kill(parentProcessId, SIGUSR1);
        sleep(1);
    }
}
