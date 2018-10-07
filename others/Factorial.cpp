#include<iostream>

using namespace std;

int factorial(int x)
{
    if(x ==0)
        return 1;
    return x * factorial(x - 1);
}

int main()
{
    int fac;
    cout << "Enter a num: ";
    cin >> fac;

    cout << "Factorial = " << factorial(fac) << endl;

    return 0;
}
