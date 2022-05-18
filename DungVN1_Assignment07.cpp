#include<iostream>
#include<cstdlib>
using namespace std;

float add(float a, float b) {
	cout << "Addition:\n";
	cout << a << " + " << b << " = " << a + b << "\n\n";
	return a + b;
}
float sub(float a, float b) {
	cout << "Subtraction:\n";
	cout << a << " - " << b << " = " << a - b << "\n\n";
	return a - b;
}
float mul(float a, float b) {
	cout << "Multiplication:\n";
	cout << a << " * " << b << " = " << a * b << "\n\n";
	return a * b;
}
float div(float a, float b) {
	cout << "Division:\n";
	if (b == 0) {
		cout << "Error: Divide by 0\n";
		return 0;
	}
	cout << a << " / " << b << " = " << a / b << "\n\n";
	return a / b;
}
void operation(float a, float b, float (*p2Func)(float, float))  
{
	p2Func(a, b);

}

int main() 
{

	int opt;
	float a, b;
	cout << "Input float number a: "; cin >> a;
	cout << "Input float number b: "; cin >> b;


	while (1)
	{
		cout << "Select option: \n";
		cout << "1. Addition\n";
		cout << "2. Subtraction\n";
		cout << "3. Multiplication\n";
		cout << "4. Division\n";
		cout << "5. Exit\n";
		cin >> opt;

		switch (opt) {

		case 1:
			operation(a, b, add);
			break;
		case 2:
			operation(a, b, sub);
			break;
		case 3:
			operation(a, b, mul);
			break;
		case 4:
			operation(a, b, div);
			break;
		case 5:
			exit(1);
		default:
			cout << "Wrong option\n\n" ;
			break;
		}

	}
}
