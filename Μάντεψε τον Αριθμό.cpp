#include <iostream>
#include <cstdlib>
#include <ctime>

int main() 
{
	using namespace std;
    srand(time(0)); // ������������ ������� �������
    int number = rand() % 100 + 1; // ������� ������� ��� 1 ��� 100
    int guess;
    
    system("CHCP 1253 > NUL");

   	cout << "������� ��� ������ (1-100): ";
    
    do {
        std::cin >> guess;
        if (guess > number) 
		{
            cout << "���� ����! �������� ����: ";
        } 
		else if (guess < number)
		 {
            cout << "���� ������! �������� ����: ";
        } 
		else 
		{
            cout << "�����! � ������� ���� " << number << ".\n";
        }
    } while (guess != number);
    
    system("Pause");

    return 0;
}

