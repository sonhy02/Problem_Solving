#include <bits/stdc++.h>


//int gcd(int a, int b) {
//    return (a % b == 0) ? b : gcd(b, a % b);
//}
//
//void decimal(int a) {
//    if(a == 0) return;
//    decimal(a / 2);
//    cout << a % 2;
//
//}

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

//class studentnode {
//public:
//    string name;
//    int id;
//    string major;
//    studentnode *next;
//};
//
//
//class List {
//private:
//    studentnode *head = NULL;
//    studentnode *tail = NULL;
//    studentnode s[1024];
//    int cnt = 0;
//public:
//    void push_front(string name, int id, string major) {
//        if (head == NULL) {
//            head = s;
//            tail = s;
//            head->name = name;
//            head->id = id;
//            head->major = major;
//            head->next = NULL;
//            cnt++;
//        } else {
//            studentnode *temp = head;
//            head = &s[cnt];
//            head->next = temp;
//            head->name = name;
//            head->id = id;
//            head->major = major;
//            cnt++;
//        }
//    }
//
//    void printall() {
//        studentnode *temp = head;
//        while (temp != NULL) {
//            cout << temp->name << " " << temp->id << " " << temp->major << "\n";
//            temp = temp->next;
//        }
//    }
//
//};

vector<bool> prime(100000000);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    for (int x = 2; x <= 25000000; x++) {
        if (prime[x]) continue;
        for (int y = x * 2; y <= 50000000; y += x) {
            prime[y] = true;
        }
    }

    int a;
    while (cin >> a) {
        if (a < 8) {
            cout << "Impossible.\n";
            continue;
        } else if (a % 2) {
            cout << "2 3 ";
            a -= 5;
        } else {
            cout << "2 2 ";
            a -= 4;
        }

        for (int i = 3; i <= a / 2; ++i) {
            if (!prime[i] && !prime[a - i]) {
                cout << i << " " << a - i << "\n";
                break;
            }
        }
    }


    return 0;
}
