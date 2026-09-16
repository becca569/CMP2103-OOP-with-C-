#include <iostream>
using namespace std; //tells the compiler that whenever 'cout', 'cin', or 'endl' is used, 
//it should look in the standard namespace for them

//Function prototypes (forward declarations)

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    cout << "Enter a credit card number as an integer: ";
    cin >> cardNumber;

    if (isValid(cardNumber))
        cout << cardNumber << " is valid." << endl;
    else
        cout << cardNumber << " is invalid." << endl;

    return 0;
} //Asks the user for a number, stores it, and prints "valid" or "invalid"

bool isValid(long long number) {
    int totalDigits = getSize(number);
    if (totalDigits < 13 || totalDigits > 16) return false;
    if (!prefixMatched(number, 4) && !prefixMatched(number, 5) &&
        !prefixMatched(number, 37) && !prefixMatched(number, 6)) return false;
    return (sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0;
} //Length check: Real card numbers are 13–16 digits long. If not, reject immediately.
//Prefix check: Real issuers have known starting digits:
//4 → Visa
//5 → Mastercard
//37 → American Express
//6 → Discover
//If the number doesn't start with any of these, it's rejected.

int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        number /= 10;                     // drop last digit (skip it)
        int digit = (number % 10) * 2;    // take next digit, double it
        sum += getDigit(digit);           // add digits of that doubled value
        number /= 10;                     // drop that digit too
    }
    return sum;
}

int getDigit(int number) {
    if (number < 10) return number;
    return number / 10 + number % 10;
}

int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;   // add last digit
        number /= 100;        // skip two digits at a time
    }
    return sum;
}

bool prefixMatched(long long number, int d) {
    return getPrefix(number, getSize(static_cast<long long>(d))) == d;
}

int getSize(long long d) {
    int size = 0;
    while (d > 0) {
        d /= 10;
        size++;
    }
    return size;

}
long long getPrefix(long long number, int k) {
    int size = getSize(number);
    for (int i = size - k; i > 0; i--) {
        number /= 10;
    }
    return number;
}
