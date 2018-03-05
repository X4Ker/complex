#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct complex_t {

private:

    float real;
    float imag;
public:

    complex_t() {
        real = 0.0f;
        imag = 0.0f;
    }
    
    complex_t add( complex_t other ) const {

        complex_t result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }

    complex_t sub( complex_t other ) const {

        complex_t result;
        result.real = this->real - other.real;
        result.imag = this->imag - other.imag;
        return result;
    }
    complex_t mul( complex_t other ) const {

        complex_t result;
        result.real = (this->real * other.real - this->imag*other.imag);
        result.imag = (this->imag *other.real + this->real * other.imag);
        return result;
    }
    complex_t div( complex_t other ) const {

        complex_t result;
        float del = (other.real*other.real + other.imag*other.imag);
        if (del != 0) {
            result.real = ((this->real*other.real + this->imag*other.imag) / (other.real*other.real + other.imag*other.imag));
            result.imag = ((this->imag*other.real - this->real*other.imag) / (other.real*other.real + other.imag*other.imag));
        }
        else {
            cout << "error";
            exit(0);
        }
        return result;
    }

    std::istream & read( std::istream & stream );
    std::ostream & write( std::ostream & stream );
};

std::ostream & complex_t::write(ostream & stream) {
    return  stream << '(' << real << ", " << imag << ')';
}

std::istream & complex_t::read(istream & stream) {
    char op;
    if (stream >> op && op == '(' &&
        stream >> this->real &&
        stream >> op && op == ',' &&
        stream >> this->imag &&
        stream >> op && op == ')')
    {
        return stream;
    }
    else {
        cout << "An error has occured while reading input data";
        cin.get();
        exit(0);
    }
}

int main() {
    complex_t a;
    complex_t b;
    complex_t res;
    string s;
    char op;
    getline(cin, s);
    istringstream stream(s);
    if (a.read(stream) && stream >> op && b.read(stream)) {
    stream >> op;

        switch (op) {
            case '+':
                res = a.add(b);
                res.write(cout);
                break;
            case '-':
                res = a.sub(b);
                res.write(cout);
                break;
            case '*':
                res = a.mul(b);
                res.write(cout);
                break;
            case '/':
                res = a.div(b);
                res.write(cout);
                break;
        }
    }

    cin.get();
    return 0;
}
