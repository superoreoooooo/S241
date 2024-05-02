#include <stdio.h>
#include <stdlib.h>

#define HGT 24
#define WTH 60

double print_score(int score[5], int size)
{
    int sum = 0, k;
    for (k = 0; k < size; k++)
    {
        printf("%d = %d점, ", k, score[k]);
        sum = sum + score[k];
    }
    return (sum / size);
}

void p1() {
    int score[5] = {75, 84, 13, 96, 46};
    double ave;
    ave = print_score(score, 5);
    printf("\n평균 = %.1lf", ave);
}

void p2() {
    char mt[HGT][WTH];

    for (int y = 0; y < HGT; y++) {
        for (int x = 0; x < WTH; x++) {
            mt[y][x] = ' ';
        }
    }

    for (int dx = 0; dx < WTH; dx++) {
        int len = rand() % HGT + 1;
        for (int dy = 0; dy < len; dy++) {
            mt[dy][dx] = 'o';
        }
    }

    for (int y = 0; y < HGT; y++) {
        for (int x = 0; x < WTH; x++) {
            printf("%c", mt[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    //p1();
    p2();
    return 0;
}