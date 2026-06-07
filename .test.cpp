/*
 * DO NOT MODIFY THIS FILE IN ANY WAY. IT IS USED BY `make test` TO
 * TEST YOUR PROGRAM AND APPROXIMATE WHAT YOUR GRADE WILL BE FOR A
 * LARGE CHUNK OF THE RUBRIC.
 */

#include <functional>
#include <iostream>
#include <vector>
#include <optional>
#include <cmath>

#include "calculator.hpp"

struct total_points {
	int earned_points;
	int max_points;
};

struct test_result {
	std::string name;
	std::optional<std::string> message;
	total_points points;
};

test_result test_empty_expression() {
	test_result tr {
		name: "Testing invalidity of empty expression...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (!is_valid_expression("")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"\") should return `false`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"\")");
	}
	return tr;
}

test_result test_space_expression() {
	test_result tr {
		name: "Testing invalidity of space expression...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 3
		}
	};

	try {
		if (!is_valid_expression(" ")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\" \") should return `false`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\" \")");
	}
	return tr;
}

test_result test_starts_with_operator() {
	test_result tr {
		name: "Testing invalidity of expression starting with operator...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (!is_valid_expression("+ 7 - 12")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"+ 7 - 12\") should return `false`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"+ 7 - 12\")");
	}
	return tr;
}

test_result test_ends_with_operator() {
	test_result tr {
		name: "Testing invalidity of expression ending with operator...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 3
		}
	};

	try {
		if (!is_valid_expression("7 - 12 *")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"7 - 12 *\") should return `false`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"7 - 12 *\")");
	}
	return tr;
}

test_result test_missing_space() {
	test_result tr {
		name: "Testing invalidity of expression with missing space...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (!is_valid_expression("7/ 12")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"7/ 12\") should return `false`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"7/ 12\")");
	}
	return tr;
}

test_result test_double_space() {
	test_result tr {
		name: "Testing invalidity of expression with too many spaces...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (!is_valid_expression("7  / 12")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"7  / 12\") should return `false` (since there are two spaces in a row between the '7' and '/'), but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"7  / 12\")");
	}
	return tr;
}

test_result test_valid_plus_operation() {
	test_result tr {
		name: "Testing validity of plus operation...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (is_valid_expression("12 + 92")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"12 + 92\") should return `true`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"12 + 92\")");
	}
	return tr;
}

test_result test_valid_minus_operation() {
	test_result tr {
		name: "Testing validity of subtraction operation...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (is_valid_expression("12 - 92")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"12 - 92\") should return `true`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"12 - 92\")");
	}
	return tr;
}

test_result test_valid_multiply_operation() {
	test_result tr {
		name: "Testing validity of multiplication operation...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (is_valid_expression("12 * 92")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"12 * 92\") should return `true`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"12 * 92\")");
	}
	return tr;
}

test_result test_valid_divide_operation() {
	test_result tr {
		name: "Testing validity of division operation...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (is_valid_expression("12 / 92")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"12 / 92\") should return `true`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"12 / 92\")");
	}
	return tr;
}

test_result test_valid_negative() {
	test_result tr {
		name: "Testing validity of operation with negative values...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (is_valid_expression("-12 + -92")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"-12 + -92\") should return `true`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"-12 + -92\")");
	}
	return tr;
}

test_result test_valid_decimal_point() {
	test_result tr {
		name: "Testing validity of operation with decimal points...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2
		}
	};

	try {
		if (is_valid_expression("12.0 + 92.5")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"12.0 + 92.5\") should return `true`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"12.0 + 92.5\")");
	}
	return tr;
}

test_result test_valid_large_expression() {
	test_result tr {
		name: "Testing validity of larger expression with many operations",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 3
		}
	};

	try {
		if (is_valid_expression("12.0 + 92 / 4 - 12 * -4")) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("is_valid_expression(\"12.0 + 92 / 4 - 12 * -4\") should return `true`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"12.0 + 92 / 4 - 12 * -4\")");
	}
	return tr;
}

bool is_close(double value1, double value2) {
	return fabs(value1 - value2) < 0.001;
}

test_result test_evaluate_single_number() {
	test_result tr {
		name: "Testing evaluation of single number...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 3
		}
	};

	try {
		double value = compute_value("12");
		if (is_close(value, 12)) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("compute_value(\"12\") should return `12`, but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"12\")");
	}
	return tr;
}

test_result test_evaluate_plus_operation() {
	test_result tr {
		name: "Testing evaluation of plus operation...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 5
		}
	};

	try {
		double value = compute_value("12 + 92");
		if (is_close(value, 104)) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("compute_value(\"12 + 92\") should return `104`, but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"12 + 92\")");
	}
	return tr;
}

test_result test_evaluate_minus_operation() {
	test_result tr {
		name: "Testing evaluation of subtraction operation...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 5
		}
	};

	try {
		double value = compute_value("12 - 92");
		if (is_close(value, -80)) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("compute_value(\"12 - 92\") should return `-80`, but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"12 - 92\")");
	}
	return tr;
}

test_result test_evaluate_multiply_operation() {
	test_result tr {
		name: "Testing evaluation of multiplication operation...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 5
		}
	};

	try {
		double value = compute_value("12 * 92");
		if (is_close(value, 1104)) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("compute_value(\"12 * 92\") should return `1104`, but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"12 * 92\")");
	}
	return tr;
}

test_result test_evaluate_divide_operation() {
	test_result tr {
		name: "Testing evaluation of division operation...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 5
		}
	};

	try {
		double value = compute_value("1 / 5");
		if (is_close(value, 0.2)) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("compute_value(\"1 / 5\") should return `0.2`, but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"1 / 5\")");
	}
	return tr;
}

test_result test_evaluate_negative() {
	test_result tr {
		name: "Testing evaluation of operation with negative values...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 5
		}
	};

	try {
		double value = compute_value("-12 + -92");
		if (is_close(value, -104)) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("compute_value(\"-12 + -92\") should return `-104`, but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"-12 + -92\")");
	}
	return tr;
}

test_result test_evaluate_decimal_point() {
	test_result tr {
		name: "Testing evaluation of operation with decimal points...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 5
		}
	};

	try {
		double value = compute_value("12.0 + 92.5");
		if (is_close(value, 104.5)) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("compute_value(\"12.0 + 92.5\") should return `104.5`, but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"12.0 + 92.5\")");
	}
	return tr;
}

test_result test_evaluate_large_expression() {
	test_result tr {
		name: "Testing evaluation of larger expression with many operations...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 8
		}
	};

	try {
		double value = compute_value("12.0 + 92 / 4 - 12 * -4");
		if (is_close(value, -56) || is_close(value, 83)) {
			tr.points.earned_points = tr.points.max_points;
		} else {
			tr.message = std::make_optional<std::string>("compute_value(\"12.0 + 92 / 4 - 12 * -4\") should return either `-56` or '83' (depending on whether you did order-of-operations extra credit), but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"12.0 + 92 / 4 - 12 * -4\")");
	}
	return tr;
}

test_result test_valid_exponential_operation() {
	constexpr int extra_credit_points = 2;
	test_result tr {
		name: "Testing validity of exponential operation for extra credit...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 2 // Extra credit
		}
	};

	try {
		double value = compute_value("7 ^ 5");
		if (is_valid_expression("7 ^ 5")) {
			tr.points.earned_points = extra_credit_points;
		} else {
			tr.message = std::make_optional<std::string>("In order to earn the exponential operation extra credit points, is_valid_expression(\"7 ^ 5\") should return 'true', but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"7 ^ 5\")");
	}
	return tr;
}

test_result test_evaluate_exponential_operation() {
	constexpr int extra_credit_points = 3;
	test_result tr {
		name: "Testing evaluation of exponential operation for extra credit...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 3 // Extra credit
		}
	};

	try {
		double value = compute_value("7 ^ 5");
		if (is_close(value, 16807)) {
			tr.points.earned_points = extra_credit_points;
		} else {
			tr.message = std::make_optional<std::string>("In order to earn the exponential operation extra credit points, compute_value(\"7 ^ 5\") should return '16807', but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"7 ^ 5\")");
	}
	return tr;
}

test_result test_evaluate_order_of_operations() {
	constexpr int extra_credit_points = 10;
	test_result tr {
		name: "Testing evaluation of order-of-operations extra credit...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 10 // Extra credit
		}
	};

	try {
		double value = compute_value("12.0 + 92 / 4 - 12 * -4");
		if (is_close(value, 83)) {
			tr.points.earned_points = extra_credit_points;
		} else {
			tr.message = std::make_optional<std::string>("In order to earn the order-of-operations extra credit points, compute_value(\"12.0 + 92 / 4 - 12 * -4\") should return '83', but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"12.0 + 92 / 4 - 12 * -4\")");
	}
	return tr;
}

test_result test_valid_parentheses() {
	constexpr int extra_credit_points = 5;
	test_result tr {
		name: "Testing validity of operation with parentheses for extra credit...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 5 // Extra credit
		}
	};

	try {
		if (is_valid_expression("5 - ( ( 2 / 4 ) - 2 )")) {
			tr.points.earned_points = extra_credit_points;
		} else {
			tr.message = std::make_optional<std::string>("In order to earn the parentheses extra credit points, is_valid_expression(\"5 - ( ( 2 / 4 ) - 2 )\") should return `true`, but it doesn't");
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating is_valid_expression(\"5 - ( ( 2 / 4 ) - 2 )\")");
	}
	return tr;
}

test_result test_evaluate_parentheses() {
	constexpr int extra_credit_points = 10;
	test_result tr {
		name: "Testing evaluation of parentheses expression for extra credit...",
		message: std::nullopt,
		points: {
			earned_points: 0,
			max_points: 10 // Extra credit
		}
	};

	try {
		double value = compute_value("5 - ( ( 2 / 4 ) - 2 )");
		if (is_close(value, 6.5)) {
			tr.points.earned_points = extra_credit_points;
		} else {
			tr.message = std::make_optional<std::string>("In order to earn the parentheses extra credit points, compute_value(\"5 - ( ( 2 / 4 ) - 2 )\") should return '6.5', but it instead returns " + std::to_string(value));
		}
	} catch(...) {
		tr.message = std::make_optional<std::string>("An error occurred when evaluating compute_value(\"5 - ( ( 2 / 4 ) - 2 )\")");
	}
	return tr;
}

void print_points(const total_points& points) {
	std::cout << points.earned_points << " / " << points.max_points << " points earned";
}

total_points compute_total_points(const std::vector<test_result>& test_results) {
	total_points points {
		earned_points: 0,
		max_points: 0
	};
	for (const test_result& tr : test_results) {
		points.earned_points += tr.points.earned_points;
		points.max_points += tr.points.max_points;
	}
	return points;
}

void print_results(const std::vector<test_result>& test_results) {
	for (const test_result& tr : test_results) {
		std::cout << tr.name << ": ";
		print_points(tr.points);
		std::cout << std::endl;
		if (tr.message.has_value()) {
			std::cout << "Reason for losing above points: " << tr.message.value() << std::endl;
		}
		std::cout << std::endl;
	}
}

int main() {
	std::vector<std::function<test_result()>> tests {
		test_empty_expression,
		test_space_expression,
		test_starts_with_operator,
		test_ends_with_operator,
		test_missing_space,
		test_double_space,
		test_valid_plus_operation,
		test_valid_minus_operation,
		test_valid_multiply_operation,
		test_valid_divide_operation,
		test_valid_negative,
		test_valid_decimal_point,
		test_valid_large_expression,
		test_evaluate_single_number,
		test_evaluate_plus_operation,
		test_evaluate_minus_operation,
		test_evaluate_multiply_operation,
		test_evaluate_divide_operation,
		test_evaluate_negative,
		test_evaluate_decimal_point,
		test_evaluate_large_expression,
		test_valid_exponential_operation,
		test_evaluate_exponential_operation,
		test_evaluate_order_of_operations,
		test_valid_parentheses,
		test_evaluate_parentheses
	};
	std::vector<test_result> test_results;
	
	for (const auto& test : tests) {
		test_results.push_back(test());
	}

	std::cout << std::endl;
	print_results(test_results);

	total_points points = compute_total_points(test_results);
	std::cout << "------------------------" << std::endl <<
		"Total points: ";
	print_points(points);
	std::cout << std::endl << "------------------------" << std::endl <<
		std::endl;
	std::cout << "Remember: 30 of these 100 points are extra credit. If you earn a 70/100 above, then that's REALLY a 70/70. Of course, there are still points for your main() function and following the course style guidelines" << std::endl;
}
