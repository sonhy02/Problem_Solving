#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        int n = str.length();
        set<string> unique_strings;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string new_str = str;
                new_str.erase(i, 1);
                new_str.erase(j - 1, 1);

                unique_strings.insert(new_str);
            }
        }

        cout << unique_strings.size() << "\n";
    }

    return 0;
}