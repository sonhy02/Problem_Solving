// Fig. 13.14: Fig13_14.cpp
#include <iostream>
#include <iomanip>

using namespace std;

class arithmetic {
public:
    arithmetic(int n1, int n2) {
        x = n1, y = n2;
    };

    void print() {
        cout << setw(9)<< x << "\t" << setw(9)<< x << "\t" << setw(9)<< x << "\n";
        cout << "+" << setw(8) << y << "\t" << "-"<< setw(8) << y << "\t" << "*" << setw(8)<< y << "\n";
        cout << setw(10)<< "----------\t" << setw(10)<< "----------\t" << setw(10)<< "----------\t"  << "\n";
        cout << setw(9) << x+y  << "\t"<< setw(9) << x-y << "\t" << setw(9)<< x*y << "\n\n\n";


    }

private:
    int x;
    int y;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int a, b;
    while (cin >> a >> b) {
        arithmetic v(a, b);
        v.print();
    }

}
