/*
 * Author: Ella Farrell
 * Description: A calculator that validates arithmetic expressions,
 * evaluates them from left to right, stores computed values, and
 * prints a history of all computed results.
 */

#include <iostream>

#include "calculator.hpp"

/*
 * Function: print_error
 * Description: Prints an error message explaining that the user supplied
 *      an invalid arithmetic expression.
 */
void print_error() {
    std::cout << "That isn't a valid arithmetic expression."
              << std::endl;
}

/*
 * Function: prompt_for_arithmetic_expression
 * Description: Prompts the user for an arithmetic expression and returns
 *      whatever text they supply, whether that text represents a valid
 *      arithmetic expression or not (validity should be checked elsewhere;
 *      checking validity is not this particular function's responsibility).
 * Returns: An entire line of text supplied by the user via the terminal when
 *      prompted for an arithmetic expression
 */
std::string prompt_for_arithmetic_expression() {
    std::cout << "Enter a valid arithmetic expression: ";

    std::string user_input;
    std::getline(std::cin, user_input);

    return user_input;
}

/*
 * Function: prompt_for_retry
 * Description: Asks the user whether they'd like to enter another arithmetic
 *      expression and returns their entire line-of-text response
 * Returns: An entire line of text supplied by the user via the terminal when
 *      asked if they'd like to enter another arithmetic expression. If this
 *      function returns the string "Y", then that means the user would like
 *      to enter another arithmetic expression.
 */
std::string prompt_for_retry() {
    std::cout << "Would you like to enter another expression? Enter Y for "
                 "yes: ";

    std::string user_input;
    std::getline(std::cin, user_input);

    return user_input;
}

/*
 * Function: print_history_header
 * Description: Prints the header that precedes the history of values to be
 *      printed at the end of the program.
 */
void print_history_header() {
    std::cout << "History of computed values:" << std::endl;
}

/*
 * Function: print_history
 * Description: Prints all previously computed values.
 * Parameters:
 *      history: Array containing computed values.
 *      historyCount: Number of stored values.
 */
void print_history(double history[], int historyCount) {
    for (int i = 0; i < historyCount; i++) {
        std::cout << history[i] << std::endl;
    }
}

int main() {
    const int MAX_HISTORY = 100;

    double history[MAX_HISTORY];
    int historyCount = 0;

    std::string go_again;

    do {
        std::string expression =
            prompt_for_arithmetic_expression();

        // Check if expression is valid by using the
        // is_valid_expression function, to be defined in calculator.cpp
        if (is_valid_expression(expression)) {
            // Expression is valid. Compute its value by using the
            // compute_value function, to be defined in calculator.cpp.
            double value = compute_value(expression);

            // Print value
            std::cout << value << std::endl;

            // Store value in history array
            history[historyCount] = value;
            historyCount++;

            go_again = prompt_for_retry();
        } else {
            print_error();
            go_again = "Y";
        }
    } while (go_again == "Y");

    // Print history header
    std::cout << std::endl;
    print_history_header();

    // Print history of computed values
    print_history(history, historyCount);

    return 0;
}