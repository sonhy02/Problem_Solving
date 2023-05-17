#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;


void swap(string *a, string *b) {
    string temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 string a, b;
 cin >> a >> b;
 cout << a << b;
 cout << "\n";
    swap(&a , &b);
    cout << a << b;

    return 0;
}
