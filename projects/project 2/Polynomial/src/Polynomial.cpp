#include <iostream>

struct poly_t {
	double *a_coeffs;       // array of coefficients
	unsigned int degree;    // the degree of the polynomial
};

void init_poly(poly_t &p, double const init_coeffs[],
		unsigned int const init_degree);
void destroy_poly(poly_t &p);
unsigned int poly_degree(poly_t const &p);
double poly_coeff(poly_t const &p, unsigned int n);
double poly_val(poly_t const &p, double x);
void poly_add(poly_t &p, poly_t const &q);
void poly_subtract(poly_t &p, poly_t const &q);
void poly_multiply(poly_t &p, poly_t const &q);
double poly_divide(poly_t &p, double r);
void poly_diff(poly_t &p);
double poly_approx_int(poly_t const &p, double a, double b, unsigned int n);

void init_poly(poly_t &p, double const init_coeffs[],
		unsigned int const init_degree) {

	if (p.a_coeffs != nullptr) {
		destroy_poly(p);
	}

	p.a_coeffs = new double[init_degree + 1];

	for (unsigned int i = 0; i <= init_degree; i++) {
		p.a_coeffs[i] = init_coeffs[i];
	}

	p.degree = init_degree;

}

void destroy_poly(poly_t &p) {

	delete[] p.a_coeffs;
	p.a_coeffs = nullptr;
	p.degree = 0;

}

unsigned int poly_degree(poly_t const &p) {

	if (p.a_coeffs == nullptr) {
		throw 0;
	} else {
		return p.degree;

	}

}
double poly_coeff(poly_t const &p, unsigned int n) {

	if (p.a_coeffs == nullptr) {
		throw 0;
	} else if (n <= p.degree) {
		return p.a_coeffs[n];
	} else {
		return 0;
	}

}
double poly_val(poly_t const &p, double x) {

	if (p.a_coeffs == nullptr) {
		throw 0;
	}

	double sum = 0;

	for (int i = p.degree; i >= 0; i--) {
		sum = sum * x + p.a_coeffs[i];
	}

	return sum;

}

void poly_add(poly_t &p, poly_t const &q) {

	if (p.a_coeffs == nullptr || q.a_coeffs == nullptr) {
		throw 0;
	}

	unsigned int degree = 0;
	if (p.degree > q.degree) {
		degree = p.degree;
	} else {
		degree = q.degree;
	}

	double tempP[p.degree + 1];

	for (unsigned int i = 0; i <= p.degree; i++) {
		tempP[i] = p.a_coeffs[i];
	}

	delete[] p.a_coeffs;
	p.a_coeffs = new double[degree + 1];

	for (unsigned int i = 0; i <= degree; i++) {

		p.a_coeffs[i] = 0;
		if (i <= p.degree) {
			p.a_coeffs[i] += tempP[i];
		}

		if (i <= q.degree) {
			p.a_coeffs[i] += q.a_coeffs[i];
		}
	}

	p.degree = degree;

	for (;;) {
		if (p.a_coeffs[p.degree] != 0) {
			break;
		} else {

			p.degree--;

			if (p.degree == 0) {

			}

			double copy[p.degree + 1];
			for (unsigned int i = 0; i <= p.degree; i++) {
				copy[i] = p.a_coeffs[i];
			}
			delete[] p.a_coeffs;

			p.a_coeffs = new double[p.degree + 1];
			for (unsigned int i = 0; i <= p.degree; i++) {
				p.a_coeffs[i] = copy[i];
			}

		}
	}

}
void poly_subtract(poly_t &p, poly_t const &q) {

	if (p.a_coeffs == nullptr || q.a_coeffs == nullptr) {
		throw 0;
	}

	unsigned int degree = 0;
	if (p.degree > q.degree) {
		degree = p.degree;
	} else {
		degree = q.degree;
	}

	double tempP[p.degree + 1];

	for (unsigned int i = 0; i <= p.degree; i++) {
		tempP[i] = p.a_coeffs[i];
	}

	delete[] p.a_coeffs;

	p.a_coeffs = new double[degree + 1];

	for (unsigned int i = 0; i <= degree; i++) {

		p.a_coeffs[i] = 0;
		if (i <= p.degree) {
			p.a_coeffs[i] += tempP[i];
		}

		if (i <= q.degree) {
			p.a_coeffs[i] -= q.a_coeffs[i];
		}
	}

	p.degree = degree;

	for (;;) {
		if (p.a_coeffs[p.degree] != 0) {
			break;
		} else {

			p.degree--;

			if (p.degree == 0) {

			}

			double copy[p.degree + 1];
			for (unsigned int i = 0; i <= p.degree; i++) {
				copy[i] = p.a_coeffs[i];
			}
			delete[] p.a_coeffs;

			p.a_coeffs = new double[p.degree + 1];
			for (unsigned int i = 0; i <= p.degree; i++) {
				p.a_coeffs[i] = copy[i];
			}

		}
	}

}
void poly_multiply(poly_t &p, poly_t const &q) {

	if (p.a_coeffs == nullptr || q.a_coeffs == nullptr) {
		throw 0;
	}

	unsigned int degree = p.degree + q.degree;

	double temp[degree + 1];

	for (unsigned int i = 0; i <= p.degree; i++) {
		for (unsigned int j = 0; j <= q.degree; j++) {
			temp[i + j] += p.a_coeffs[i] * q.a_coeffs[j];
		}
	}

	init_poly(p, temp, degree);

}

double poly_divide(poly_t &p, double r) {

	if (p.a_coeffs == 0) {
		throw 0;
	}

	double temp[p.degree + 1];
	temp[p.degree] = p.a_coeffs[p.degree];

	for (int i = p.degree - 1; i >= 0; i--) {
		temp[i] = r * temp[i + 1] + p.a_coeffs[i];
	}

	delete[] p.a_coeffs;

	p.a_coeffs = new double[p.degree];

	for (unsigned int i = 0; i < p.degree; i++) {
		p.a_coeffs[i] = temp[i + 1];
	}

	p.degree--;

	return temp[0];

}

void poly_diff(poly_t &p) {

	if (p.a_coeffs == nullptr) {
		throw 0;

	}

	double temp[p.degree];

	for (unsigned int i = 0; i < p.degree; i++) {
		temp[i] = p.a_coeffs[i + 1] * (i + 1);
	}

	delete[] p.a_coeffs;

	p.a_coeffs = new double[p.degree];

	for (unsigned int i = 0; i < p.degree; i++) {
		p.a_coeffs[i] = temp[i];
	}

	p.degree--;
}
double poly_approx_int(poly_t const &p, double a, double b, unsigned int n) {

	if (p.a_coeffs == nullptr) {
		throw 0;

	}
	double h = (b - a) / n;
	double result = 0;
	double x = 0;
	for (unsigned int i = 0; i <= n; i++) {
		x = a + i * h;
		if (i == 0 || i == n) {
			result += poly_val(p, x);
		} else {
			result += 2 * poly_val(p, x);

		}

	}

	result *= h / 2;
	return result;

}

void printP(poly_t &p) {
	for (unsigned int i = 0; i <= p.degree; i++) {
		std::cout << i << " : " << p.a_coeffs[i] << "\n";
	}

	std::cout << "degree is " << p.degree << "\n";
}

#ifndef MARMOSET_TESTING

int main() {

	poly_t p = { nullptr, 0 };
	double co[7] = { -7107, 2, 3 ,4,5,6,7};
	init_poly(p, co, 6);



	std::cout << poly_divide(p,3) << std::endl;
	printP(p);

	return 0;
}
#endif

