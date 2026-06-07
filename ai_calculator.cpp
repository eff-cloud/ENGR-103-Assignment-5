/*
 * Author: ChatGPT
 * Description: Validates and evaluates arithmetic expressions,
 * stores computed results, and prints a history of results.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

/*
 * Returns true if the given string is a valid number.
 */
bool is_number(string s) {
    if (s.length() == 0) {
        return false;
    }

    bool decimal_found = false;
    int start = 0;

    // Skip a leading negative sign
    if (s[0] == '-') {
        if (s.length() == 1) {
            return false;
        }
        start = 1;
    }

    for (int i = start; i < s.length(); i++) {

        // Allow only one decimal point
        if (s[i] == '.') {
            if (decimal_found) {
                return false;
            }
            decimal_found = true;
        }

        // All other characters must be digits
        else if (!isdigit(s[i])) {
            return false;
        }
    }

    return true;
}

/*
 * Returns true if the expression follows the required format.
 */
bool is_valid_expression(string expression) {
    stringstream ss(expression);
    string token;

    bool expect_number = true;
    bool found_number = false;

    while (ss >> token) {

        // Check for a valid number
        if (expect_number) {

            if (!is_number(token)) {
                return false;
            }

            found_number = true;
            expect_number = false;
        }

        // Check for a valid operator
        else {

            if (token != "+" &&
                token != "-" &&
                token != "*" &&
                token != "/") {
                return false;
            }

            expect_number = true;
        }
    }

    return found_number && !expect_number;
}

/*
 * Evaluates a valid arithmetic expression from left to right.
 */
double compute_value(string expression) {

    stringstream ss(expression);
    string token;

    // Read the first number
    ss >> token;
    double result = stod(token);

    while (ss >> token) {

        string op = token;

        // Read the next value
        ss >> token;
        double value = stod(token);

        // Perform the requested operation
        if (op == "+") {
            result += value;
        }
        else if (op == "-") {
            result -= value;
        }
        else if (op == "*") {
            result *= value;
        }
        else if (op == "/") {
            result /= value;
        }
    }

    return result;
}

/*
 * Runs the calculator and prints the history of results.
 */
int main() {

    // Stores up to 100 computed values
    double history[100];
    int history_count = 0;

    string expression;
    string answer;

    bool keep_going = true;

    while (keep_going) {

        cout << "Enter a valid arithmetic expression: ";
        getline(cin, expression);

        // Keep asking until a valid expression is entered
        while (!is_valid_expression(expression)) {

            cout << "That isn't a valid arithmetic expression."
                 << endl;

            cout << "Enter a valid arithmetic expression: ";
            getline(cin, expression);
        }

        // Compute and display the result
        double result = compute_value(expression);

        cout << result << endl;

        // Save result in history
        history[history_count] = result;
        history_count++;

        cout << "Would you like to enter another expression? "
             << "Enter Y for yes: ";
        getline(cin, answer);

        if (answer != "Y") {
            keep_going = false;
        }
    }

    cout << endl;
    cout << "History of computed values:" << endl;

    // Print all stored results
    for (int i = 0; i < history_count; i++) {
        cout << history[i] << endl;
    }

    return 0;
}