#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using ll = long long;
using namespace std;
int p[100001];
int m = 0;
int mi = 0x3f3f3f3f;
int r;
int l;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;
    while (t--) {

        int a, b;
        cin >> a >> b;
        for (int i = 0; i < a; ++i) {
            cin >> p[i];
            if(p[i] == -1) l++;
            else if(p[i] == -2) r++;
            if (m < p[i]) m = p[i];
            if (p[i] > 0 && mi > p[i]) mi = p[i];
        }




    }
    return 0;
}