////#include <bits/stdc++.h>
////
////using namespace std;
////using ll = long long;
//
////ll fastpow(ll a, ll b, ll mod) {
////    if (b == 0) {
////        return 1;
////    }
////
////    ll sub = fastpow(a, b / 2, mod);
////    ll result = sub * sub % mod;
////
////    if (b % 2 == 1) {
////        result = result * a % mod;
////    }
////
////    return result;
////
////
////}
////
////int main() {
////    ios_base::sync_with_stdio(false);
////    cin.tie(NULL);
////    int a, b, c;
////    cin >> a >> b >> c;
////    cout << fastpow(a, b, c) << "\n";
////
////
////    return 0;
////}
//
////#include <bits/stdc++.h>
////
////using namespace std;
////
////class max_heap {
////public:
////    int size() {
////        return cnt;
////    }
////
////    void push(int a) {
////        heap[cnt++] = a;
////        int child = cnt;
////        int parent = cnt / 2;
////        while (heap[child] > heap[parent] && child > 1) {
////            swap(heap[child], heap[parent]);
////            child = parent;
////            parent = child / 2;
////        }
////    }
////
////    int pop() {
////        int result = heap[1];
////        swap(heap[1], heap[cnt]);
////        cnt--;
////        int parent = 1;
////        int child = parent * 2;
////
////
////
////        return result;
////    }
////
////
////private:
////    int heap[100001];
////    int cnt = 1;
////
////
////};
////
////
////int main() {
////    ios::sync_with_stdio(false);
////    cin.tie(NULL);
////    priority_queue<int> pq;
////    int t;
////    cin >> t;
////    while (t--) {
////        int num;
////        cin >> num;
////        for (int i = 0; i < num; ++i) {
////            int a;
////            cin >> a;
////            pq.push(a);
////        }
////        for (int i = 0; i < num; ++i) {
////            cout << pq.top() << "\n";
////            pq.pop();
////
////        }
////
////
////    }
////
////
////}
//
////#include <iostream>
////#include <string>
////#include <stack>
////using namespace std;
////
////int main() {
////    while (true) {
////        string s;
////        int sign = 0; // pop에서 걸러진 경우
////        getline(cin, s);
////        if (s == "\n") {
////            continue;
////        }
////        if (s == ".") {
////            break;
////        }
////        stack<int> round;
////        stack<int> square;
////        int count = 0;
////
////        round.push(0); // 초기화 작업
////        square.push(0);
////
////        for (int i = 0; i < s.length(); i++) {
////            if (s[i] == '(') {
////                count++;
////                round.push(count);
////            }
////            else if (s[i] == ')') {
////                if (round.size() == 1 || round.top() != count) {
////                    cout << "no\n";
////                    sign = 1;
////                    break;
////                }
////                round.pop();
////                count--;
////            }
////            else if (s[i] == '[') {
////                count++;
////                square.push(count);
////
////            }
////            else if (s[i] == ']') {
////                if (square.size() == 1 || square.top() != count) {
////                    cout << "no\n";
////                    sign = 1;
////                    break;
////                }
////                square.pop();
////                count--;
////            }
////        }
////        if (sign == 1) {
////            continue;
////        }
////        if (square.size() == 1 && round.size() == 1) {
////            cout << "yes\n";
////        }
////        else if ((square.size() == 1 && round.size() >= 1) || (square.size() >= 1 && round.size() == 1)){
////            cout << "no\n";
////        }
////    }
////}
////#include <iostream>
////#include <iomanip>
////
////using namespace std;
////
////void swap(int *const p1, int *const p2);
////
////void selectionSort(int A[], const int size, int order);
////
////int main() {
////    int a[10], c;
////    for (void (*i){new int{0}}, (*p)(int[], const int, int){selectionSort};
////         *(int *) i < 30; ((*(int *) i) == 0 ? cout << "Enter 10 integers in [-99, 99] to sort: " : cout
////            << ""), (((*(int *) i) < 10) ? cin >> a[*(int *) i] : cin), ((*(int *) i) == 9 ? cout
////            << "Choose sorting order (1: ascending order, 2: descending order): " : cout << ""), ((*(int *) i) == 9 ?
////                                                                                                  cin >> c
////                                                                                                                    : cin), (*(int *) i) += 1, (
////            (*(int *) i) != 20 ? (*p)(a, 1, 1) : (*p)(a, 10, c)))
////        (*(int *) i) < 10 ? cout : cout << ((*(int *) i) != 10 ? "" : "Initial array:")
////                                        << ((*(int *) i) != 20 ? "" : c == 1 ? "Sorted in ascending order:"
////                                                                             : "Sorted in descending order:") << setw(4)
////                                        << a[(*(int *) i) % 10] << (((*(int *) i) % 10) != 9 ? "" : "\n");
////
////    return 0;
////}
////
////void selectionSort(int A[], const int size, int order) {
////    for (int i{size - 1}, m{0}, j{0}; m = A[m] > A[size - i + j] ^ (order >> 1) ? size - i + j : m, i > 0; i -= ++j /
////                                                                                                                i, j %= i +
////                                                                                                                        1)
////        if (j + 1 == i)
////            for (void (*k){new int{0}}, (*s)(int *, int *){swap};
////                 *(int *) k == 0 ? (*s)(&A[(m = size - i) - 1], &A[m]) : (*s)(&A[m], &A[m]), *(int *) k <
////                                                                                             10; (*(int *) k)++)
////                *(int *) k != 0 ? (cout << setw(4) << A[*(int *) k] << (*(int *) k != 9 ? "" : "\n")) : (cout
////                        << "after " << size - i - 1 << "-th iteration:" << setw(4) << A[*(int *) k]
////                        << (*(int *) k != 9 ? "" : "\n"));
////}
////
////void swap(int *const p1, int *const p2) {
////    int t{*p1}, c{(*p2 = t ^ (*p1 = *p2) ^ (*p1))};
////}
//
//
//#include <bits/stdc++.h>
//
//using namespace std;
//const int INF = 0x3f3f3f3f;
//using ll = long long;
//using pii = pair<int, int>;
//using pli = pair<ll, int>;
//using pll = pair<ll, ll>;
//using vi = vector<int>;
//using vll = vector<ll>;
//using vpii = vector<pii>;
//
//
//class node {
//    int x;
//    int y;
//    double dis;
//public:
//    node(int x, int y, double dis) {
//        this->x = x;
//        this->y = y;
//        this->dis = dis;
//    }
//
//    double getd() {
//        return dis;
//    }
//
//    int getx() {
//        return x;
//    }
//
//    int gety() {
//        return y;
//    }
//};
//
//bool compare(node x, node y) {
//    double dx = x.getd();
//    double dy = y.getd();
//    return x.getd() < y.getd();
//}
//
//string integer_to_Roman(int n) {
//
//    string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
//    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//
//    string result = "";
//
//    for (int i = 0; i < 13; ++i) {
//        while (n - values[i] >= 0) {
//            result += romans[i];
//            n -= values[i];
//        }
//    }
//
//    return result;
//}
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//
//
////   string s,q;       ///problem1
////   cin >> s;
////   int a[s.size()];
////    for (int i = 0; i < s.size(); ++i) {
////        a[i] = s[i];
////    }
////    sort(a,a+s.size());
////    q.push_back(a[0]);
////    for (int i = 0; i < s.size(); ++i) {
////        s[i] = a[i];
////        if(i != 0 && a[i-1] != a[i]) q.push_back(a[i]);
////    }
////    cout << s << "\n" << q;     ///problem1
//
//    vector<node> p;    // problem 2
//    int a, b;
//    int i = 0;
//    while (cout << "Enter x and y coordinates of the " << i << "-th point (EOF to end): " && cin >> a >> b) {
//        p.push_back(node(a, b, sqrt(a * a + b * b)));
//        i++;
//    }
//    sort(p.begin(), p.end(), compare);
//    cout << "\n";
//    cout << p[0].getx() << " " << p[0].gety() << "\n";
//    cout << fixed << setprecision(2) << p[0].getd() << "\n";
//    cout << p[p.size() - 1].getx() << " " << p[p.size() - 1].gety() << "\n";
//    cout << fixed << setprecision(2) << p[p.size() - 1].getd() << "\n";    // problem 2
//
////    int a; //p3
////    while (cout << "Enter n in [1, 3999}: " && cin >> a){
////        cout << integer_to_Roman(a) << "\n";
////    } //p3
//
//        return 0;
//}
//
//
////
////#include <bits/stdc++.h>
////using namespace std;
////using ll = long long;
////
////struct segtree {
////    ll n;
////    vector<ll> tree;
////    segtree(ll n) : n(n) { tree.resize(n*4); }
////
////    void update(ll t, ll x, ll i, ll l, ll r) {
////        if (l == r) {
////            tree[i] = x;
////            return;
////        }
////
////        ll m = l+r>>1;
////        if (t <= m) update(t, x, i<<1, l, m);
////        else update(t, x, i<<1|1, m+1, r);
////        tree[i] = tree[i<<1] + tree[i<<1|1];
////    }
////
////    void update(ll t, ll x) {
////        update(t, x, 1, 1, n);
////    }
////
////    ll query(ll b, ll e, ll i, ll l, ll r) {
////        if (b > r || e < l) return 0;
////        if (b <= l && r <= e) return tree[i];
////
////        ll m = l+r>>1;
////        return query(b, e, i<<1, l, m) + query(b, e, i<<1|1, m+1, r);
////    }
////
////    ll query(ll b, ll e) {
////        return query(b, e, 1, 1, n);
////    }
////};
#include<iostream>
#include<algorithm>

using namespace std;

void BinarySearch(int* arr1,int* arr2, int len1, int len2) {
    int start = 0;
    int end1 = len1 - 1;
    int mid;
    int check = 0;
    bool set = true;
    for (int i = 0;i < len2;i++) {
        int key = arr2[i];
        while (end1 - start >= 0) {
            mid = (start + end1) / 2;
            if (arr1[mid] == key) {
                cout << 1 << '\n';
                set = false;
                break;

            }
            else if (arr1[mid] > key) {
                end1 = mid - 1;

            }
            else {
                start = mid + 1;

            }
        }
        if (set == true) {
            cout << 0 << '\n';
        }
        else {
            set = true;
        }
    }
}

int d[1000000];
int b[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a;

    cin >> a;

    for (int i = 0;i < a;i++) {
        int c;
        cin >> c;
        b[i] = c;
    }

    int e;
    cin >> e;

    for (int i = 0;i < e;i++) {
        int c;
        cin >> c;
        d[i] = c;
    }

    sort(b, b + 100000);
    sort(d, d + 100000);

    BinarySearch(b, d,a, e);

}
