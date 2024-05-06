#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HGT 24
#define WTH 60
#define LEN 40

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
    int k, jul, met, sound[WTH];

	for (k = 0; k < 200; k++) {
		system("cls");
		for (met = 0; met < WTH; met++) sound[met] = rand() % (HGT+1);

		for (jul = 0; jul <= HGT; jul++) {
			for (met = 0; met < WTH; met++) {
				if (sound[met] <= jul) printf("ㅁ");
				else printf("  ");
			}
			printf("\n");
		}
	}
}

void p3() {
    char mt[HGT][WTH];
    for (int k = 0; k < 200; k++) {
		system("cls");
        for (int y = 0; y < HGT; y++) {
            for (int x = 0; x < WTH; x++) {
                mt[y][x] = 'A';
            }
        }

        for (int dx = 0; dx < WTH; dx++) {
            int len = rand() % HGT + 1;
            for (int dy = 0; dy < len; dy++) {
                mt[dy][dx] = 'B';
            }
        }

        for (int y = 0; y < HGT; y++) {
            for (int x = 0; x < WTH; x++) {
                if (mt[y][x] == 'A') {
                    printf("  ");
                } else if (mt[y][x] == 'B') {
                    printf("ㅁ");
                }
                //printf("%c", mt[y][x]);
            }
            printf("\n");
        }
    }
}

void p4() {
    int p[LEN] = { 0 };
	int vic = 0, m, k2, user, pos;

	srand((unsigned)time(NULL));
	for (k2 = 0; k2 < 5; k2++) {
		pos = rand() % LEN;
		p[pos] = 8;
		for (m = 0; m < LEN; m++) printf("%2d ", m);
		printf("\n");
		for (m = 0; m < LEN; m++) printf(" %d ", p[m]);
		system("timeout 2 > NULL");
		system("cls");

		printf("\n\n 8은 몇 번에?");
		scanf("%d", &user);
		if (user == pos) printf("\n 맞췄음! %d번 찾음\n\n", ++vic);
		else {
			printf("\n 틀렸음! %d번 찾음\n\n", vic);
			break;
		}
		p[pos] = 0;
	}
}

void p5() {
    
	int x[26], dx[26];
	char input_string[6];

	printf("\n\n\n문자입력 : ");
	for (int k9 = 0; k9 < 6; k9++) {
		scanf("%c", &input_string[k9]);
	}
	

	for (int dy = 0; dy < 26; dy++) {
		x[dy] = -24;
		dx[dy] = rand() % 10 + 3;
	}
	for (int i = 0; i < 100; i++) {
		system("cls");
		for (int dy = 0; dy < 26; dy++) {
			x[dy] = x[dy] + dx[dy];
			if (x[dy] > 115) {
				x[dy] = -22;
				dx[dy] = rand() % 20 + 3;
			}
			for (int dx = 0; dx < 115; dx++) {
				if (x[dy] == dx) printf("%s", input_string);
				else printf("  ");
			}
			printf("\n");
		}
		system("timeout 1 > NULL");
	}
}

int main()
{
    p1();
    p2();
    p3();
    p4();
    p5();
    return 0;
}