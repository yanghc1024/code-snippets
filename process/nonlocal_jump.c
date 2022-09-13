#include <setjmp.h>

static jmp_buf env;

static void f2() {
    longjmp(env, 2); // unwind the stack
}

static void f1(int var) {
    if (var == 1) {
        longjmp(env, 1);
    }
    f2();
}

int main(int argc, char *argv[]) {

}
