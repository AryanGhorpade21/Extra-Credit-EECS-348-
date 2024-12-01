#include <iostream>

#include <iomanip>

#include <string>

using namespace std;



// Function to check if a string is a valid double-precision number

double extractNumeric(const string& str) {

    // Handle empty strings

    if (str.empty()) {

        return -999999.99;

    }



    bool hasDecimal = false;

    bool hasSign = false;



    for (size_t i = 0; i < str.size(); ++i) {

        char ch = str[i];



        // Check for valid characters: digits, '.', '+', '-'

        if (isdigit(ch)) {

            continue;

        } else if (ch == '.' && !hasDecimal) {

            hasDecimal = true;

        } else if ((ch == '+' || ch == '-') && i == 0 && !hasSign) {

            hasSign = true;

        } else {

            return -999999.99; // Invalid character

        }

    }



    // Check for cases like "." or "+" or "-"

    if (str == "." || str == "+" || str == "-") {

        return -999999.99;

    }



    // Convert the validated string to a double manually

    double result = 0.0;

    double fraction = 0.1;

    bool isNegative = (str[0] == '-');

    bool isFraction = false;



    for (size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0; i < str.size(); ++i) {

        char ch = str[i];

        if (ch == '.') {

            isFraction = true;

            continue;

        }

        if (isFraction) {

            result += (ch - '0') * fraction;

            fraction /= 10.0;

        } else {

            result = result * 10 + (ch - '0');

        }

    }



    return isNegative ? -result : result;

}



int main() {

    string input;

    cout << "Welcome to Extracting Numbers from Strings!" << endl;



    while (true) {

        cout << "Enter a string (or 'END' to quit): ";

        cin >> input;



        if (input == "END") {

            break;

        }



        double number = extractNumeric(input);



        if (number != -999999.99) {

            cout << "The input is: " << fixed << setprecision(4) << number << endl;

        } else {

            cout << "The input is invalid." << endl;

        }

    }

    cout << "=====Thank you====="<< endl;



    return 0;

}

