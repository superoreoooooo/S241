#include <stdio.h>
#include <stdlib.h>
#define CNT 3

int main() {
    int scores[CNT];

    for (int i = 0; i < CNT; i++) {
        scanf("%d", &scores[i]);
    }

    for (int a = 0; a < CNT - 1; a++) {
        for (int b = a + 1; b < CNT; b++) {
            if (scores[b] > scores[a]) {
                int temp = scores[b];
                scores[b] = scores[a];
                scores[a] = temp;
            }
        }
    }

    for (int i = 0; i < CNT; i++) {
        printf("%d : %d ", i + 1, scores[i]);
    }
    return 0;
}