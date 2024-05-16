#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void p1();
void p2();

int main() {
    //p1();
    p2();
    return 0;
}

void p1() {
    char str[255], *p;

    p = str;

    printf("소문자 입력 : ");
    scanf("%s", str);

    while (*p != '\0') {
        if (*p >= 97 && *p <= 122) {
            printf("%c", *p - 32);
        } else {
            printf("%c", *p);
        }
        p++;
    }
}

void p2() {
    int mine[30], chip = 0, m, k, bet;

    srand((unsigned)time(NULL));

    for (m = 0; m < 30; m++) {
        mine[m] = (rand() % 30) - 30;
    }

    for (k = 5; k > 0; k--) {
        system("cls");
        for (m = 0; m < 30; m++) {
            printf("%3d", m);
        }
        printf("\n\n");

        for (m = 0; m < 30; m++) {
            if (mine[m] < 0) {
                printf(" -- ");
                //printf("%3d", mine[m]);
            }
            else {
                if (m < 29) {
                    printf("%3d %3d", mine[m], mine[m + 1]);
                } else {
                    printf("%3d ", mine[m]);
                }
            }
        }

        printf("\n\ncnt : %d, chip : %d, pick : ", k, chip);
        scanf("%d", &bet);

        if (bet < 0 || bet > 29 || mine[bet] > 0) {
            continue;
        }
        if (mine[bet] >= -22) {
            mine[bet] = mine[bet] + 30;
            chip += mine[bet];
        }
        else {
            printf("\nBOOM");
            break;
        }
    }
}