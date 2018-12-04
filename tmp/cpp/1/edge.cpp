
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define M 10
#define N 19 //定义分辨率

//检测方向属性
void main() // image[M][N]输入图像分辨率为M×N,
{

    int xmin = 0, xmax = 0, ymin = 0, ymax = 0; //读入目标位置坐标
    int n = 0;
    int e = 0;
    int f = 0;
    int a = 0, b = 0, c = 0,
        d = 0; // a,b,c,d为像素点在0°、45°、90°、135°方向的边缘强度
    int max = 0; //中间值
    // int pix8[M][N]={0};

    int pix8[M][N] = {
        {0, 1, 2, 2, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 2, 1, 1, 1, 1, 0, 0},
        {4, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 3, 1, 6, 2, 5, 1, 1, 0},
        {3, 1, 2, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 4, 2, 5, 1, 1, 0},
        {0, 2, 1, 3, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 5, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 2, 1, 3, 1, 1, 0},
        {0, 0, 0, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {8, 0, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0}};

    int bianyuan[M][N] = {0};
    int image[M][N] = {
        {0, 1, 2, 2, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0, 0},
        {4, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0},
        {3, 1, 2, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 1, 1, 1, 0},
        {0, 2, 1, 3, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 2, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0},
        {0, 0, 0, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {8, 0, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0}};

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            bianyuan[i][j] = 0;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            if (i < 2 || j < 2 || i > M - 3 || j > N - 3) //边界点处理
                bianyuan[i][j] = 1;

            else {
                a = image[i - 1][j - 2] + 3 * image[i - 1][j - 1] +
                    8 * image[i - 1][j] + 3 * image[i - 1][j + 1] +
                    image[i - 1][j + 2] - image[i + 1][j - 2] -
                    3 * image[i + 1][j - 1] - 8 * image[i + 1][j] -
                    3 * image[i + 1][j + 1] - image[i + 1][j + 2];

                b = image[i - 2][j] + 8 * image[i - 1][j - 1] +
                    3 * image[i - 1][j] + image[i][j - 2] -
                    3 * image[i][j - 1] + image[i][j + 1] -
                    3 * image[i + 1][j] - 8 * image[i + 1][j + 1] -
                    image[i + 2][j];

                c = image[i - 2][j - 1] - image[i - 2][j + 1] +
                    3 * image[i - 1][j - 1] - 3 * image[i - 1][j + 1] +
                    8 * image[i][j - 1] - 8 * image[i][j + 1] +
                    3 * image[i + 1][j - 1] - 3 * image[i + 1][j + 1] +
                    image[i + 2][j - 1] - image[i + 2][j + 1];

                d = image[i - 2][j] + 3 * image[i - 1][j] +
                    8 * image[i - 1][j + 1] - image[i][j - 2] -
                    3 * image[i][j - 1] + 3 * image[i][j + 1] +
                    image[i][j + 2] - 8 * image[i + 1][j - 1] -
                    3 * image[i + 1][j] - image[i + 2][j];

                max = a > b ? a : b;
                max = max > c ? max : c;
                max = max > d ? max : d; //求a,b,c,d最大值

                /*ROI区域处理*/
                if (xmin <= j <= xmax && ymin <= i <= ymax) {
                    if (a < 2 && b < 2 && c < 2 &&
                        d < 2) //判断ROI区域是否包含边缘点,如果a,b,c,d都小于2,则认为不包含边缘点,置像素值0.
                        bianyuan[i][j] = 0;

                    else {
                        if (a == max)
                            bianyuan[i][j] = 5; // 0°方向属性像素值
                        else if (b == max)
                            bianyuan[i][j] = 6; // 45°方向属性像素值
                        else if (c == max)
                            bianyuan[i][j] = 7; // 90°方向属性像素值
                        else
                            bianyuan[i][j] = 8; // 135°方向属性像素值
                    }
                }

                /*非ROI区域处理*/
                else {
                    if (a < 2 && b < 2 && c < 2 &&
                        d < 2) //判断是否包含边缘点,如果a,b,c,d都小于2,则认为不包含边缘点,置像素值0.
                        bianyuan[i][j] = 0;
                    else {
                        if (a == max)
                            bianyuan[i][j] = 1; // 0°方向属性像素值
                        else if (b == max)
                            bianyuan[i][j] = 2; // 45°方向属性像素值
                        else if (c == max)
                            bianyuan[i][j] = 3; // 90°方向属性像素值
                        else
                            bianyuan[i][j] = 4; // 135°方向属性像素值
                    }
                }
            }
        }

    //输出打印
    printf("\nThe origianl image is:\n");
    for (int i = 0; i < M; i++) {
        printf("\n");
        for (int j = 0; j < N; j++)
            printf("%-4d", image[i][j]);
    }

    printf("\nThe edge image is:\n");
    for (int i = 0; i < M; i++) {
        printf("\n");
        for (int j = 0; j < N; j++)
            printf("%-4d", bianyuan[i][j]);
    }

    //计算8×8块像素权重值

    for (int i = 0; i < M - 1 - 8; i += 8){
        for (int j = 0; j < N - 1 - 8; j += 8) {
            n = 0;
            a = 0;
            b = 0;
            c = 0;
            d = 0;
            e = 0;

            for (int h = 0; h < 8; h++) {
                for (int k = 0; k < 8; k++) {
                    if (bianyuan[i + h][j + k] > 0) //统计总边缘点数
                        n++;
                    if (bianyuan[i + h][j + k] == 1) //统计每种方向的边缘数
                        a++;
                    if (bianyuan[i + h][j + k] == 2)
                        b++;
                    if (bianyuan[i + h][j + k] == 3)
                        c++;
                    if (bianyuan[i + h][j + k] == 4)
                        d++;

                    if (h == 7 && k == 7) {
                        if (a > 5) //统计总的方向数
                            e++;
                        if (b > 5)
                            e++;
                        if (c > 5)
                            e++;
                        if (d > 5)
                            e++;

                        if (n > 24)
                            f = 1;
                        if (n <= 24)
                            f = 0;

                        if (e == 0)
                            for (int m = 0; m < 8; m++)
                                for (int r = 0; r < 8; r++)
                                    pix8[i + m][j + r] = 0;
                        if (e == 1)
                            for (int m = 0; m < 8; m++)
                                for (int r = 0; r < 8; r++)
                                    pix8[i + m][j + r] = 2;
                        if (e == 2)
                            for (int m = 0; m < 8; m++)
                                for (int r = 0; r < 8; r++)
                                    pix8[i + m][j + r] = 2 - f;
                        if (e >= 3)
                            for (int m = 0; m < 8; m++)
                                for (int r = 0; r < 8; r++)
                                    pix8[i + m][j + r] = 1 - f;
                    }
                }
            }
        }
    }

    printf("\nThe pix8 image is:\n");
    for (int i = 0; i < M; i++) {
        printf("\n");
        for (int j = 0; j < N; j++)
            printf("%-4d", pix8[i][j]);
    }

    system("pause");
}
