#include <stdio.h>

int main() {
    FILE* fp;

    char direction;
    int clicks, dial = 50, password = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File not found. Exiting...\n");
        return 0;
    }


    int fs = fscanf(fp, "%c%d\n", &direction, &clicks);
    printf("Dial: %d, fs: %d\n", dial, fs);

    while (fs == 2) {
        dial += clicks * (direction == 'R' ? 1 : -1);
        if (dial % 100 == 0) password++;
        fs = fscanf(fp, "%c%d\n", &direction, &clicks);
        printf("Direction: %c, Clicks: %d, Dial: %d, mod: %d, fs: %d\n", direction, clicks, dial, (dial % 100), fs);
    }

    printf("Password: %d\n", password);

    return 0;
}
