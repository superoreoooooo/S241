#include <stdio.h>
#include <stdlib.h>
#define X_MAX 70
#define Y_MAX 40
#define UFO_LENGTH 5

void p1() {
    printf("====1====\n");
    system("timeout 3 > NULL");

    int num;

    do {
        printf("¦�� �Է� ������ �ݺ�: ");
        scanf("%d", &num);
    } while (num % 2 != 0);

    printf("%d�� ¦��\n", num);
}

void p2() {
    system("cls");
    system("timeout 3 > NULL");
    printf("====2====\n");
    system("timeout 3 > NULL");

    for (int i = 0; i < 70; i++) {
        system("cls");
        if (i % 2 == 0) {
            printf("\n");
        }
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("<#=#>\n");
        system("timeout 1 > NULL");
    }
}

void p3() {
    system("cls");
    system("timeout 3 > NULL");
    printf("====3====\n");
    system("timeout 3 > NULL");

    for (int i = 0; i < 140; i++) {
        system("cls");
        if (i % 2 == 0) {
            printf("\n");
        }
        if (i < 70) {
            for (int j = 0; j < i; j++) {
                printf(" ");
            }
        }
        else {
            for (int j = 0; j < 140 - i; j++) {
                printf(" ");
            }
        }

        printf("<#=#>\n");
        system("timeout 1 > NULL");
    }
}

void p4() {
    system("cls");
    system("timeout 3 > NULL");
    printf("====4====\n");
    system("timeout 3 > NULL");

    for (int i = 0; i < 26; i++) {
        system("cls");

        for (int j = 0; j < i; j++) {
            printf("\n");
        }

        if (i % 2 == 0) {
            printf("     ");
        }

        printf("<#=#>\n");
        system("timeout 1 > NULL");
    }
}

void p5() {
    system("cls");
    system("timeout 3 > NULL");
    printf("====5====\n");
    system("timeout 3 > NULL");

    int x, y;

    for (int cnt = 0; cnt < 70; cnt++) {
        system("cls");

        x = rand() * (X_MAX - UFO_LENGTH) / (RAND_MAX + 1);
        y = rand() * (Y_MAX - 1) / (RAND_MAX + 1);

        //printf("%d %d", x, y);

        for (int dy = 0; dy < y; dy++) {
            printf("\n");
        }

        for (int dx = 0; dx < x; dx++) {
            printf(" ");
        }

        printf("<#=#>");
        system("timeout 1 > NULL");
    }
}

void p6() {

    system("cls");
    system("timeout 3 > NULL");
    printf("====6====\n");
    system("timeout 3 > NULL");

    int min, sec;
    printf("�� �� �Է�: ");
    scanf("%d %d", &min, &sec);
    for (; min >= 0; min--) { // for: ��(min)�� ��� 
        for (; sec >= 0; sec--) { // for: ��(sec)�� ��� 
            system("cls"); // ȭ�� �����
            printf("%d�� : %d��\n", min, sec);
            system("timeout 1 > NULL"); // 1�� ���߱�
        }
        sec = 59; // ���ο� 1�� ����
    } // End of for min
    printf("�׸� Ƣ��!\n");
}

void p7() {
    system("cls");
    system("timeout 3 > NULL");
    printf("====7====\n");
    system("timeout 3 > NULL");

    int com, user;
    int chip = 10, bet;

    srand((unsigned)time(NULL));
    while (chip > 0) {
        user = rand() % 10 + 1;
        com = rand() % 10 + 1;

        printf("chip=%d you=%d ����(0������): ", chip, user);
        scanf("%d", &bet);

        if (bet == 0) {
            printf("com=%d: ���� ����! chip=%d\n", com, chip);
        }
        else if (user >= com) {
            chip += bet;
            printf("com=%d: ����� ��! chip=%d\n", com, chip);
        }
        else {
            chip -= bet;
            printf("com=%d: ��ǻ�� ��! chip=%d\n", com, chip);
        }
    }
}

void p8() {
    system("cls");
    system("timeout 3 > NULL");
    printf("====8====\n");
    system("timeout 3 > NULL");

    int com, user;
    int chip = 10, bet;

    srand((unsigned)time(NULL));
    while (1) {
        user = rand() % 10 + 1;
        com = rand() % 10 + 1;

        printf("chip=%d you=%d ����(0������): ", chip, user);
        scanf("%d", &bet);

        if (user >= com) {
            chip += bet;
            printf("com=%d: ����� ��! chip=%d\n", com, chip);
        }
        else {
            chip -= bet;
            printf("com=%d: ��ǻ�� ��! chip=%d\n", com, chip);
        }
        if (chip == 0 || chip == 30) {
            break;
        }
    }
}

void p9() {
    system("cls");
    system("timeout 3 > NULL");
    printf("====9====\n");
    system("timeout 3 > NULL");

    int min, sec;
    int limit, k;
    printf("�� �� �Է�: ");
    scanf("%d %d", &min, &sec);
    limit = 60 * min + sec;
    for (k = limit; k > 0; k--) {
        system("timeout 1 > NULL"); // 1�� ���߱�
        system("cls"); // ȭ�� �����
        printf("%d�� : %d��\n", min, sec--); // 1�� ���� �� ���
        if (sec < 0) {
            min--;
            sec = 59;
        } // End of if
    } // End of for
    printf("�׸� Ƣ��!");
}

int main() {
    /**
    for (int i = 2; i < 10; i++) {
        printf("%d dan: ", i);
        for (int j = 1; j < 10; j++) {
            printf("%dx%d=%d ", i, j, i*j);
        }
        printf("\n");
    }*/
    p1();
    p2();
    p3();
    p4();
    p5();
    p6(); 
    p7();
    p8();
    p9();
    return 0;
}