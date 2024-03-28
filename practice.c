#include <stdio.h>

#define TRATE 0.045

void getTotal(double *total, double hour, int pay) {
    *total = (hour * pay);
}

int main() {
    int pay = 0;
    double hour = 0;
    double total = 0;

    scanf("%d %lf", &pay, &hour);

    getTotal(&total, hour, pay);

    printf("total without tax : %1f", total * (1 - TRATE));
    return 0;
}