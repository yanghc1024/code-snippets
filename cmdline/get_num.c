#include <stdlib.h>

/**
 * 将字符串解析为浮点数，返回值为 double 类型。
 * 其他类似的函数有: strtof, strtold, strtol, strtoll, strtoul, strtoull
 */
double getDouble(const char *raw_number) {
    char *endptr = NULL; 

    errno = 0;
    double number = strtod(raw_number, &endptr);
    if (errno != 0) { // 由于 strtod 在无法做有效转换时返回 0，所以需要检查 errno。
        exit(EXIT_FAILURE);
    }

    if (endptr == NULL || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return number;
}

// base 限制为 [0, 36] (0-9, a-z/A-Z).
long getLong(const char *raw_number, int base) {
    char *endptr = NULL;

    errno = 0;
    long number = strtol(raw_number, &endptr, base);
    if (errno != 0) {
        exit(EXIT_FAILURE);
    }

    if (endptr == NULL || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return number;
}

int main(int argc, char *argv[]) {
    double number = getDouble(" +3.14");
    double integer = getLong(" -02022", 8);
}
