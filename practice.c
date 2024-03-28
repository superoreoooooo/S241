#include <stdio.h>

void getTotal(double *total, double hour, int pay) {
    *total = (hour * pay);
}

int main() {
    int pay = 0;
    double hour = 0;
    double total = 0;

    scanf("%d %lf", &pay, &hour);

    getTotal(&total, hour, pay);

    printf("tax : %f", total * 0.045);
    return 0;
}