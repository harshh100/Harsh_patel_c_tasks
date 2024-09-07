#include <stdio.h>

int main() {
    int x = 0;

start:
    if (x < 5) {
        printf("x = %d\n", x);
        x++;
        goto start;
    }

    if (x == 5) {
        goto end;
    }

    printf("This will never be printed.\n");

end:
    printf("End of program.\n");
    return 0;
}

