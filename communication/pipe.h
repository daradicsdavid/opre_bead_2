#ifndef OP_BEAD_PIPE_H
#define OP_BEAD_PIPE_H

int setupPipes(int parentToChild[], int childToParent[]);

void sendMessage(char message[], int pipe[]);

void receiveMessage(char *message, int pipe[]);

#endif //OP_BEAD_PIPE_H