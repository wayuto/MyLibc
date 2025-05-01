#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *lib_paths = getenv("LD_PATHS");
    if (lib_paths == NULL) {
        fprintf(stderr, "Error: LD_PATHS environment variable not set\n");
        return EXIT_FAILURE;
    }

    char *args[1024] = {
        "gcc",
        "-Wno-builtin-declaration-mismatch",
        "-I",
        NULL,
        NULL
    };

    args[2] = "-I";
    args[3] = lib_paths;
    int index = 4;

    for (int i = 1; i < argc && index < 1024 - 1; i++) {
        args[index++] = argv[i];
    }

    char *so_paths = getenv("SO_PATHS");
    if (so_paths != NULL) {
        char *token = strtok(so_paths, ":");
        while (token != NULL && index < 1024 - 1) {
            args[index++] = token;
            token = strtok(NULL, ":");
        }
    } else {
        fprintf(stderr, "Error: SO_PATHS environment variable not set\n");
        return EXIT_FAILURE;
    }

    args[index] = NULL;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        execvp("gcc", args);
        perror("execvp failed");
        _exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return WIFEXITED(status) ? WEXITSTATUS(status) : EXIT_FAILURE;
    }
}