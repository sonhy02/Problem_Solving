#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main()
{
    int v1 = 20;
    int v2 = 12;
    cout << "Please input two nums: ";
    cin >> v1 >> v2;
    cout << "GCD of " << v1 << " and " << v2 << " is: ";
    gcd(v1, v2);
    return 0;
}