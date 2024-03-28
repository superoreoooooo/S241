#include <stdio.h>

void p1() {
    printf("=======1=======\n");
    double money = 30000000000;
    printf("chunsur = %.0f\n", money);
}

void p2() {
    printf("=======2=======\n");
    double fnum = 0.123456789;
    printf("double = %.9f\n", fnum);
}

void p3() {
    printf("=======3=======\n");
    char Alp = 'A';
    printf("char = %c\n", Alp);
}

void p4() {
    printf("=======4=======\n");
    short pay1 = 15000;
    long pay2 = pay1 * 10;
    printf("pay1 = %hd\n", pay1);
    printf("pay2 = %ld\n", pay2);
}

void p5() {
    printf("=======5=======\n");
    double money = 30000000000;
    printf("double = %.3f\n", money);
    printf("지수형 = %.1e\n", money);
}

int main() {
    p1();
    p2();
    p3();
    p4();
    p5();

    return 0;
}