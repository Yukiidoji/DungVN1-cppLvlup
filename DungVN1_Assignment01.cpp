#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int num, r, reverse_num = 0, temp;

    cout << "Enter a number: ";
    cin >> num;

    // Dao nguoc so
    for (temp = num; num != 0; num = num / 10) {
        r = num % 10;
        reverse_num = reverse_num * 10 + r;
    }

    // Kiem tra so doi xung
    if (temp == reverse_num)
        cout << temp << " is a palindrome";
    else
        cout << temp << " is not a palindrome";

    return 0;
}