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
//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//void swap(int *const p1, int *const p2);
//
//void selectionSort(int A[], const int size, int order);
//
//int main() {
//    int a[10], c;
//    for (void (*i){new int{0}}, (*p)(int[], const int, int){selectionSort};
//         *(int *) i < 30; ((*(int *) i) == 0 ? cout << "Enter 10 integers in [-99, 99] to sort: " : cout
//            << ""), (((*(int *) i) < 10) ? cin >> a[*(int *) i] : cin), ((*(int *) i) == 9 ? cout
//            << "Choose sorting order (1: ascending order, 2: descending order): " : cout << ""), ((*(int *) i) == 9 ?
//                                                                                                  cin >> c
//                                                                                                                    : cin), (*(int *) i) += 1, (
//            (*(int *) i) != 20 ? (*p)(a, 1, 1) : (*p)(a, 10, c)))
//        (*(int *) i) < 10 ? cout : cout << ((*(int *) i) != 10 ? "" : "Initial array:")
//                                        << ((*(int *) i) != 20 ? "" : c == 1 ? "Sorted in ascending order:"
//                                                                             : "Sorted in descending order:") << setw(4)
//                                        << a[(*(int *) i) % 10] << (((*(int *) i) % 10) != 9 ? "" : "\n");
//
//    return 0;
//}
//
//void selectionSort(int A[], const int size, int order) {
//    for (int i{size - 1}, m{0}, j{0}; m = A[m] > A[size - i + j] ^ (order >> 1) ? size - i + j : m, i > 0; i -= ++j /
//                                                                                                                i, j %= i +
//                                                                                                                        1)
//        if (j + 1 == i)
//            for (void (*k){new int{0}}, (*s)(int *, int *){swap};
//                 *(int *) k == 0 ? (*s)(&A[(m = size - i) - 1], &A[m]) : (*s)(&A[m], &A[m]), *(int *) k <
//                                                                                             10; (*(int *) k)++)
//                *(int *) k != 0 ? (cout << setw(4) << A[*(int *) k] << (*(int *) k != 9 ? "" : "\n")) : (cout
//                        << "after " << size - i - 1 << "-th iteration:" << setw(4) << A[*(int *) k]
//                        << (*(int *) k != 9 ? "" : "\n"));
//}
//
//void swap(int *const p1, int *const p2) {
//    int t{*p1}, c{(*p2 = t ^ (*p1 = *p2) ^ (*p1))};
//}


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        vi v(2 * a);
        set<int> s;
        vi check(400001);
        for (int i = 0; i < 2 * a; ++i) {
            cin >> v[i];
            s.insert(v[i]);
        }
        int max = 0;
        for (int i: s) {
            int c = count(v.begin(), v.end(), i);
            if (max < c) max = c;
        }

        cout << max << "\n";

    }
    return 0;
}

