#include <stdio.h>

int main()
{
    int num1;

    printf("숫자를 입력: ");
    scanf("%d", &num1);
    printf("짝수E 홀수O: %c\n", 69 + (num1 % 2) * 10);
    return 0;
}
