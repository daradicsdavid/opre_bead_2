#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "server/client/client.h"
#include "server/communication/pipe.h"
#include "server/server.h"
#include "server/model/boolean.h"
#include "server/read/read.h"

void signalFromChild(int pid);


int main() {
    int parentProcessId = getpid();
    int parentToChild[2];
    int childToParent[2];


    if (!setupPipes(parentToChild, childToParent)) {
        exit(1);
    }

    //boolean simulation = readYesNo("Szeretné szimulációs módban futtatni a társaságot?\n");
    boolean simulation = true;
    int pid = fork();
    if (pid == 0) {
        startClient(parentProcessId, childToParent, parentToChild);
    } else {
        if (simulation) {
            startSimulationServer(pid, childToParent, parentToChild);
        }
    }
    return 0;
}

