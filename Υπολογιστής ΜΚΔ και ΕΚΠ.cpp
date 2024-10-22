#include <stdio.h>
# include <stdlib.h>

// ��������� ��� ������ ���
int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// ��������� ��� ������ ���
int lcm (int a, int b) 
{
    return (a * b) / gcd(a, b);
}

int main() 
{
	system ("CHCP 1253 > NUL");
    int num1, num2;
    printf("���� ��� ����� ������: ");
    scanf("%d", &num1);
    printf("���� ��� ������� ������: ");
    scanf("%d", &num2);

    printf("���: %d\n", gcd(num1, num2));
    printf("���: %d\n", lcm(num1, num2));
    
    system("Pause");

    return 0;
}

