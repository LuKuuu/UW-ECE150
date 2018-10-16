#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING

int main();

#endif

int pascal_triangle(int n);

int pascal_triangle_recursive(int n);

int number(int row, int column);

#ifndef MARMOSET_TESTING

int main() {

//	int s = pascal_triangle(14);
//	std::cout << s << "\n";
//
//	int s1 = pascal_triangle_recursive(14);
//	std::cout << s1 << "\n";


	return 0;
}

#endif

int pascal_triangle(int n) {

	int number[n + 1][n + 1];

	for (int i = 0; i < n + 1; i++) {

		for (int j = 0; j < i + 1; j++) {

			if (j == 0 || i == j) {

				number[i][j] = 1;

			} else {

				number[i][j] = number[i - 1][j] + number[i - 1][j - 1];
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < i + 1; j++) {

			sum++;
			std::cout << number[i][j] << " ";
		}
		std::cout << "\n";
	}

	return sum;
}

int pascal_triangle_recursive(int n) {

	int sum = 0;

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			sum++;
			std::cout << number(i, j) << " ";
		}
		std::cout << "\n";
	}

	return sum;
}

int number(int row, int column) {
	if (row == column || column == 0) {
		return 1;
	} else {
		return number(row - 1, column - 1) + number(row - 1, column);
	}
}

