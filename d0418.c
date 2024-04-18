#include <stdio.h>
#include <stdlib.h>

void today_luck(int* point, int* total_loss, int key, int* cnt) {
    int p = rand() % 20 + 1;
    printf("행운수 %2d ", p);
    if (key == p) {
        *point += 60;
        *cnt = 0;
    } else {
        *point -= *cnt;
        *total_loss -= *cnt;
    }
}

int main() {
    int k, point, cnt, total_loss, try;

    point = 60;
    cnt = 1;
    total_loss = 0;
    try = 1;

    printf("60만점부터 시작: 1~20 선택: ");
    scanf("%d", &k);
    while (point >=  0)
    {   
        today_luck(&point, &total_loss, k, &cnt);
        cnt++;
        printf("%2d만점사라짐 %3d만점\n", total_loss, point);
    }

    printf("오늘은 %d만점!\n", point);

    return 0;
}