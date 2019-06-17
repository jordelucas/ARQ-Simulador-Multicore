#include <iostream>

int main() {
    int num1 = 10;
    int * pont1 = &num1;
    int num2 = *pont1;
    num1 = 20;
    num2 = *pont1;
    std::cout << num1 << "\n"; 
    std::cout << num2 << "\n"; 
    std::cout << *pont1 << "\n"; 

    return 0;
}