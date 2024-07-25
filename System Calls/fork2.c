#include <stdio.h>
#include <unistd.h>

int main() {
    // Create a new process
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("I'm the child\n");
    } else {
        // Parent process
        printf("I'm the parent\n");
    }

    return 0;
}
