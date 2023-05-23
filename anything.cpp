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

class stu {
    int stuno = 0;
    string stuname;
    int test1 = 0;
    int test2 = 0;
public:
    void setstuno(int k);

    void setstuname(string s);

    void settest1(int k);

    void settest2(int k);

    int getstuno();

    int gettest1();

    int gettest2();

    string getstuname();

    void f(stu s[]);
};

void stu::f(stu s[]) {
    int l;
    cin >> l;
    for (int t = 0; t < 10; ++t) {
        if ((s[t].gettest1() + s[t].gettest2()) / 2)
            cout << s[t].getstuname();
    }
}

void stu::setstuno(int k) {
    stuno = k;
}

void stu::settest1(int k) {
    test1 = k;
}

void stu::settest2(int k) {
    test2 = k;
}

void stu::setstuname(string s) {
    stuname = s;
}

int stu::getstuno() {
    return stuno;
}

string stu::getstuname() {
    return stuname;
}

int stu::gettest1() {
    return test1;
}

int stu::gettest2() {
    return test2;
}

void pr(stu s[], int t) {
    for (int t1 = 0; t1 < t; ++t1) {
        cout << s[t1].getstuname() << " ";
    }
    cout << "\n";
}

int main() {

    stu v[10];
    int s = 0;
    int cnt = 0;
    while (cout << "select 1 2 3 (-1 for stop) \n" && cin >> s) {
        if (s == -1)break;
        switch (s) {
            case 1:
                pr(v, cnt);
                break;
            case 2:
                int sen;
                for (int t = cnt; t < 10; ++t) {
                    int t1 = 0;
                    int t2 = 0;
                    int t3 = 0;
                    string ssss;

                    cin >> t1;
                    cin >> ssss;
                    cin >> t2;
                    cin >> t3;

                    v[t].setstuno(t1);
                    v[t].setstuname(ssss);
                    v[t].settest1(t2);
                    v[t].settest2(t3);

                    cnt++;
                    cout << "continue?(if not input -1)\n";
                    cin >> sen;
                    if (sen == -1)
                        break;
                }
                break;
            case 3:
                int v1;
                cin >> v1;
                for (int t = 0; t < cnt; ++t) {
                    if (v1 == v[t].getstuno())
                        cout << v[t].getstuname();
                }
                cout << "\n";
                break;

        }
    }
}





