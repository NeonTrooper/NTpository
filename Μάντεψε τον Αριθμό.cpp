#include <iostream>
#include <cstdlib>
#include <ctime>

int main() 
{
	using namespace std;
    srand(time(0)); // Αρχικοποίηση τυχαίου αριθμού
    int number = rand() % 100 + 1; // Τυχαίος αριθμός από 1 έως 100
    int guess;
    
    system("CHCP 1253 > NUL");

   	cout << "Μάντεψε τον αριθμό (1-100): ";
    
    do {
        std::cin >> guess;
        if (guess > number) 
		{
            cout << "Πολύ ψηλά! Δοκίμασε ξανά: ";
        } 
		else if (guess < number)
		 {
            cout << "Πολύ χαμηλά! Δοκίμασε ξανά: ";
        } 
		else 
		{
            cout << "Σωστά! Ο αριθμός ήταν " << number << ".\n";
        }
    } while (guess != number);
    
    system("Pause");

    return 0;
}

