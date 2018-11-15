//============================================================================
// Name        : Intervals.cpp
// Author      : Edward Li
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

class Intervals {

	double a = 0;
	double b = 0;
	bool no_value = true;
	double stored_a = 0;
	double stored_b = 0;
	bool no_stored_value = true;

public:
	void enter() {
		double tempA;
		double tempB;
		std::cin >> tempA;
		std::cin >> tempB;

		if (tempA > tempB) {
			std::cout << "Error: invalid interval as " << tempA << " > "
					<< tempB << "\n";
		} else {
			this->a = tempA;
			this->b = tempB;
			this->no_value = false;
		}
		this->print_value(false);

	}

	void negate() {
		double temp = this->a;
		this->a = -this->b;
		this->b = -temp;
		print_value(false);
	}

	bool print_value(bool stored) {
		if (stored) {
			if (this->no_stored_value) {
				std::cout << "--\n";
				return true;
			} else {
				std::cout << "[" << this->stored_a << ", " << this->stored_b
						<< "]\n";
				return false;
			}
		} else {
			if (this->no_value) {
				std::cout << "--\n";
				return true;
			} else {
				std::cout << "[" << a << ", " << b << "]\n";
				return false;
			}

		}

	}

	void invert() {
		if (this->no_value) {
			print_value(false);
		} else {
			if ((a < 0 && b < 0) || (a > 0 && b > 0)) {
				double tempA = 1 / this->b;
				double tempB = 1 / this->a;
				this->a = tempA;
				this->b = tempB;
			} else {
				std::cout << "Error: division by zero\n";
				this->no_value = true;
			}
			print_value(false);

		}
	}
//---------------------------------------m calculation----------------------------
	void ms() {
		this->stored_a = this->a;
		this->stored_b = this->b;
		this->no_stored_value = this->no_value;
		print_value(true);
	}

	void mr() {
		if (this->no_value || this->no_stored_value) {
			print_value(false);
		} else {
			this->a = this->stored_a;
			this->b = this->stored_b;
			print_value(false);

		}
	}

	void mc() {
		this->no_stored_value = true;
		print_value(false);
	}

	void m_plus() {
		if (this->no_stored_value) {
			print_value(true);
		} else {
			this->stored_a += this->a;
			this->stored_b += this->b;
		}
	}

	void m_minus() {
		if (this->no_stored_value) {
			print_value(true);
		} else {
			this->stored_a -= this->a;
			this->stored_b -= this->b;
		}
	}

//---------------------------------------scalar calculation----------------------------
	void scalar_add() {
		double temp = 0;
		std::cin >> temp;

		if (this->no_value) {

		} else {

		}
		this->a += temp;
		this->b += temp;
		print_value(false);
	}

	void scalar_subtract() {
		double temp = 0;
		std::cin >> temp;
		this->a -= temp;
		this->b -= temp;
		print_value(false);
	}

	void scalar_multiply() {
		double temp = 0;
		std::cin >> temp;
		this->a *= temp;
		this->b *= temp;
		print_value(false);
	}

	void scalar_divide() {
		double temp = 0;
		std::cin >> temp;

		if (temp == 0) {
			this->no_value = true;
			std::cout << "Error: division by zero\n";

		} else {
			this->a /= temp;
			this->b /= temp;
		}

		print_value(false);
	}

	void scalar_divided_by() {
		double c = 0;
		std::cin >> c;

		if (this->a <= 0 && this->b >= 0) {
			this->no_value = true;
			std::cout << "Error: division by zero\n";
		}

		if (c > 0) {
			double tempA = c / this->b;
			double tempB = c / this->a;

			this->a = tempA;
			this->b = tempB;
		} else {
			double tempA = c / this->a;
			double tempB = c / this->b;

			this->a = tempA;
			this->b = tempB;
		}

		print_value(false);
	}

//---------------------------------------interval calculation----------------------------
	void interval_add() {

		double tempA;
		double tempB;
		std::cin >> tempA;
		std::cin >> tempB;

		if (tempA > tempB) {
			std::cout << "Error: invalid interval as " << tempA << " > "
					<< tempB << "\n";
		} else {
			this->a += tempA;
			this->b += tempB;
		}
		this->print_value(false);
	}

	void interval_subtract() {

		double tempA;
		double tempB;
		std::cin >> tempA;
		std::cin >> tempB;

		if (tempA > tempB) {
			std::cout << "Error: invalid interval as " << tempA << " > "
					<< tempB << "\n";
		} else {
			this->a -= tempA;
			this->b -= tempB;
		}
		this->print_value(false);
	}

	void interval_multiply() {

		double c;
		double d;
		std::cin >> c;
		std::cin >> d;

		if (c > d) {
			std::cout << "Error: invalid interval as " << c << " > " << d
					<< "\n";
		} else {

			double tempA = this->minimum_value(a * c, a * d, b * c, b * d);
			double tempB = this->maximum_value(a * c, a * d, b * c, b * d);

			this->a = tempA;
			this->b = tempB;

		}
		this->print_value(false);
	}

	void interval_divide() {

		double c;
		double d;
		std::cin >> c;
		std::cin >> d;

		if (c > d) {
			std::cout << "Error: invalid interval as " << c << " > " << d
					<< "\n";
		} else if (c <= 0 && d >= 0) {
			this->no_value = true;
			std::cout << "Error: division by zero\n";

		} else {
			double tempA = this->minimum_value(a / c, a / d, b / c, b / d);
			double tempB = this->maximum_value(a / c, a / d, b / c, b / d);

			this->a = tempA;
			this->b = tempB;

		}
		this->print_value(false);
	}

	double minimum_value(double a, double b, double c, double d) {

		double minimum = a;
		if (minimum > b) {
			minimum = b;
		}

		if (minimum > c) {
			minimum = c;
		}

		if (minimum > d) {
			minimum = d;
		}

		return minimum;
	}

	double maximum_value(double a, double b, double c, double d) {

		double maximum = a;
		if (maximum < b) {
			maximum = b;
		}

		if (maximum < c) {
			maximum = c;
		}

		if (maximum < d) {
			maximum = d;
		}

		return maximum;
	}

//--------------------------intersect---------------------------
	void intersect() {

		double c;
		double d;
		std::cin >> c;
		std::cin >> d;

		if (c > d) {
			std::cout << "Error: invalid interval as " << c << " > " << d
					<< "\n";
		} else if (c > b || d < a) {
			this->no_value = true;

		} else {

			if (c > this->a) {
				this->a = c;
			}

			if (d < this->b) {
				this->b = d;
			}

		}
		this->print_value(false);

	}

	void integers() {

		if (this->no_value) {

		} else {

			for (int i = this->a - 1; i <= this->b; i++) {
				if (i <= this->b && i >= this->a) {
					if (Fuking_ABS(i - b) < 1) {
						std::cout << i << "\n";

					} else {
						std::cout << i << ", ";

					}
				}
			}

		}

		this->print_value(false);

	}

	void cartesian_integers() {
		double c = 0;
		double d = 0;
		std::cin >> c;
		std::cin >> d;

		if (c > d) {
			std::cout << "Error: invalid interval as " << c << " > " << d
					<< "\n";
		} else {
			if (this->no_value) {

			} else {

				for (int i = a - 1; i < b + 1; i++) {
					for (int j = c - 1; j < d + 1; j++) {

						if (i >= a && i <= b && j >= c && j <= d) {

							if (Fuking_ABS(i - b) < 1
									&& Fuking_ABS(j - d) < 1) {
								std::cout << "(" << i << "," << j << ")\n";

							} else {
								std::cout << "(" << i << "," << j << "), ";

							}
						}

					}
				}

			}

		}

		print_value(false);

	}





	double Fuking_ABS(double x) {
		if (x >= 0) {
			return x;
		} else {
			return -x;
		}
	}

};

int main() {

	Intervals interval;
	std::string input;

	for (;;) {

		std::cout << "input :> ";
		std::cin >> input;

		if (input == "exit") {
			std::cout << "Bye bye: Terminating interval calculator program.\n";
			return 0;
		} else if (input == "enter") {
			interval.enter();
		} else if (input == "negate") {
			interval.negate();
		} else if (input == "invert") {
			interval.invert();
		} else if (input == "ms") {
			interval.ms();
		} else if (input == "mr") {
			interval.mr();
		} else if (input == "mc") {
			interval.mc();
		} else if (input == "m+") {
			interval.m_plus();
		} else if (input == "m-") {
			interval.m_minus();
		} else if (input == "scalar_add") {
			interval.scalar_add();
		} else if (input == "scalar_subtract") {
			interval.scalar_subtract();
		} else if (input == "scalar_multiply") {
			interval.scalar_multiply();
		} else if (input == "scalar_divide") {
			interval.scalar_divide();
		} else if (input == "scalar_divided_by") {
			interval.scalar_divided_by();
		} else if (input == "interval_add") {
			interval.interval_add();
		} else if (input == "interval_subtract") {
			interval.interval_subtract();
		} else if (input == "interval_multiply") {
			interval.interval_multiply();
		} else if (input == "interval_divide") {
			interval.interval_divide();
		} else if (input == "intersect") {
			interval.intersect();
		} else if (input == "integers") {
			interval.integers();
		} else if (input == "cartesian_integers") {
			interval.cartesian_integers();
		} else {
			std::cout << "Error: illegal command\n";
		}
	}

	std::cout << input;

	return 0;
}

