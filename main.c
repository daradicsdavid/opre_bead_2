#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "client/client.h"
#include "communication/pipe.h"
#include "server/server.h"

void signalFromChild(int pid);


int main() {
    int parentProcessId = getpid();
    int parentToChild[2];
    int childToParent[2];

    if (!setupPipes(parentToChild, childToParent)) {
        exit(1);
    }

    int pid = fork();
    if (pid == 0) {
        startClient(parentProcessId, childToParent, parentToChild);
    } else {
        startServer(pid, childToParent, parentToChild);
    }
    return 0;
}

