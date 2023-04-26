#include<iostream>
#include<string>

using namespace std;

int main() {
    int a;
    cin >> a;
    for (int i = 0;i < a;i++) {
        int b;
        string c;
        cin >> b >> c;
        for (int p = 0; p < c.size(); p++) {
            for (int q = 0;q < b;q++) {
                cout << c[p];
            }
        }
    }
}