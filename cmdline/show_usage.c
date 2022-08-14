void showUsage() {
    // Do nothing.
}

int main(int argc, char *argv[]) {

    if (argc != 2 || strcmp(argv[1], "--help") == 0) {
        showUsage();
    }

    return 0;
}
