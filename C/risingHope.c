int rising_hope(char *R) {
    int ret = 0, len = strlen(R);
    for (int i = 0; i < len; i++) {
        if (R[i] == 'N') ret--;
        if (R[i] == 'P') ret++;
    }

    return ret;
}
