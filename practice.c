#include <stdio.h>

void getTotal(double *total, double hour, int pay) {
    *total = (hour * pay);
}

int main() {
    int pay = 10000;
    double hour = 42.5;
    double total = 0;
    getTotal(&total, hour, pay);
    
    printf("�ñ� %d, %.1f�ð� ����\n���� = %.0f", pay, hour, total);
    return 0;
}