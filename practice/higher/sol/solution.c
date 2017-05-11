#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a >= b) {
        printf("LARRY\n");
    } else {
        printf("KEVIN\n");
    }
    return 0;
}

