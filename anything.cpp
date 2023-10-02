#include <iostream>
#include <sstream>
#include <array>
using namespace std;


class Equation {
    friend bool operator==(const Equation& lhs, const Equation& rhs);
    friend ostream& operator<<(ostream& out, const Equation& eq);
public:
    Equation(double coefficients[], int number);
    Equation(const Equation& rhs);             // copy constructor
    ~Equation();
    int degree() const { return size - 1; }

    Equation& operator= (const Equation& rhs);
    Equation& operator+= (const Equation& rhs);
    Equation& operator-= (const Equation& rhs);
    Equation& operator*= (double rhs);
private:
    int size;       // size of the coeff array (= degree + 1)
    double* coeff;  // coeff is an array
};
Equation operator+(const Equation& lhs, const Equation& rhs);
Equation operator-(const Equation& lhs, const Equation& rhs);
Equation operator*(const Equation& lhs, double rhs);
Equation operator*(double lhs, const Equation& rhs);

int main() {
    int eq1Num, eq2Num;
    cout << "Number of terms in equation eq1: ";
    cin >> eq1Num;
    double coeff1[999]{};
    cout << "Coefficients from the highest terms: ";
    for (int i = 0; i < eq1Num; i++) {
        int num;
        cin >> num;
        coeff1[i] = num;
    }
    Equation eq1(coeff1, eq1Num);

    cout << "Number of terms in equation eq2: ";
    cin >> eq2Num;
    double coeff2[999]{};
    cout << "Coefficients from the highest terms: ";
    for (int i = 0; i < eq2Num; i++) {
        int num;
        cin >> num;
        coeff2[i] = num;
    }
    Equation eq2(coeff2, eq2Num);

    cout << "eq1: " << eq1 << endl;
    cout << "eq2: " << eq2 << endl;

    Equation C = eq1 + eq2;
    cout << "eq1+eq2: " << C << endl;
    if (eq1 == eq2)
        cout << "eq1 and eq2 are equal" << endl;
    else {
        cout << "eq1 and eq2 are not equal" << endl;
        Equation D = eq1 - eq2;
        cout << "eq1-eq2: " << D << endl;
    }
    Equation eq3(eq1);
    cout << "eq3 after eq3(eq1): " << eq3 << endl;
    eq3 += eq2;
    cout << "eq3 after eq3+=eq2: " << eq3 << endl;
    Equation eq4 = eq3 * 0.5;
    cout << "eq3*0.5: " << eq4 << endl;
    Equation eq5 = 4 * eq3;
    cout << "4*eq3: " << eq5 << endl;
}


bool operator==(const Equation& lhs, const Equation& rhs) {
    if (lhs.size != rhs.size) {
        return false;
    }
    else {
        for (int i = 0; i < lhs.size; i++) {
            if (lhs.coeff[i] != rhs.coeff[i]) {
                return false;
            }
        }
    }
    return true;
}

ostream& operator<<(ostream& out, const Equation& eq) {
    out << eq.coeff[0] << "x^" << eq.size - 1;
    for (size_t i{ 1 }; i < eq.size - 1; ++i) {
        if (eq.coeff[i] > 0) {
            out << "+" << eq.coeff[i] << "x^" << eq.size - i - 1;
        }
        else if (eq.coeff[i] < 0) {
            out << eq.coeff[i] << "x^" << eq.size - i - 1;
        }
    }
    if (eq.coeff[eq.size - 1] > 0) {
        out << "+" << eq.coeff[eq.size - 1] << "=0";
    }
    else if(eq.coeff[eq.size - 1] < 0){
        out << eq.coeff[eq.size - 1] << "=0";
    }
    else {
        out << "=0";
    }
    return out;
}

Equation::Equation(double coefficients[], int number) :
        size{number >= 2 ? number: throw invalid_argument{"Array size must be greater than 0"} },
        coeff{new double[size]{}}{
    for (int i = 0; i < size; i++) {
        coeff[i] = coefficients[i];
    }
}

Equation::Equation(const Equation& rhs) :
        size{rhs.size}, coeff{ new double[size] }
{
    for (int i = 0; i < size; i++) {
        coeff[i] = rhs.coeff[i];
    }
}

Equation::~Equation() {
    delete[] coeff;
}

Equation& Equation::operator= (const Equation& rhs) {
    size = rhs.size;
    coeff =  new double[size];
    for (int i = 0; i < size; i++) {
        coeff[i] = rhs.coeff[i];
    }

    return *this;
}

Equation& Equation::operator+= (const Equation& rhs) {
    int maxSize = this->size;
    double coefficients[999]{};

    if (rhs.size > maxSize) {
        maxSize = rhs.size;
    }

    int sub = rhs.size - this->size;
    if (sub >= 0) {
        for (int i = 0; i < sub; i++) {
            coefficients[i] = rhs.coeff[i];
        }
        for (int i = 0; i < this->size; i++) {
            coefficients[i + sub] = rhs.coeff[i + sub] + this->coeff[i];
        }
    }

    else if (sub < 0) {
        sub = -sub;
        for (int i = 0; i < sub; i++) {
            coefficients[i] = this->coeff[i];
        }
        for (int i = 0; i < rhs.size; i++) {
            coefficients[i + sub] = this->coeff[i + sub] + rhs.coeff[i];
        }
    }

    Equation C2(coefficients, maxSize);
    *this = C2;
    return *this;
}

Equation& Equation::operator-= (const Equation& rhs) {
    int maxSize = this->size;
    double coefficients[999]{};

    if (rhs.size > maxSize) {
        maxSize = rhs.size;
    }

    int sub = rhs.size - this->size;
    if (sub >= 0) {
        for (int i = 0; i < sub; i++) {
            coefficients[i] = -1 * rhs.coeff[i];
        }
        for (int i = 0; i < this->size; i++) {
            coefficients[i + sub] = this->coeff[i] - rhs.coeff[i + sub];
        }
    }

    else if (sub < 0) {
        sub = -sub;
        for (int i = 0; i < sub; i++) {
            coefficients[i] = this->coeff[i];
        }
        for (int i = 0; i < rhs.size; i++) {
            coefficients[i + sub] = this->coeff[i + sub] - rhs.coeff[i];
        }
    }

    Equation C2(coefficients, maxSize);
    *this = C2;
    return *this;
}

Equation& Equation::operator*= (double rhs) {
    double coefficients[999]{};
    for (int i = 0; i < this->size; i++) {
        coefficients[i] = this->coeff[i] * rhs;
    }
    Equation C2(coefficients, this->size);
    *this = C2;
    return *this;
}

Equation operator+(const Equation& lhs, const Equation& rhs) {
    Equation lhs2 = lhs;
    Equation rhs2 = rhs;
    lhs2 += rhs2;
    return lhs2;
}

Equation operator-(const Equation& lhs, const Equation& rhs) {
    Equation lhs2 = lhs;
    Equation rhs2 = rhs;
    lhs2 -= rhs2;
    return lhs2;
}

Equation operator*(const Equation& lhs, double rhs) {
    Equation lhs2 = lhs;
    lhs2 *= rhs;
    return lhs2;
}

Equation operator*(double lhs, const Equation& rhs) {
    Equation rhs2 = rhs;
    rhs2 *= lhs;
    return rhs2;
}