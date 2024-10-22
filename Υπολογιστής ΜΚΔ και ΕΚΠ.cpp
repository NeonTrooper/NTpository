#include <stdio.h>
# include <stdlib.h>

// Συνάρτηση για εύρεση ΜΚΔ
int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Συνάρτηση για εύρεση ΕΚΠ
int lcm (int a, int b) 
{
    return (a * b) / gcd(a, b);
}

int main() 
{
	system ("CHCP 1253 > NUL");
    int num1, num2;
    printf("Δώσε τον πρώτο αριθμό: ");
    scanf("%d", &num1);
    printf("Δώσε τον δεύτερο αριθμό: ");
    scanf("%d", &num2);

    printf("ΜΚΔ: %d\n", gcd(num1, num2));
    printf("ΕΚΠ: %d\n", lcm(num1, num2));
    
    system("Pause");

    return 0;
}

