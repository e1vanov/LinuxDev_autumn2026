#include <stdio.h>
#include <stdlib.h>

void
range(int m, int n, int s)
{
    for (int i = m; i < n; i += s) 
        printf("%d\n", i);
}

int
main(int argc, char *argv[])
{
    int m = 0, n, s = 1;
    if (argc == 1) {
        printf("range N     -> [0,   1, ..., N-1]\n");
        printf("range M N   -> [M, M+1, ..., N-1]\n");
        printf("range M N S -> [M, M+S, ..., N-1]\n");
    } else if (argc == 2) {
        n = atoi(argv[1]);
    } else if (argc == 3) {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    } else if (argc == 4) {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
        s = atoi(argv[3]);
    } else if (argc > 4) {
        printf("Too much args\n");
        return 0;
    }
    range(m, n, s);
    return 0;
}
