int addition(char str[]) {
    int sum = 0;
    char *c;
    c = strtok(str, "+");

    while (c != NULL) {
        sum += atoi(c);
        c = strtok(NULL, "+");
    }
    return sum;
}