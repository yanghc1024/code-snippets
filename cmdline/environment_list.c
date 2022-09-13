#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

void modifyEnv(int num, char *env[]) {
    clearenv();
    for (int i = 0; i < num; ++i) {
        if (putenv(*env) != 0) { // Add a new variable
            exit(EXIT_FAILURE);
        } 
    }
    int override = 1;
    setenv("Foo", "Bar", override); 
    unsetenv("Foo");
}

int main(int argc, char *argv[]) {
    for (char **ep = environ; *ep != NULL; ++ep) {
        puts(*ep);
    }
    return 0;
}
