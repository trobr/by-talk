#include <stdio.h>

int main()
{
    /* 我的第一个 C 程序 */
    int arr[][10] = {{0, 0, 30, 20, 115, 11111, 0, 4321},
                     {3000, 20, 60322, 0, 333, 2, 12334, 33}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%-7d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}