#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#

int p1();
int p2();
int p3();
int p4();

int main()
{
    p1();
    p2();
    p3();
    p4();
    return 0;
}

int p1()
{
    printf("=======1=======\n");
    int ticket;

    scanf("%d", &ticket);

    switch (ticket)
    {
    case 1: // 오류 1
        printf("돌고래 \n");
        //break; ??
    case 2: // 오류 2
        printf("10종  \n");
        break;
    default:
        printf("입장권  \n");
    }       //오류 3 ?
    return 0;
}

int p2()
{
    printf("=======2=======\n");
    int birth, age;

    printf("이번 달에 생일입니까? Yes=1, No=0: ");
    scanf("%d", &birth);
    printf("나이를 입력하세요: ");
    scanf("%d", &age);

    if (!(birth == 1 && age >= 19))
        printf("탄산음료 한 잔 당첨! \n");
    else
        printf("축하합니다! 모히또 한 잔 당첨! \n");
    return 0;
}

int p3() {
    printf("=======3=======\n");
    int coupon, con;

    printf("쿠폰 개수 입력: ");
    scanf("%d", &coupon);
    con = coupon / 10;
    if (con == 1)
    {
        printf("다이어리\n");
    }
    else if (con == 2)
    {
        printf("여행 가방\n");
    }
    else
    {
        printf("커피 한 잔\n");
    }
    /**
    switch (con) {
    case 2:
        printf("여행 가방\n");
        break;
    case 1:
        printf("다이어리\n");
        break;
    default :
        printf("커피 한 잔\n");
    }*/
    return 0;
}

int p4() {
    printf("=======4=======\n");
    int com, user;

    srand((unsigned)time(NULL)); // 실행할 때마다 rand() 패턴 변경
    com = rand() % 3;            // rand() 0, 1, 2 중 무작위 수 생성
    printf("가위(0), 바위(1) 보(2) 선택: ");
    scanf("%d", &user);
    printf("com = %d, user = %d\n", com, user);

    if (com == user)
        printf("비겼습니다!\n"); // 비긴 경우
    else if (com - user == 2 || user - com == 1)           // 괄호 안을 채우시오
        printf("사용자 승!\n");  // 사용자가 이긴 경우
    else
        printf("컴퓨터 승!\n"); // 컴퓨터가 이긴 경우
    return 0;
}