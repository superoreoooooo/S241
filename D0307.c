#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0;
    scanf("%d", &a);

    switch(a) {
        case 1 :
            printf("111");
            break;
        case 2 :
            printf("222");
            break;
        default :
            printf("000");
            break;
    }
    return 0;
}