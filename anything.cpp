//#include <bits/stdc++.h>
//
//using namespace std;
//using ll = long long;

//ll fastpow(ll a, ll b, ll mod) {
//    if (b == 0) {
//        return 1;
//    }
//
//    ll sub = fastpow(a, b / 2, mod);
//    ll result = sub * sub % mod;
//
//    if (b % 2 == 1) {
//        result = result * a % mod;
//    }
//
//    return result;
//
//
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    int a, b, c;
//    cin >> a >> b >> c;
//    cout << fastpow(a, b, c) << "\n";
//
//
//    return 0;
//}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//class max_heap {
//public:
//    int size() {
//        return cnt;
//    }
//
//    void push(int a) {
//        heap[cnt++] = a;
//        int child = cnt;
//        int parent = cnt / 2;
//        while (heap[child] > heap[parent] && child > 1) {
//            swap(heap[child], heap[parent]);
//            child = parent;
//            parent = child / 2;
//        }
//    }
//
//    int pop() {
//        int result = heap[1];
//        swap(heap[1], heap[cnt]);
//        cnt--;
//        int parent = 1;
//        int child = parent * 2;
//
//
//
//        return result;
//    }
//
//
//private:
//    int heap[100001];
//    int cnt = 1;
//
//
//};
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    priority_queue<int> pq;
//    int t;
//    cin >> t;
//    while (t--) {
//        int num;
//        cin >> num;
//        for (int i = 0; i < num; ++i) {
//            int a;
//            cin >> a;
//            pq.push(a);
//        }
//        for (int i = 0; i < num; ++i) {
//            cout << pq.top() << "\n";
//            pq.pop();
//
//        }
//
//
//    }
//
//
//}

//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//int main() {
//    while (true) {
//        string s;
//        int sign = 0; // pop에서 걸러진 경우
//        getline(cin, s);
//        if (s == "\n") {
//            continue;
//        }
//        if (s == ".") {
//            break;
//        }
//        stack<int> round;
//        stack<int> square;
//        int count = 0;
//
//        round.push(0); // 초기화 작업
//        square.push(0);
//
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] == '(') {
//                count++;
//                round.push(count);
//            }
//            else if (s[i] == ')') {
//                if (round.size() == 1 || round.top() != count) {
//                    cout << "no\n";
//                    sign = 1;
//                    break;
//                }
//                round.pop();
//                count--;
//            }
//            else if (s[i] == '[') {
//                count++;
//                square.push(count);
//
//            }
//            else if (s[i] == ']') {
//                if (square.size() == 1 || square.top() != count) {
//                    cout << "no\n";
//                    sign = 1;
//                    break;
//                }
//                square.pop();
//                count--;
//            }
//        }
//        if (sign == 1) {
//            continue;
//        }
//        if (square.size() == 1 && round.size() == 1) {
//            cout << "yes\n";
//        }
//        else if ((square.size() == 1 && round.size() >= 1) || (square.size() >= 1 && round.size() == 1)){
//            cout << "no\n";
//        }
//    }
//}
#include <bits/stdc++.h>

using namespace std;
bool dp[2501][2501];
vector<int> num(2001);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        dp[i][i] = true;
        if (i != 0 && s[i - 1] == s[i]) dp[i - 1][i] = true;
    }

    for (int i = 2; i < s.size() - 1; ++i) {
        for (int j = 0; i + j < s.size(); ++j) {
            if (dp[j + 1][i + j - 1] && s[j] == s[i + j]) dp[j][i + j] = true;
        }
    }

    int b = 0, e = s.size() - 1, cnt = 0;

    while (b < s.size()) {
        if (dp[b][e]) {
            cnt++;
            b = e + 1;
            e = s.size()-1;
        }
        e--;
    }


    cout << cnt << "\n";
    return 0;
}
