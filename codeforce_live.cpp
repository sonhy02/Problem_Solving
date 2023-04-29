#include <bits/stdc++.h>

using namespace std;

int cal(int a){
    if(a<1) return 0;
    else return a*(a-1)/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
int f;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        f = 0;
        if(n == 2 && k == 0){
            cout << "YES\n";
            cout << "1 -1 \n";
            continue;
        }
        for (int i = 2; i <=n ; ++i) {
            if(k == cal(i)+ cal(n-i)){
                cout << "YES\n";
                f =1;
                for (int j = 1; j <=i ; ++j) {
                    cout << "1 ";
                }
                for (int j = i+1; j <=n ; ++j) {
                    cout <<"-1 ";
                }
                cout << "\n";
                break;
            }
        }
        if(f==0) cout << "NO\n";
    }

    return 0;
}