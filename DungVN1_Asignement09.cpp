#include<iostream>
using namespace std;

class CFraction
{
	private:
		int num;
		int den;
	public:
		void importFraction(CFraction &frac);
		void showFrac(CFraction frac );
		friend CFraction operator+ (const CFraction&, const CFraction&);
		friend CFraction operator- (const CFraction&, const CFraction&);
		friend CFraction operator* (const CFraction&, const CFraction&);
		friend CFraction operator/ (const CFraction&, const CFraction&);
};

int main()
{
    int option;
    bool check = true ;
	CFraction firstFrac,secondFrac,addFrac,subFrac,mulFrac,divFrac;
	cout << "Input first fraction:\n";
	firstFrac.importFraction(firstFrac);
	cout << "first fraction: ";
	firstFrac.showFrac(firstFrac);
	cout << "Input second fraction:\n";
	secondFrac.importFraction(secondFrac);
	cout << "second fraction: ";
	secondFrac.showFrac(secondFrac);
	

	cout << " 1. Add two Fractions :\n";
    addFrac = firstFrac + secondFrac;
	cout << "a + b = ";
    addFrac.showFrac(addFrac);
    
    cout << " 2. Sub two Fractions :\n";
    subFrac = firstFrac - secondFrac;
    cout << "a - b = ";
    subFrac.showFrac(subFrac);
    
    cout << " 3. Mul two Fractions :\n";

    mulFrac = firstFrac * secondFrac;
    cout << "a * b = ";
    mulFrac.showFrac(mulFrac);
    
    cout << " 4. Div two Fractions :\n";
    divFrac = firstFrac / secondFrac;
    cout << "a / b = ";
    divFrac.showFrac(divFrac);

}
	
/******************************************************
function:       importFraction
parameter:      fraction
description:    input fraction
*******************************************************/
void CFraction::importFraction(CFraction &frac)
{
    cout << "Enter numerator: ";
    cin >> frac.num;
    do
    {
        cout << "Enter denominator: ";
        cin >> frac.den;
    }while(frac.den == 0);
    
}

/******************************************************
function:       gcd
parameter:      2 positive numbers
return:         greatest common divisor
description:    finding greatest common divisor
*******************************************************/
int gcd(int a, int b)
{
     while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

/******************************************************
function:       showFrac
parameter:      fraction
description:    display fraction on console
*******************************************************/
void CFraction::showFrac(CFraction frac)
{

        cout << frac.num << "/"  << frac.den << endl;

}

/******************************************************
function:       operator+
parameter:      2 fractions
return:         result of the addition
description:    Support adding 2 fractions
*******************************************************/
CFraction operator+ (const CFraction& firstFrac, const CFraction& secondFrac )
{
    CFraction addFrac;
    addFrac.num = firstFrac.num * secondFrac.den + secondFrac.num * firstFrac.den;
    addFrac.den = firstFrac.den * secondFrac.den;
    int addFrac_gcd = gcd(addFrac.num, addFrac.den);
    addFrac.num = addFrac.num/addFrac_gcd;
    addFrac.den = addFrac.den/addFrac_gcd;
    return addFrac;
}

/******************************************************
function:       operator-
parameter:      2 fractions
return:         result of the subtraction
description:    Support subtract 2 fractions
*******************************************************/
CFraction operator- (const CFraction& firstFrac, const CFraction& secondFrac )
{
    CFraction subFrac;
    subFrac.num = firstFrac.num * secondFrac.den - secondFrac.num * firstFrac.den;
    subFrac.den = firstFrac.den * secondFrac.den;
    int subFrac_gcd = gcd(subFrac.num, subFrac.den);
    subFrac.num = subFrac.num/subFrac_gcd;
    subFrac.den = subFrac.den/subFrac_gcd;
    return subFrac;
}

/******************************************************
function:       operator*
parameter:      2 fractions
return:         result of the multiplication
description:    Support multiple 2 fractions
*******************************************************/
CFraction operator* (const CFraction& firstFrac, const CFraction& secondFrac )
{
    CFraction mulFrac;
    mulFrac.num = firstFrac.num * secondFrac.num ;
    mulFrac.den = firstFrac.den * secondFrac.den;
    int mulFrac_gcd = gcd(mulFrac.num, mulFrac.den);
    mulFrac.num = mulFrac.num/mulFrac_gcd;
    mulFrac.den = mulFrac.den/mulFrac_gcd;
    return mulFrac;
}

/******************************************************
function:       operator/
parameter:      2 fractions
return:         result of the division
description:    Support divide 2 fractions
*******************************************************/
CFraction operator/ (const CFraction& firstFrac, const CFraction& secondFrac )
{
    CFraction divFrac;
    divFrac.num = firstFrac.num * secondFrac.den ;
    divFrac.den = firstFrac.den * secondFrac.num;
    int divFrac_gcd = gcd(divFrac.num, divFrac.den);
    divFrac.num = divFrac.num/divFrac_gcd;
    divFrac.den = divFrac.den/divFrac_gcd;
    return divFrac;
}









