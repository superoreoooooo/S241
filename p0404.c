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
    case 1: // ���� 1
        printf("���� \n");
        //break; ??
    case 2: // ���� 2
        printf("10��  \n");
        break;
    default:
        printf("�����  \n");
    }       //���� 3 ?
    return 0;
}

int p2()
{
    printf("=======2=======\n");
    int birth, age;

    printf("�̹� �޿� �����Դϱ�? Yes=1, No=0: ");
    scanf("%d", &birth);
    printf("���̸� �Է��ϼ���: ");
    scanf("%d", &age);

    if (!(birth == 1 && age >= 19))
        printf("ź������ �� �� ��÷! \n");
    else
        printf("�����մϴ�! ������ �� �� ��÷! \n");
    return 0;
}

int p3() {
    printf("=======3=======\n");
    int coupon, con;

    printf("���� ���� �Է�: ");
    scanf("%d", &coupon);
    con = coupon / 10;
    if (con == 1)
    {
        printf("���̾\n");
    }
    else if (con == 2)
    {
        printf("���� ����\n");
    }
    else
    {
        printf("Ŀ�� �� ��\n");
    }
    /**
    switch (con) {
    case 2:
        printf("���� ����\n");
        break;
    case 1:
        printf("���̾\n");
        break;
    default :
        printf("Ŀ�� �� ��\n");
    }*/
    return 0;
}

int p4() {
    printf("=======4=======\n");
    int com, user;

    srand((unsigned)time(NULL)); // ������ ������ rand() ���� ����
    com = rand() % 3;            // rand() 0, 1, 2 �� ������ �� ����
    printf("����(0), ����(1) ��(2) ����: ");
    scanf("%d", &user);
    printf("com = %d, user = %d\n", com, user);

    if (com == user)
        printf("�����ϴ�!\n"); // ��� ���
    else if (com - user == 2 || user - com == 1)           // ��ȣ ���� ä��ÿ�
        printf("����� ��!\n");  // ����ڰ� �̱� ���
    else
        printf("��ǻ�� ��!\n"); // ��ǻ�Ͱ� �̱� ���
    return 0;
}