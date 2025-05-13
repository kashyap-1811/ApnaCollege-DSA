#include <iostream>
#include <cmath>
using namespace std;

int binary_to_decimal(int binary)
{
    int number = 0;
    int pow = 1;
    while (binary > 0)
    {
        int remainder = binary % 10;
        number += remainder * pow;
        pow *= 2;
        binary /= 10;
    }
    return number;
}

int main()
{
    int num1, num2;
    cout << "Provide number1: ";
    cin >> num1;
    cout << "Provide number2: ";
    cin >> num2;

    int carry = 0;
    int binary = 0, pow = 1;
    int add = 0;

    cout << "remainder1\tremainder2" << endl;
    while (num1 > 0 || num2 > 0)
    {
        int remainder1 = num1 % 2;
        int remainder2 = num2 % 2;

        cout << remainder1 << "\t\t\t\t" << remainder2 << "\t\t\t\t";

        if (remainder1 == 1 && remainder2 == 1)
        {
            if (carry == 1)
            {
                add = 1;
                binary += add * pow;
                carry = 1;
            }
            else
            {
                add = 0;
                carry = 1;
                binary += add * pow;
            }
        }
        else if ((remainder1 == 1 && remainder2 == 0) || (remainder1 == 0 && remainder2 == 1))
        {
            if (carry == 1)
            {
                carry = 1;
                add = 0;
                binary += add * pow;
            }
            else
            {
                carry = 0;
                add = 1;
                binary += add * pow;
            }
        }
        else if (remainder1 == 0 && remainder2 == 0)
        {
            if (carry == 1)
            {
                carry = 0;
                add = 1;
                binary += add * pow;
            }
            else
            {
                carry = 0;
                add = 0;
                binary += add * pow;
            }
        }
        cout << binary << endl;
        pow *= 10;
        num1 /= 2;
        num2 /= 2;
    }
    if (carry == 1)
    {
        add = 1;
        binary += add * pow;
        cout << "0\t\t\t\t0\t\t\t\t" << binary;
    }
    cout << endl;
    int sum = binary_to_decimal(binary);
    cout << endl << "Sum is: " << sum << endl;
    return 0;
}
