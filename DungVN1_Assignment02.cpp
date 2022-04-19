#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
    int n, i, j;

    n = 5;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++)
            cout << " ";

        for (j = 1; j <= 2 * i -1; j++)
            cout << "*";

        cout << "\n";
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i -1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return true;
}