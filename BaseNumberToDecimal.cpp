// Converts any number base 2-16 to a decimal number

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    string inputNumber;
    int base = 0;

    // Get input from user
    cout << "Enter a number: ";
    cin >> inputNumber;
    cout << "Base: ";
    cin >> base;
    
    int inputStringLength = inputNumber.length();
    int wholeNumber[inputStringLength];
    int wholeNumberLength = 0;
    int fractionalNumber[inputStringLength];
    int fractionalNumberLength = 0;
    int outputInt = 0;
    float sum = 0;
    int position = 0;

    // Iterate over every digit in the string and convert from char to int
    for (int position = 0; position < inputStringLength; position++) {
        // Loop will run until a '.' is found in which case the program moves on to the fractional part of the number
        if (inputNumber[position] != '.') {
            wholeNumberLength++;
            // Converts hexadecimal letters to the decimal equivalent
            if (inputNumber[position] <= 'F' && inputNumber[position] >= 'A') {
                switch(inputNumber[position]) {
                    case 'A': outputInt = 10; break;
                    case 'B': outputInt = 11; break;
                    case 'C': outputInt = 12; break;
                    case 'D': outputInt = 13; break;
                    case 'E': outputInt = 14; break;
                    case 'F': outputInt = 15; break;
                }
                wholeNumber[position] = outputInt;
            }
            else if (inputNumber[position] <= 'f' && inputNumber[position] >= 'a') {
                switch(inputNumber[position]) {
                    case 'a': outputInt = 10; break;
                    case 'b': outputInt = 11; break;
                    case 'c': outputInt = 12; break;
                    case 'd': outputInt = 13; break;
                    case 'e': outputInt = 14; break;
                    case 'f': outputInt = 15; break;
                }
                wholeNumber[position] = outputInt;
            }
            // If digit is numerical then do nothing other than convert from char to int
            else {
                wholeNumber[position] = inputNumber[position] - '0';
            }
        }
        // Converts the fractional part of the number from char to int and store in a seperate variable
        else {
            position++;
            for (int i = 0; position < inputStringLength; i++, position++, fractionalNumberLength++) {
            if (inputNumber[position] <= 'F' && inputNumber[position] >= 'A') {
                switch(inputNumber[position]) {
                    case 'A': outputInt = 10; break;
                    case 'B': outputInt = 11; break;
                    case 'C': outputInt = 12; break;
                    case 'D': outputInt = 13; break;
                    case 'E': outputInt = 14; break;
                    case 'F': outputInt = 15; break;
                    }
                fractionalNumber[i] = outputInt;
            }
            else if (inputNumber[position] <= 'f' && inputNumber[position] >= 'a') {
                switch(inputNumber[position]) {
                    case 'a': outputInt = 10; break;
                    case 'b': outputInt = 11; break;
                    case 'c': outputInt = 12; break;
                    case 'd': outputInt = 13; break;
                    case 'e': outputInt = 14; break;
                    case 'f': outputInt = 15; break;
                    }
                fractionalNumber[i] = outputInt;
            }
                else {
                    fractionalNumber[i] = inputNumber[position] - '0';
                }
            }
        }
    }

    // Max power for decimal number whole part
    float power = 1;
    for (int i = 0; i < wholeNumberLength - 1; i++) {
        power *= base;
    }

    // Multiply the whole part of the decimal number by the power
    for (int i = 0; i < wholeNumberLength; i++) {
        sum += wholeNumber[i] * power;
        // Reduce power by 1
        power /= base;
    }

    // Multiply the fractional part of the decimal number by the power
    for (int i = 0; i < fractionalNumberLength; i++) {
        sum += fractionalNumber[i] * power;
        // Reduce power by 1
        power /= base;
    }

    // Print decimal number to the terminal
    cout << fixed << "Decimal number is: " << setprecision(3) << sum << endl;
}