#include <stdio.h>
#include <stdlib.h>

void fry(int min, double milk);
void swap(int* one, int* two);
double ret_cent(double len);
void soundMeter(int s);
void luck1(int pick, int* tf, int try);
void luck2(int* point, int* total_loss, int key, int* cnt);

int main() {
    //1��
    fry(6, 40.5);
    
    //2��
    int first = 7, second = 24;
    swap(&first, &second);
    printf("f=%d, s=%d\n", first, second);

    //3��
    double conv, inch;
    printf("��ȯ�� ��ġ �� : ");
    scanf("%lf", &inch);


    //4��
    conv = ret_cent(inch);
    printf("%.2lf inch = %.2lf cm\n", inch, conv);

    //5��
    soundMeter(6);

    //6��
    int try = 1, pick, tf = 0;
    printf("������ � 1~20 ���� : ");
    scanf("%d", &pick);
    while (tf == 0) {
        luck1(pick, &tf, try++);
    }
    if (try <= 5) {
        printf("\n������ ����� ��!\n\n");
    } else {
        printf("\n������ �����ϼ���!\n\n");
    }

    //7��
    int k, point, cnt, total_loss, try_2;

    point = 60;
    cnt = 1;
    total_loss = 0;
    try_2 = 1;
    
    for (int i = 0; i < 3; i++) {
        printf("%d�������� ����: 1~20 ����: ", point);
        scanf("%d", &k);
        luck2(&point, &total_loss, k, &cnt);
        cnt++;
        printf("%2d��������� %3d����\n", total_loss, point);
    }

    printf("������ %d����!\n", point);

    return 0;
}

void fry(int min, double milk) {
    printf("%.1lf�� ������ ����\n", milk);
    printf("Ƣ��� ������\n");
    printf("%d�� Ƣ���\n", min);
}

void swap(int* one, int* two) {
    int tmp = *one;
    *one = *two;
    *two = tmp;
}

double ret_cent(double len) {
    return len * 2.54;
}

void soundMeter(int s) {
    for (int i = 0; i < 100; i++) {
        system("cls");
        for (int cnt = 1; cnt <= s; cnt++) {
            for (int len = 0; len < rand() % 80; len++) {
                printf("��");
            }
            printf(" %d\n-------------------------\n", cnt);
        }
    }
}

void luck1(int pick, int* tf, int try) {
    int num = rand() % 20 + 1;
    printf("��� �� %2d ���� �� %2d\n", num, try);
    if (num == pick) {
        *tf = 1;
    }
}

void luck2(int* point, int* total_loss, int key, int* cnt) {
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