#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

vector<pair<string, int>> block;
set<int> chain;
bool check[100001];
bool flag = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        string s1, s2;
        int t;
        cin >> s1 >> s2 >> t;
        if (i = m - 1 && s1 == "A" && t == 2 * n) flag = false;
        if (t == 1) flag = true;
        block.push_back({s1, t});
        check[t] = true;
    }
    if (!flag) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i < 2 * n; ++i) {
        if (!check[i])
            chain.insert(i);
    }
    if (block[m - 1].first == "A") {
        chain.erase(2 * n);
    }

    cout << block[0].first << " BLOCK " << block[0].second << "\n";
    for (int i = 1; i < m - 1; ++i) {
        if (block[i].second == 1) {
            int s = chain.size();











        } else {
            if (block[i].first == block[i + 1].first) {
                cout << block[i].first << " BLOCK " << block[i].second << "\n";
                int temp = block[i].second;
                while (1) {
                    temp++;
                    if (chain.find(temp) != chain.end() || temp > 2 * n) {
                        chain.erase(temp);
                        break;
                    }
                }
                string prt;
                if (block[i].first == "A") prt = "B";
                else prt = "A";
                cout << prt << " CHAIN " << temp << "\n";


            } else {
                cout << block[i].first << " BLOCK " << block[i].second << "\n";
                int temp = block[i].second;
                while (1) {
                    temp++;
                    if (chain.find(temp) != chain.end() || temp > 2 * n) {
                        chain.erase(temp);
                        break;
                    }
                }
                string prt;
                if (block[i].first == "A") prt = "B";
                else prt = "A";
                cout << prt << " CHAIN " << temp << "\n";
                while (1) {
                    temp++;
                    if (chain.find(temp) != chain.end() || temp > 2 * n) {
                        chain.erase(temp);
                        break;
                    }
                }
                if (block[i].first == "A") prt = "B";
                else prt = "A";
                cout << prt << " CHAIN " << temp << "\n";
            }

        }


    }


    return 0;
}
