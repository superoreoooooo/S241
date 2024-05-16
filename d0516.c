#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    /*
    int bubb[30], k, jul, met, s;

    for (met = 0; met < 30; met++) {
        bubb[met] = rand() % 26 + 26;
    }

    for (k = 0; k < 300; k++) {
        system("cls");
        for (met = 0; met < 30; met++) {
            if (bubb[met] > 0) {
                bubb[met]--;
            } else {
                bubb[met] = 26;
            }
        }
        for (jul = 0; jul < 26; jul++) {
            for (s = 0; s < sin(jul) * 3 + 3; s++) {
                printf(" ");
            }
            for (met = 0; met < 30; met++) {
                if (bubb[met] == jul) {
                    printf("  O");
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }
    }*/

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
            }
            else {
                printf("%3d ", mine[m]);
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

    return 0;
}