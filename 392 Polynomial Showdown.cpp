#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string format_polynomial(const vector<int>& coeffs) {
    string result;
    bool first_term = true;

    for (int i = 0; i < 9; ++i) {
        int coef = coeffs[i];
        int degree = 8 - i;

        if (coef == 0) continue;

        string term;
        string sign;

        if (first_term) {
            if (coef < 0) sign = "-";
        } else {
            sign = (coef < 0) ? " - " : " + ";
        }

        int abs_coef = abs(coef);
        if (degree == 0) {
            term = to_string(abs_coef);
        } else if (degree == 1) {
            term = (abs_coef == 1 ? "x" : to_string(abs_coef) + "x");
        } else {
            term = (abs_coef == 1 ? "x^" + to_string(degree) : to_string(abs_coef) + "x^" + to_string(degree));
        }

        result += sign + term;
        first_term = false;
    }

    if (result.empty()) return "0";
    return result;
}

int main() {
    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> coeffs(9);
        for (int i = 0; i < 9; ++i) {
            iss >> coeffs[i];
        }

        cout << format_polynomial(coeffs) << endl;
    }

    return 0;
}
