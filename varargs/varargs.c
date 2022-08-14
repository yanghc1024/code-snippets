#include <stdarg.h>

int addNumber(int count, ...) {
    int sum = 0;
    va_list args;

    va_start(args, first);
    for (int i = 0; i < n; ++i)
        sum += va_arg(args, int);
    va_end(args);

    return sum;
}

int main(int argc, char *argv[]) {
    int sum = addNumber(5, 1, 2, 3, 4, 5);
}
