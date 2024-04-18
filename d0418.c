#include <stdio.h>
#include <stdlib.h>

void today_luck(int* point, int* total_loss, int key, int* cnt) {
    int p = rand() % 20 + 1;
    printf("���� %2d ", p);
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

    printf("60�������� ����: 1~20 ����: ");
    scanf("%d", &k);
    while (point >=  0)
    {   
        today_luck(&point, &total_loss, k, &cnt);
        cnt++;
        printf("%2d��������� %3d����\n", total_loss, point);
    }

    printf("������ %d����!\n", point);

    return 0;
}