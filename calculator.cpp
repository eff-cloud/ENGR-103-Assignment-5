#include <iostream>
#include <string>
#include <cmath>

/*
 * THIS IS A HELPER FUNCTION. YOU AREN'T REQUIRED TO USE IT, AND YOU CAN
 * MODIFY IT IF YOU WANT, BUT I STRONGLY RECOMMEND THAT YOU USE IT AS-IS.
 * YOU MAY FIND IT VERY HELPFUL.
 * Function: is_number
 * Description: Computes and returns the value of the given arithmetic
 *      expression. Expressions are evaluated from left to right and
 *      support +, -, *, /, and ^ operators.
 */
bool is_number(std::string str) {
    // A valid number must contain at least one digit and at most one
    // decimal point
    int num_digits = 0;
    int num_points = 0;
    for (int i = 0; i < str.length(); i++) {
        bool is_point = str.at(i) == '.';
        // A negative sign is a dash at the beginning of the string
        bool is_negative_sign = str.at(i) == '-' && i == 0;
        bool is_number = str.at(i) >= '0' && str.at(i) <= '9';

        if (is_point) {
            num_points++;
            if (num_points > 1) {
                return false;
            }
        }

        if (is_number) {
            num_digits++;
        }

        if (!is_point && !is_negative_sign && !is_number) {
            return false;
        }
    }

    return num_digits > 0;
}

/*
 * Function: is_operator
 * Description: Returns true if the given string is a valid operator.
 * Supports addition, subtraction, multiplication,
 * division, and exponentiation.
 */
bool is_operator(std::string str) {
    return str == "+" ||
           str == "-" ||
           str == "*" ||
           str == "/" ||
           str == "^";
}


/*
 * THIS IS A REQUIRED FUNCTION. YOU MAY NOT ALTER ITS HEADER (NAME, PARAMETERS,
 * OR RETURN TYPE) IN ANY WAY.
 * Function: is_valid_expression
 * Description: Determines whether a given string holds a valid arithmetic
 *      expression, as defined in the assignment document.
 */
bool is_valid_expression(std::string expression) {
    if (expression.length() == 0) {
        return false;
    }

    if (expression.at(0) == ' ' ||
        expression.at(expression.length() - 1) == ' ') {
        return false;
    }

    // Reject multiple spaces in a row
    for (int i = 0; i < expression.length() - 1; i++) {
        if (expression.at(i) == ' ' &&
            expression.at(i + 1) == ' ') {
            return false;
        }
    }

    bool expect_number = true;
    std::string token = "";

    for (int i = 0; i <= expression.length(); i++) {

        if (i == expression.length() ||
            expression.at(i) == ' ') {

            if (expect_number) {
                if (!is_number(token)) {
                    return false;
                }
            } else {
                if (!is_operator(token)) {
                    return false;
                }
            }

            expect_number = !expect_number;
            token = "";
        } else {
            token += expression.at(i);
        }
    }

    // Expression is valid only if it ended with a number
    return !expect_number;
}


/*
 * THIS IS A REQUIRED FUNCTION. YOU MAY NOT ALTER ITS HEADER (NAME, PARAMETERS,
 * OR RETURN TYPE) IN ANY WAY.
 * Function: compute_value
 * Description: Computes and returns the value of the given arithmetic
 *      expression.
 */
double compute_value(std::string expression) {
    std::string token = "";
    int position = 0;

    while (position < expression.length() &&
           expression.at(position) != ' ') {
        token += expression.at(position);
        position++;
    }

    double result = std::stod(token);

    while (position < expression.length()) {
        position++;

        std::string operation = "";
        operation += expression.at(position);

        position += 2;

        token = "";

        while (position < expression.length() &&
               expression.at(position) != ' ') {
            token += expression.at(position);
            position++;
        }

        double value = std::stod(token);

        if (operation == "+") {
			result += value;
		} else if (operation == "-") {
			result -= value;
		} else if (operation == "*") {
			result *= value;
		} else if (operation == "/") {
			result /= value;
		} else if (operation == "^") {
			result = pow(result, value);
		}
    }

    return result;
}