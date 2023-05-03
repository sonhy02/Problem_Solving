#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        cout << binary_search(a.begin(), a.end(), temp) << '\n';
    }
}