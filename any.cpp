#include<iostream>
#include<queue>

using namespace std;
int num[50002]{0};
int rs[50002]{0};
int k = 1;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int m, n;
    cin >> m >> n;
    if (m == 1 && n == 1) {
        cout << "<1>";
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        num[i] = i;
        q.push(num[i]);
    }
    while (!q.empty()) {
        for (int H = 0; H < n - 1; H++) {
            q.push(q.front());
            q.pop();
        }
        rs[k] = q.front();
        k++;
        q.pop();
    }
    cout << "<" << rs[1] << ", ";
    for (int j = 2; j < m; j++) {
        cout << rs[j] << ", ";
    }
    cout << rs[m] << ">";

    return 0;
}
