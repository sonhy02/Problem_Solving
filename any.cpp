#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 4000005;
string s = "$";
int A[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string tmp; cin >> tmp;
    for (char c : tmp)
    {
        s.push_back(c);
        s.push_back('$');
    }

    int m = -1, k = -1;

    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i <= m) A[i] = min(m - i, A[2 * k - i]);

        while (0 <= i - A[i] - 1 && i + A[i] + 1 < s.size()
            && s[i - A[i] - 1] == s[i + A[i] + 1])
        {
            if (i + ++A[i] > m) m = i + A[i], k = i;
        }

        ans += (A[i] + 1) / 2;
    }

    cout << ans;
}
