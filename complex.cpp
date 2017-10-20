#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct complex_t {
	float real;
	float imag;
};

complex_t add(complex_t lhs, complex_t rhs) {
	complex_t res;
	res.real = lhs.real + rhs.real;
	res.imag = lhs.imag + rhs.imag;
	return res;
}

complex_t sub(complex_t lhs, complex_t rhs) {
	complex_t res;
	res.real = lhs.real - rhs.real;
	res.imag = lhs.imag - rhs.imag;
	return res;
}

complex_t mul(complex_t lhs, complex_t rhs) {
	complex_t res;
	res.real = ((lhs.real * rhs.real) - (lhs.imag * rhs.imag));
	res.imag = ((lhs.imag * rhs.real) + (lhs.real * rhs.imag));
	return res;
}

complex_t div(complex_t lhs, complex_t rhs) {
	complex_t res;
	res.real = ((lhs.real * rhs.real) + (lhs.imag * rhs.imag)) / ((rhs.real * rhs.real) + (rhs.imag * rhs.imag));
	res.imag = ((lhs.imag * rhs.real) - (lhs.real * rhs.imag)) / ((rhs.real * rhs.real) + (rhs.imag * rhs.imag));
	return res;
}

bool read(istringstream & stream, complex_t & cmplx) {
	
	char symbol;
	float real, imag;
	if (stream >> symbol && symbol == '(' &&
		stream >> real &&
		stream >> symbol && symbol == ',' &&
		stream >> imag &&
		stream >> symbol && symbol == ')') {

		cmplx.real = real;
		cmplx.imag = imag;

		return true;
	}

	return false;
}

void write(complex_t & cmplx) {
	float real, imag;
	cout << "(" << cmplx.real << "," << " " << cmplx.imag << ")";
}

int main() {
	complex_t a, b;
	string s;
	char op;
	bool q = false;
	getline(cin, s);
	istringstream stream(s);
	q = read(stream, a);
	stream >> op;
	q = read(stream, b);
	if (q == true) {
		switch (op) {
		case '+':
			write(add(a, b));
			break;
		case '-':
			write(sub(a, b));
			break;
		case '*':
			write(mul(a, b));
			break;
		case '/':
			write(div(a, b));
			break;
		}
	}
	else {
		cout << "An error has occured while reading input data";
	}
	cin.get();
	return 0;
}
