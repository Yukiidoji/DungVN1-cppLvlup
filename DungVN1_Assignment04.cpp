#include<iostream>
using namespace std;

int* get_even_num(int* arr, int* even_sz)
{
    *even_sz = arr[0];
    int sz = *even_sz;
    int* ptr = new int[*even_sz];
    int count = 0;

    for (int i = 1; i <=sz; i++)
    {
        if (arr[i] % 2 == 0)
        {
            ptr[count] = arr[i];
            count++;
        }
        else {
            (*even_sz)--;
        }
    }
    return ptr;
}


int main() {
    int A[] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int even_sz;
    int* even_A = get_even_num(A, &even_sz);
    cout << "mang cac phan tu chan cua A la: ";
    for (int i = 0; i < even_sz; i++)
    {
        cout << even_A[i] << " ";
    }
    cout << endl << "so phan tu chan cua mang la: " << even_sz;
    free(even_A);
    return 0;
}

